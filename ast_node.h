#ifndef NODE_H
#define NODE_H

#include <stdio.h>

enum AstNodeType
{
	Identifier = 0,
	Number,
	String,
	Keyword,
	Operator,
	Statement,
	Expression,
	FunctionDefinition,
	Declaration
};

typedef union
{
	char value_string[40];
	double value_number;
}NodeValue;

typedef struct AstNode
{
	int id;
	enum AstNodeType nodetype_ast;
	NodeValue value;	/*节点值*/
	int linenumber;		/*在源代码中的行号*/
	int endlinenumber;	/*记录整个语句的结束行号，仅在循环语句或选择语句中使用到*/
	struct AstNode *firstchild, *nextsibling;	/*指向第一个孩子和下一个兄弟*/
}AstNode;

AstNode *ast_root;		/*抽象语法树的根节点*/
extern int linesno;		/*词法分析器的接口*/
int node_counter;		/*抽象语法树的节点编号，用来初始化节点中的index，初始值为1*/

/*-----------------函数详细注释见函数定义处-------------------*/
/*创建表示节点值的共用体节点*/
NodeValue *newNodeValue(int type, ...);

/*创建抽象语法树的节点*/
AstNode *newAstNode(enum AstNodeType type, NodeValue *val, int line_number);

/*连接抽象语法树的节点*/
void linkAstNode(AstNode *parentNode, AstNode *first_child, ...);

/*给节点编号，根节点编号为0*/
void initialiseNodeId(AstNode *node);

/*释放抽象语法树节点所占空间*/
void freeAstNode(AstNode *node);

#endif