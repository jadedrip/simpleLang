#include "stdafx.h"
#include "lex.h"
#include "Ast/AstLet.h"
#include "Ast/AstGet.h"
#include "Ast/AstIf.h"
#include "Ast/AstIif.h"
#include "Ast/AstIs.h"
#include "Ast/AstBinary.h"
#include "Ast/AstUnary.h"
#include "Ast/AstLoop.h"
#include "Ast/AstReturn.h"
#include "Ast/AstClass.h"
#include "Ast/AstGetClass.h"
#include "Ast/AstConstant.h"
#include "Ast/AstTuple.h"
#include "Ast/AstFunction.h"
#include "Ast/AstValue.h"
#include "Ast/AstTupleSpread.h"
#include "Ast/AstProtected.h"
#include "Ast/AstDot.h"
#include "Ast/AstConst.h"
#include "Ast/AstEnum.h"
#include "Ast/AstSwitch.h"
#include "Ast/AstTry.h"
#include "Ast/AstNew.h"
#include "Ast/AstInterface.h"
#include "Ast/AstInc.h"
#include "Ast/AstBased.h"
#include "Ast/AstPackage.h"
#include "Ast/AstImport.h"
#include "Ast/AstStringList.h"
#include "Ast/AstStringLiteral.h"
#include "Ast/AstFloatConstant.h"
#include "Ast/AstSequence.h"
#include "Ast/AstCall.h"
#include "Ast/AstSplice.h"
#include "Ast/AstDelete.h"
#include "Ast/AstIndex.h"
#include "Ast/AstDef.h"
#include "Ast/AstSet.h"
#include "Ast/AstList.h"
#include "Ast/AstEmpty.h"
#include "Ast/AstAnnotation.h"
#include "token.h"
#include "utility.h"
#include "Type/AutoType.h"
#include "Type/TupleType.h"
#include "Type/SArrayType.h"
#include "Type/SIntegerType.h"
#include "Type/ClassInstanceType.h"

using namespace std;
using namespace llvm;
vector< status_t > status;
status_t current = prog;
extern AstPackage* currentPackage;

template<typename T = AstLet, typename L>
inline void canCastTo(AstNode* node, L func)
{
	if (node) {
		auto *x = dynamic_cast<T*>(node);
		if (x) {
			func(x);
		}
	}
}

template< typename T = AstLet, typename L >
inline bool foreach(AstNode* node, L func, bool autoDelete = false)
{
	if (node) {
		auto* p = dynamic_cast<AstList*>(node);
		if (p) {
			for (auto *i : p->lines) {
				auto x = dynamic_cast<T *>(i);
				if (x) {
					func(x);
					if (autoDelete) delete x;
				}
			}
			delete p;
			return true;
		} else {
			auto x=dynamic_cast<T *>(node);
			if (x) {
				func(x);
				if (autoDelete) delete x;
			}
			return false;
		}
	}
	return false;
}

template<typename T>
inline void moveLines(vector<T*>& block, AstNode* x)
{
	foreach(x, [block](T* i) {block.push_back(i); });
}

inline void moveLines(vector<AstNode*>& block, AstNode* x)
{
	if (x) {
		auto *p = dynamic_cast<AstList*>(x);
		if (p) {
			block = move(p->lines);
			delete x;
		} else {
			block.push_back(x);
		}
	}
}

AstType* to_type(AstNode* p) {
	return p ? dynamic_cast<AstType*>(p) : nullptr;
}

AstNode* packageName(AstNode* names)
{
	foreach(names, [](AstNode* i) {
		currentPackage->names.push_back(std::move(i->name));
	}, true);
	return nullptr;
}

AstNode* importName(AstNode* n, char* name)
{
	auto *p = new AstImport();
	foreach(n, [&p](AstNode* i) {
		p->identifiers.push_back(std::move(i->name));
	}, true);
	p->identifiers.push_back(name);
	return p;
}

void packageImport(AstNode * n)
{
	foreach<AstImport>(n, [](AstImport* i) {
		currentPackage->imports.push_back(i);
	});
}

void setPackageLines(AstNode * a)
{
	moveLines(currentPackage->lines, a);
}

AstLet* let(char * name, AstNode* value, int flag) {
	return let(nullptr, name, value, flag);
}

AstLet* let(AstType* type, char* name, AstNode* value, int flag)
{
	auto p = new AstLet();
	p->type = type;
	p->name = name ? string(name) : string();
	p->right = value;
	p->flag = flag;
	return p;
}

AstNode* binary(int op, AstNode* left, AstNode* right) {
	if ('.' == op) {
		return new AstDot(left, right);
	}
		
	return new AstBinary(op, left, right);
}

AstNode * binaryIs(AstNode * left, AstType * right)
{
	auto p = new AstIs();
	p->expr = left;
	p->type = right;
	return p;
}

AstNode * link(AstNode * left, AstNode * right)
{
	AstList* p = dynamic_cast<AstList*>(left);
	if (!p) {
		p = new AstList();
		p->lines.push_back(left);
	}
	p->lines.push_back(right);
	return p;
}

AstNode* getVar(const char* name, bool right) {
	auto p = new AstGet();
	p->name = name;
	p->right = right;
	return p;
}

AstNode* makeValue(const char* name, int32_t v) {
	auto a = new AstConstant(name);
	a->set_value(v);
	return a;
}

AstNode* makeValue(const char* name, int64_t v) {
	auto a = new AstConstant(name);
	a->set_value(v);
	return a;
}

AstNode* makeValue(const char* name, float v) {
	return new AstFloatConstant(name, v, false);
}

AstNode* makeValue(const char* name, double v) {
	return new AstFloatConstant(name, v, true);
}

AstNode* makeValue(const char* name, bool v) {
	auto a = new AstConstant(name);
	a->set_value(v);
	return a;
}

AstNode* makeValue(const char* v) {
	// TODO：utf8 支持？
	return new AstStringLiteral(v);
}

AstNode* makeIf(AstNode* cond, AstNode* thenBlock) {
	auto p = new AstIf();
	p->condition = cond;
	moveLines(p->thenBlock, thenBlock);
	return p;
}

AstNode* setElse(AstNode* ifCond, AstNode* elseBlock) {
	auto p = dynamic_cast<AstIf*>(ifCond);
	moveLines(p->elseBlock, elseBlock);
	return ifCond;
}

AstNode* makeWhile(AstNode* cond, AstNode* block) {
	auto p = new AstLoop();
	p->cond = cond;
	moveLines(p->block, block);
	return p;
}

AstNode* makeFor(AstNode* let, AstNode* cond, AstNode* inc, AstNode* block) {
	auto p = new AstLoop();
	canCastTo(let, [p](AstLet* i) {
		auto d = new AstDef();
		d->type = i->type;
		d->vars.push_back( std::make_pair(i->name, i->right) );
		p->let = d;
	});
	
	p->cond = cond;
	p->inc = inc;
	moveLines(p->block, block);
	return p;
}

AstNode * unary(int op, AstNode * v)
{
	return new AstUnary(op, v);
}

AstNode* unaryAfter(int op, AstNode* v) {
	auto *p = new AstUnary(op, v);
	p->after = true;
	return p;
}

AstNode * createFunction(int funcType, const string& name, AstNode * parameters, AstNode * ret, AstNode * block)
{
	auto* p = new AstFunction();
	p->name = name;
	p->funcType = (AstFunction::FunctionType)funcType;
	moveLines(p->block, block);

	foreach(parameters, [p](AstLet* i) {
		FunctionArgument arg = { i->name, i->type, i->right };
		p->paremeters.push_back(move(arg));
	}, true);

	if (ret) {
		foreach(ret, [p](AstLet* i) {p->rets.push_back(i); });
	}

	return p;
}

AstNode * addFunctionBlock(AstNode *node, AstNode * block, AstNode* annotation)
{
	auto p=dynamic_cast<AstFunction*>(node);
	moveLines(p->block, block);
	return p;
}

AstNode * createOperator(int oper, AstNode * variables, AstNode * ret, AstNode * block)
{
	auto n = "operator " + operator_to_str(oper);
	return createFunction(7, n, variables, ret, block);
}

AstType * createInterface(char * name, AstNode * block)
{
	auto *p = new AstInterface();
	p->name = name;
	moveLines(p->block, block);
	return p;
}

AstNode* makeSplice(AstNode* expr, AstNode* begin, AstNode* end) {
	auto p = new AstSplice();
	p->expr = expr;
	p->begin = begin;
	p->end = end;
	return p;
}

AstNode * makeIndex(AstNode * expr, AstNode * x)
{
	auto p = new AstIndex();
	p->expr = expr;
	p->index = x;
	return p;
}

AstNode* makeDelete(AstNode* expr) {
	auto *p = new AstDelete();
	p->expr = expr;
	return p;
}

AstNode* callReturn(AstNode * val)
{
	AstReturn* p = new AstReturn();
	p->returnValues.push_back(val);
	return p;
}

AstType * getFuncType()
{
	return new AstType(AstType::FunctionTyID);
}

AstType * makeArray(AstType * type, AstNode* list)
{
	return new SArrayType(type, list);
}

AstNode* makeSequence(AstNode* node) {
	return new AstSequence(node);
}

AstNode * makeEmpty()
{
	return new AstEmpty();
}

AstNode * makeNull()
{
	return new AstValue();
}

AstType* getType(int type_id) {
	//"var"	yylval.type = 0;	return ITYPE;	/* 内部变量 */
	//"bool"		yylval.type = 1;	return ITYPE;
	//"byte"		yylval.type = 2;	return ITYPE;
	//"char"		yylval.type = 3;	return ITYPE;
	//"short"		yylval.type = 4;	return ITYPE;
	//"int"		    yylval.type = 5;	return ITYPE;
	//"long"		yylval.type = 6;	return ITYPE;
	//"float"		yylval.type = 7;	return ITYPE;
	//"double"	yylval.type = 8;	return ITYPE;
	//"string"	yylval.type = 9;	return ITYPE;
	//"any"		yylval.type = 10;	return ITYPE;

	switch (type_id)
	{
	case 0:
		return new AutoType();
	case 1:
		return SIntegerType::get(1);
	case 2:
		return SIntegerType::get(8);
	case 3:
		return SIntegerType::get(32, true);	// unsigned
	case 4:
		return SIntegerType::get(16);
	case 5:
		return SIntegerType::get(32);
	case 6:
		return SIntegerType::get(64);
	case 7:
		return AstType::floatType;
	case 8:
		return AstType::doubleType;
	case 9:
		return AstType::stringType;
	case 10:
		return AstType::anyType;
	default:
		throw runtime_error("未知类型");
	}
}

AstType * getClassType(char * name)
{
	auto p = new AstGetClass();
	p->name = name;
	return p;
}

AstNode* makeTuple(AstNode* elem, AstNode* list)
{
	auto* p = new AstTuple();
	p->elements.push_back(elem);

	foreach<AstNode>(list, [p](AstNode* i) {
		p->elements.push_back(i);
	});

	return p;
}

AstNode * tupleResolve(AstNode * left, AstNode * tuple)
{
	cout << "tupleResolve: " << tuple->name << endl;
	auto spread = new AstTupleSpread();
	spread->tuple = tuple;

	foreach(left, [spread](AstNode*i) {
		spread->vars.push_back(std::move(i->name));
	}, true);
	return spread;
}

AstNode* makeClass(
	int type,
	char * name,
	AstType* inherit,
	AstNode* block
)
{
	auto *p = new AstClass();
	p->name = name;
	p->singleton = (type == 1);
	if (inherit) p->inherit = (AstGetClass*)inherit;
	moveLines(p->block, block);
	return p;
}

AstNode* setProtected()
{
	return new AstProtected();
}

AstNode * makeConst(char * name, AstNode * value)
{
	AstConst *p = new AstConst();
	p->name = name;
	p->expr = value;
	return p;
}

AstNode * createSwitch(AstNode * cond, AstNode * o)
{
	auto *p = new AstSwitch();
	p->expression = cond;
	foreach<AstCase>(o, [p](AstCase* x) {p->cases.push_back(x); });
	return p;
}

AstNode * makeGet(char * name, AstNode * block)
{
	/*	等同
	func operator get() : var valueName{
	}
	*/

	// TODO: new

	auto *p = new AstFunction();
	p->name = "GET_" + string(name);
	p->rets.push_back(let(name));
	moveLines(p->block, block);
	return p;
}

/*
	set(int v){
	}
*/
AstNode * makeSet(char * name, AstType* type, char* id, AstNode * block)
{
	auto *p = new AstSet();
	if (name) p->name = name;
	p->type = type;
	if (id) {
		p->name = string(id);
	}
	if (block)	moveLines(p->block, block);
	return p;
}

AstNode * makeBased(AstNode * expr, AstNode * block)
{
	auto p = new AstBased();
	p->expr = expr;
	moveLines(p->block, block);
	return p;
}

AstNode * createCase(AstNode * cond, AstNode * block)
{
	auto *p = new AstCase();
	if (cond) {
		moveLines(p->conditions, cond);
	}
	moveLines(p->block, block);
	return p;
}

AstNode * makeCatch(AstNode * e, char * name, AstNode * lines)
{
	auto *p = new AstTryCatch();
	moveLines(p->block, lines);
	p->name = name;
	foreach(e, [p](AstLet* i) {
		p->exception_types.push_back(i->type);
	});
	return p;
}

AstNode * createTry(AstNode * block, AstNode * catchs, AstNode * finallyBlock)
{
	auto *p = new AstTry();
	moveLines(p->block, block);

	foreach<AstTryCatch>(catchs, [p](AstTryCatch* i) {
		p->catchs.push_back(i);
	});
	
	moveLines(p->finallyBlock, finallyBlock);
	return p;
}

AstNode * makeInc(AstNode * expr, bool isInc)
{
	auto p = new AstInc();
	p->expr = expr;
	p->isInc = isInc;
	return p;
}

AstNode * createEnum(char * name, AstNode* items)
{
	auto* p = new AstEnum();
	p->name = name;

	foreach(items, [p](AstLet* x) {
		p->values.push_back(x);
	});
	return p;
}

AstNode * makeCall(char * name, AstNode* node)
{
	auto *p = new AstCall();
	p->name = name;
	foreach<AstNode>(node, [p](AstNode* i) {
		auto x=dynamic_cast<AstLet*>(i);
		if (x) {
			p->arguments.push_back(make_pair(x->name, x->right));
			delete i;
		} else
			p->arguments.push_back(make_pair(string(), i));
	});

	return p;
}

AstNode * createNew(AstType* type, char * name, AstNode * args)
{
	auto *p = new AstNew();
	p->type = type;
	p->name = name;

	if (args) {
		moveLines(p->blocks, args);
	}
	return p;
}

AstNode * createDef(AstNode * def)
{
	auto *x = dynamic_cast<AstLet*>(def);
	auto *p = new AstDef();
	p->type = x->type;
	p->vars.push_back(make_pair(x->name, x->right));
	delete def;
	return p;
}

AstNode * appendDef(AstNode * def, char * name, AstNode * value)
{
	auto *d = dynamic_cast<AstDef*>(def);
	d->vars.push_back(make_pair(name, value));
	return def;
}

AstType* nullAble(AstType* type) {
	type->nullable = true;
	return type;
}

AstNode * annotationdClass(AstNode * annotation, AstNode * cls)
{
	auto *p = dynamic_cast<AstClass*>(cls);
	auto *a = dynamic_cast<AstAnnotation*>(annotation);
	p->annotations[a->name] = a;
	return p;
}

AstNode * makeAnnotation(char * name, AstNode * attrs)
{
	auto *p = new AstAnnotation();
	p->name.assign(name);

	bool is = false;
	foreach(attrs, [p](AstLet* let) {
		p->attrs[let->name] = let->right;
	}, true);

	if (p->attrs.empty()) {
		p->defaultValue = attrs;
	}
	return p;
}

AstNode * makeIsNull(AstNode * value)
{
	// auto* p = AstBinary(EQ, new AstCast( value, 0);
	return nullptr;
}

AstNode * makeIIF(AstNode * cond, AstNode * thenValue, AstNode * elseValue)
{
	return new AstIif(cond, thenValue, elseValue);
}
