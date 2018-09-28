#include "stdafx.h"
#include <unordered_map>
#include "AstFunction.h"
#include "FunctionInstance.h"
#include "AstContext.h"
#include "utility.h"
#include "AstContext.h"
#include "AstReturn.h"
#include "ClassContext.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/CastGen.h"
#include "CodeGenerate/DefGen.h"
#include "CodeGenerate/ReturnGen.h"
#include "CodeGenerate/ParamenterGen.h"
#include "CodeGenerate/ClassMemberGen.h"
#include "utility.h"
#include "../Type/LLVMType.h"
#include "../Type/TupleType.h"
#include "../Type/ClassInstanceType.h"
#include "../Type/AutoType.h"
#include "../Type/SArrayType.h"

using namespace llvm;
void AstFunction::draw(std::ostream & os) {
	dotLable(os, "function " + name, "box");

	// std::string n = nodeId;
	// block->draw(os);
	// block->dotLable(os, "function " + name);
}

CodeGen * AstFunction::makeCast(llvm::LLVMContext& c, std::vector<CodeGen*> cache, AstType * type, CodeGen * value)
{
	auto* p=new CastGen(type->llvmType(c), value);
	cache.push_back(p);
	return p;
}

AstFunction::OrderedParameters* clearGen(
	AstFunction::OrderedParameters* ordered, 
	std::vector<CodeGen*> cache
) {
	for (auto * i : cache)
		delete i;
	delete ordered;
	return nullptr;
}

AstFunction::OrderedParameters* AstFunction::orderParameters(llvm::LLVMContext& c, const std::vector<std::pair<std::string, CodeGen*>>& types) {
	auto * ordered = new OrderedParameters();
	std::vector<CodeGen*> cache;  // 这里保存生成的转换器，匹配失败退出时，清理

	auto a = paremeters.begin();
	auto i = types.begin();
	for (; i != types.end() && a != paremeters.end(); a++, i++) {	// 先顺序匹配
		const std::string& name = i->first;
		Type* type = i->second->type;	// 参数的类型

		if (!name.empty() && a->name != name)
			break;	// 如果输入有名字，并且和当前位置不匹配，退出顺序匹配模式

		bool is = AutoType::isAuto(a->type);

		if (!is && !instanceOf( type, a->type->llvmType(c) ) )
			return nullptr;		// 输入类型不匹配函数签名

		auto *v = makeCast(c, cache, a->type, i->second);
		ordered->parameters.push_back(std::make_pair(name.empty() ? a->name : name, v));
	}

	// 然后按名称匹配
	std::map<std::string, CodeGen*> indexes;
	// 先创建索引
	for (; i != types.end(); i++) {
		if (i->first.empty()) {
			if (variable) break;
			return clearGen(ordered, cache);	// 进入名字匹配模式时，参数都是需要有名字的
		}
		indexes.insert(std::make_pair(i->first, i->second));
	}

	// 然后按函数参数，找剩下的参数
	for (; a != paremeters.end(); a++) {
		auto x = indexes.find(a->name);
		if (x == indexes.end()) {
			if (a->defaultValue) {	// 有默认值
				ordered->parameters.push_back(std::make_pair(a->name, a->defaultValue));
			}
			else
				return clearGen(ordered, cache);
		}
		auto ty = a->type->llvmType(c);
		if (! instanceOf( x->second->type, ty) )
			return nullptr;

		auto* v = makeCast(c, cache, a->type, x->second);
		ordered->parameters.push_back(std::make_pair(a->name, v));
		indexes.erase(x);
	}

	if (variable) for (; i != types.end(); i++) {	// 可变参数
		auto* v = makeCast(c, cache, variable, i->second);
		ordered->variableGen.push_back(v);
	}
	else if (!indexes.empty())	// 有多余未匹配的参数
		return clearGen(ordered, cache);
	return ordered;
}

AstType * AstFunction::getTypeByName(const std::string & name) {
	if (named.empty()) {
		for (auto &i : paremeters) {
			named[i.name] = i;
		}
	}
	auto iter = named.find(name);
	if (iter == named.end()) return nullptr;
	return iter->second.type;
}

CodeGen * AstFunction::makeCall(LLVMContext& c, const std::vector<std::pair<std::string, CodeGen*>>& types, CodeGen * object){
	OrderedParameters *ordered = orderParameters(c, types);
	if (!ordered) return nullptr;
	// 成功
	return createCallGen(c, ordered->parameters, ordered->variableGen, object);
}

/// <summary>
///  按函数签名保存
/// </summary>
std::unordered_map<std::string, FunctionInstance*> functionInstances;

CodeGen * AstFunction::makeGen(AstContext * parent)
{
	llvm::LLVMContext& c = parent->context();
	this->pathName = parent->pathName;

	// TODO: 判断是否构造函数
	parent->defineFunction( name, this );
	_parent = parent;

	// TODO: 如果非模板函数，直接生成签名 & 实现
	std::vector<std::pair<std::string, Type*>> parameters;

	for (auto &i : paremeters) {
		if (AutoType::isAuto(i.type)) return nullptr;
		parameters.push_back(std::make_pair(i.name, i.type->llvmType(c)));
	}
	if (variable) {
		if (AutoType::isAuto(variable))
			return nullptr;
	}
	ClassInstanceType* cls = nullptr;// TODO: 判断是否类 c ? c->getClassType() : nullptr;
	noTemplateInstance = getFunctionInstance(parent->context(), parameters, variable, cls);
	return nullptr;
}

CodeGen * AstFunction::createCallGen(
	llvm::LLVMContext& c,
	std::vector<std::pair<std::string, CodeGen*>>& parameterGens,
	std::vector<CodeGen*>& variableGen,
	CodeGen* object,
	FunctionInstance* instance
)
{
	auto p = new CallGen();
	if (instance)
		p->function = instance;
	else {
		ClassInstanceType* o = object ? ClassInstanceType::findByStruct(object->type) : nullptr;
		p->function = getFunctionInstance(c, parameterGens, variableGen, o);
	}

	if (object) {
		p->params.push_back(object);
	}

	p->type =p->function->returnType;

	for (auto &i : parameterGens) {
		p->params.push_back(i.second);
	}

	for (auto &i : variableGen) {
		p->params.push_back(i);
	}
	return p;
}

FunctionInstance* AstFunction::getFunctionInstance(
	llvm::LLVMContext& c, 
	std::vector<std::pair<std::string, llvm::Type*>> parameters,
	AstType* variableGen,
	ClassInstanceType* object) {
	if (this->noTemplateInstance) return this->noTemplateInstance;

	AstContext *s;
	auto *instance = new FunctionInstance();

	instance->name = object ? object->name + "." + name : name;
	if (object) {
		instance->module = object->name;
	}

	// 如果是类，首参为类
	if (object) {
		s = object->makeContext(_parent );
		s->setSymbolValue("this", new ClassMemberGen());
		instance->object = llvm::dyn_cast<llvm::StructType>( object->llvmType(c));
	}
	else {
		s = new AstContext(_parent);
	}
	// 参数类型
	for (auto &i : parameters) {
		auto* p = new ParamenterGen();
		p->type = i.second;
		p->name = i.first;

		s->setSymbolValue(i.first, p);
		instance->parameters.push_back(std::make_pair(i.first, p->type));
	}

	// TODO: 可变参数
	if (variable) {
		if (AutoType::isAuto(variable)) {	 // 使用可变函数
			instance->variable = true;
		}
		else { // 类型确定的情况下，转为一个数组
			AstType* tp = new SArrayType(variable, 0);
			auto* p = new ParamenterGen();
			p->type = tp->llvmType(c);
			p->name = variableName;
			s->setSymbolValue(variableName, p);
			instance->parameters.push_back(std::make_pair(variableName, p->type));
		}
	}

	if (block.empty()) {
		std::vector<llvm::Type*> types;
		for (auto i : rets) {
			if (AutoType::isAuto(i->type))
				throw std::runtime_error("函数" + name + "无函数体，返回值必须明确定义类型");
			types.push_back(i->type->llvmType(c));
		}
		instance->returnType = TupleType::create(c, std::move(types));
	} 
	else {
		// 生成函数体
		fillFunctionBlock(s, instance);
	}
	return instance;
}

void AstFunction::fillFunctionBlock(AstContext * s, FunctionInstance *instance)
{
	auto &c = s->context();
	std::vector<CodeGen*> namedReturn;
	std::vector<llvm::Type*>  returnTypes;
	// 初始化返回值
	for (auto *i : rets) {
		if (!i->name.empty()) {
			CodeGen* v = nullptr;
			if (i->right)
				v = i->right->makeGen(s);
			auto *p = new DefGen(i->name, i->type->llvmType(c), v);
			s->setSymbolValue(i->name, p);
			instance->block.push_back(p);
			namedReturn.push_back(p);
		}
		// returnTypes.push_back(i.type);
	}

	for (auto i : block) {
		auto a = i->makeGen(s);
		instance->block.push_back(a);

		auto r = dynamic_cast<ReturnGen*>(a);
		// 尝试通过 return 推导返回值类型
		if (r) {
			auto z1 = r->returnValues.begin();
			auto z2 = rets.begin();
			for (; z2 != rets.end(); z2++) {
				if (z1 == r->returnValues.end()) {	// return 后的参数已经结束
					if (!(*z2)->name.empty()) {	// 填充命名的参数
						auto *p = s->findSymbolValue((*z2)->name, false);
						assert(p);
						r->returnValues.push_back(p);
						returnTypes.push_back(p->type);
					}
					else {
						throw std::runtime_error("return 语句返回的参数不足");
					}
				}
				else {
					auto *g = *z1;
					auto *x = dynamic_cast<AutoType*>((*z2)->type);
					if (x) {	// 需要推导
						x->setDeductive(g->type);
						returnTypes.push_back(g->type);
					}
					else {
						returnTypes.push_back((*z2)->type->llvmType(c));
					}
					z1++;
				}
			}
		}
	}

	instance->returnType = TupleType::create(c, returnTypes);

	if (block.empty()) {
		instance->block.push_back(new ReturnGen());
		return;
	}

	auto *p = block.back();
	if (dynamic_cast<AstReturn*>(p))
		return;

	// 需要补全 Return (命名返回)
	auto *o = new ReturnGen();
	o->returnValues = std::move(namedReturn);
	instance->block.push_back(o);
}

FunctionInstance* AstFunction::getFunctionInstance(
	llvm::LLVMContext& c,
	std::vector<std::pair<std::string, CodeGen*>> parameterGens,
	std::vector<CodeGen*> variableGen,
	ClassInstanceType* object)
{
	// 参数
	std::vector<std::pair<std::string, llvm::Type*>> params;
	for (auto&i : parameterGens) {
		params.push_back(std::make_pair(i.first, i.second->type));
	}

	// 可变参数
	AstType* v = variable;
	if (!variableGen.empty()) {
		std::vector<llvm::Type*> types;
		for (auto& i : variableGen) {
			types.push_back(i->type);
			if (AutoType::isAuto(v))
				dynamic_cast<AutoType*>(v)->setDeductive(i->type);
			else if (v && !instanceOf( i->type, v->llvmType(c))) {
				v = nullptr;
			}
		}
		if (!v) v = new LLVMType( TupleType::create(c, std::move(types)));
	}

	return getFunctionInstance(c, params, v, object);
}
