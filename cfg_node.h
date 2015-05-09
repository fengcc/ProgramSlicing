#ifndef CFG_H
#define CFG_H

#include "ast_node.h"

#define true 1
#define false 0

enum CfgNodeType
{
	Entry,
	Assign_express_jump,
	Select,
	Iteration,
	Exit
};

/*用来保存后继节点指针的链表节点*/
struct _CfgNodeList
{
	int path_value;		/*路径值，true或false*/
	struct _CfgNode *node_cfg;
	struct _CfgNodeList *next;
};

/*在此是一条语句一个控制流图节点，而不是一个语句块一个节点*/
struct _CfgNode
{
	enum CfgNodeType nodetype_cfg;

	AstNode *node_of_ast;	/*对应的抽象语法树节点*/
	int visited;	/*节点是否访问过*/

	struct _CfgNodeList *predecessor;	/*前驱节点指针链表*/
	struct _CfgNodeList *successor;		/*后继节点指针链表*/
};

typedef struct _CfgNodeList CfgNodeList;
typedef struct _CfgNode CfgNode;

/*用于建立控制流图时作为参数传递使用*/
typedef struct NodeParameterList
{
	CfgNode *node_cfg;			/*用于连接节点的前驱节点时使用*/
	CfgNodeList *node_succ;		/*用于连接节点的后继节点时使用*/
	struct NodeParameterList *next;
}NodeParameterList;

/*根据抽象语法树，创建控制流图*/
CfgNode *createCFG(AstNode *node_ast);

/*先序递归遍历抽象语法树，同时建立控制流图，由createCFG()函数调用*/
NodeParameterList *createNodeRecursively(NodeParameterList *succlist, AstNode *node_ast);

/*---------------不同类型节点处理函数----------------*/
/*赋值语句节点或表达式语句节点或跳转语句节点处理函数*/
NodeParameterList *assign_express_jump_case(NodeParameterList *succlist, AstNode *node_ast);
/*选择语句节点处理函数*/
NodeParameterList *select_no_else_case(NodeParameterList *succlist, AstNode *node_ast);
NodeParameterList *select_with_else_case(NodeParameterList *succlist, AstNode *node_ast);
/*循环语句处理函数*/
NodeParameterList *iteration_case(NodeParameterList *succlist, AstNode *node_ast);

/*创建控制流图节点，由节点处理函数调用*/
CfgNode *newCfgNode(enum CfgNodeType type);

void freeCfgNode(CfgNode *node);

#endif