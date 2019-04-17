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
#include "CodeGenerate/LambdaGen.h"
#include "CodeGenerate/ThisGen.h"
#include "utility.h"
#include "AstGetClass.h"
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

void AstFunction::genDefaultValue(AstContext * context)
{
	for (auto &i : paremeters) {
		if (i.defaultValue) return;// 已经执行过
		if (i.value)
			i.defaultValue = i.value->makeGen(context);
	}
}

CodeGen * AstFunction::makeCast(llvm::LLVMContext& c, std::vector<CodeGen*> cache, AstType * type, CodeGen * value)
{
	if (type->isAuto()) return value;
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

AstFunction::OrderedParameters* AstFunction::orderParameters(
	AstContext* content,
	const std::vector<std::pair<std::string, CodeGen*>>& types,
	const std::map<std::string, AstType*>* mapedTemplateTypes,
	bool force
)
{
	raw_os_ostream log(std::clog);

	llvm::LLVMContext& c = content->context();
	auto * ordered = new OrderedParameters();
	std::vector<CodeGen*> cache;  // 这里保存生成的转换器，匹配失败退出时，清理

	auto a = paremeters.begin();
	auto i = types.begin();
	for (; i != types.end() && a != paremeters.end(); a++, i++) {	// 先顺序匹配
		const std::string& name = i->first;
		Type* type = i->second->type;	// 参数的类型

		if (!name.empty() && a->name != name)
			break;	// 如果输入有名字，并且和当前位置不匹配，退出顺序匹配模式

		AstType* aType = a->type;
		bool is = AutoType::isAuto(aType);
		if (!is) {
			auto *x = dynamic_cast<AstGetClass*>(aType);
			if (x&&mapedTemplateTypes) {
				auto it = mapedTemplateTypes->find(x->name);
				if (it != mapedTemplateTypes->end()) {
					aType = it->second;
					x = dynamic_cast<AstGetClass*>(aType);
				}
			}
		
			if (x) { // TODO: 判断类是否能转换
				// 参数有两种可能，非模板类型或者确定了模板参数的模板类
				// 或者是模板类型，这种情况下，函数也应该是模板的，这种
				// 情况下，就应该以参数来实例化
				// 而如果是非模板参数，就要考虑继承
				if(!type->isStructTy())
					return clearGen(ordered, cache);
				
				auto cls=_parent->findClass(x->name);
				// TODO: cls->is(type)  // 判断
				if (cls->isTemplated()) {

				} else {
					
				}
				ordered->parameters.push_back(std::make_pair(name.empty() ? a->name : name, i->second));
				continue;
			} else {
				auto * tp=aType->llvmType(c);
				if (force) { // 强制完全相同
					if (tp != type) 
						return nullptr;
				} else if (tp->isFunctionTy() && type->isPointerTy()) {
					auto *pt=type->getPointerElementType();
					if (pt != tp) {
						throw std::runtime_error("函数指针类型不匹配");
					}
					/*log << "Func array ";
					tp->print(log);
					log << " is ";
					pt->print(log);
					log << " : " << (tp==pt? "true" : "false") << "\r\n";
					log.flush();*/
				} else if (!instanceOf(type, aType->llvmType(c)))
					return nullptr;		// 输入类型不匹配函数签名
			}
		}

		auto *v = makeCast(c, cache, aType, i->second);
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
				continue;
			} 
			else
				return clearGen(ordered, cache);
		}
		auto ty = a->type->llvmType(c);
		assert(ty);
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

CallGen * AstFunction::makeCall(
	AstContext* context, 
	const std::vector<std::pair<std::string, CodeGen*>>& types,
	CodeGen * object,
	ClassInstanceType* clsType,
	std::map<std::string, AstType*>* templateVars
)
{
	llvm::LLVMContext& c = context->context();
	OrderedParameters *ordered = orderParameters(context, types, templateVars);
	if (!ordered) return nullptr;
	// 成功

	auto *func = _funcInstance ? _funcInstance
		: getFunctionInstance(c, ordered->parameters, ordered->variableGen, clsType);
	auto p = new CallGen(func);

	p->object = object;
	//if (object)
	//	p->params.push_back(object);
	auto& excapes = func->excapes;
	// 如果函数是空的，所有参数被认为是会逃逸的
	bool empty = func->block.codes.empty();

	for (auto &i : ordered->parameters) {
		assert(!i.first.empty());
		if (empty || excapes.find(i.first) != excapes.end())
			i.second->escape = true;
		p->params.push_back(i.second);
	}

	for (auto &i : ordered->variableGen) {
		p->params.push_back(i);
	}
	return p;
}

CodeGen * AstFunction::makeGen(AstContext * parent)
{
	if (_parent) return nullptr; // 已经执行过
	llvm::LLVMContext& c = parent->context();
	this->pathName = parent->pathName;

	// TODO: 判断是否构造函数
	parent->defineFunction( name, this );
	_parent = parent;

	// TODO: 如果非模板函数，直接生成签名 & 实现
	std::vector<std::pair<std::string, Type*>> parameters;

	for (auto i : rets) {
		auto *p = dynamic_cast<AstGetClass*>(i->type);
		if (p) p->context = parent;
	}

	for (auto &i : paremeters) {
		auto *p = dynamic_cast<AstGetClass*>(i.type);
		if (p) p->context = parent;
	}

	for (auto &i : paremeters) {
		auto *tp = i.type;
		if (AutoType::isAuto(tp)) return nullptr;
		// TODO: AstGetClass
		if(name.empty())
			parameters.push_back(std::make_pair(i.name, tp->llvmType(c)));
	}

	// _isTemplate = _cls && _cls->isTemplated();

	if (funcType==Lambda || name.empty()) {// 匿名函数
		if (_isTemplate) throw std::runtime_error("匿名函数不能是模板的");
		if (variable)  throw std::runtime_error("匿名函数不允许有可变参数");
		
		_funcInstance = getFunctionInstance(c, parameters, nullptr, dynamic_cast<ClassInstanceType*>(parent));
		return new LambdaGen(this, _funcInstance);
	}

	return nullptr;
}

// 对于成员函数，如果类是模板的，那么函数需要复制给固化类

AstFunction * AstFunction::clone()
{
	auto *p = new AstFunction();
	p->name = name;
	p->pathName = pathName;
	p->paremeters = paremeters;
	p->rets = rets;
	p->isOperator = isOperator;
	p->variable = variable;
	p->variableName = variableName;
	p->overload = overload;
	p->block = block;
	p->_parent = _parent;
	p->_cls = _cls;
	p->_isTemplate = _isTemplate;
	return p;
}
// TODO: 移除，整理模块
extern std::unique_ptr<Module> module;
FunctionInstance* AstFunction::getFunctionInstance(
	llvm::LLVMContext& c, 
	std::vector<std::pair<std::string, llvm::Type*>> parameters,
	AstType* variableGen,
	ClassInstanceType* object) {

	if (_funcInstance) return _funcInstance;

	auto *instance = new FunctionInstance();
	instance->overload = overload || isTemplate();

	// 如果不是匿名函数，定义唯一名称
	if(!name.empty())
		instance->name = object ? object->uniqueName() + "." + name : pathName + "." + name;
	if (object) {
		instance->module = object->name;
	}
	
	AstContext *s = new AstContext(_parent);
	// 如果是类，首参为类
	if (object) {
		// s = object->makeContext(_parent );
		Type* v = object->llvmType(c);
		assert(v);
		auto t=new ThisGen(v);
		s->setSymbolValue("this", t);
		instance->object = llvm::dyn_cast<llvm::StructType>(v);

		for (auto &i : object->memberGens) {
			auto *p = i.second->clone(t);
			s->setSymbolValue(i.first, p);
		}
	}

	// 参数写入环境
	for (auto &i : parameters) {
		auto* p = new ParamenterGen();
		p->type = i.second;
		p->name = i.first;

		s->setSymbolValue(i.first, p);
		instance->parameters.push_back(std::make_pair(i.first, p->type));
	}

	// 可变参数
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

	if (isOperator || overload) { // 如果是操作符重载或重载
		instance->overload = true;
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
		instance->generateCode(module.get(), c);
	}
	if (!_isTemplate)
		_funcInstance = instance;

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
			p->escape = true; // 返回值必定是逃逸的
			s->setSymbolValue(i->name, p);
			instance->block.codes.push_back(p);
			namedReturn.push_back(p);
		}
		// returnTypes.push_back(i.type);
	}

	for (auto i : block) {
		auto a = i->makeGen(s);
		instance->block.codes.push_back(a);

		if (a->escape) {
			auto *x=dynamic_cast<ParamenterGen*>(a);
			if (x) { // 参数逃逸了
				instance->excapes.insert(x->name);
			}
		}

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
		instance->block.codes.push_back(new ReturnGen());
		return;
	}

	auto *p = block.back();
	if (dynamic_cast<AstReturn*>(p))
		return;

	// 需要补全 Return (命名返回)
	auto *o = new ReturnGen();
	o->returnValues = std::move(namedReturn);
	instance->block.codes.push_back(o);
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
		auto *t = i.second->type;
		params.push_back(std::make_pair(i.first, t));
		if (t->isArrayTy()) { // 长度
			params.push_back(std::make_pair("size", llvm::IntegerType::get(c, 32)));
		}
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
