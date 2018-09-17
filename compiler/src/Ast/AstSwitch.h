#pragma once
#include "AstContext.h"
#include "AstCase.h"


/** switch 分支
	switch vegetable {
		case "celery":
			vegetableComment = "Add some raisins and make ants on a log."
		case "cucumber", "watercress":
			vegetableComment = "That would make a good tea sandwich."
		default:    //by gashero
			vegetableComment = "Everything tastes good in soup."
	}
*/
class AstSwitch : public AstNode
{
public:
	AstNode*				expression;		// 用来比较的变量（表达式）
	std::vector<AstCase*>	cases;			// 分支
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
};
