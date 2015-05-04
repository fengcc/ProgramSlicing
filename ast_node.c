#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#include "ast_node.h"

/*创建一个表示节点值的共用体，若type值为0,则共用体使用的是value_string成员，若type值为1,则使用的是value_number成员*/
NodeValue *newNodeValue(int type, ...)
{
	NodeValue *union_node = (NodeValue *)malloc(sizeof(NodeValue));
	va_list ap;
	va_start(ap, type);

	if (type == 0)
		strcpy(union_node->value_string, va_arg(ap, char *));
	else
		union_node->value_number = va_arg(ap, double);

	va_end(ap);
	
	return union_node;
}

/*创建一个抽象语法树的节点，并初始化其类型、值、以及行号*/
AstNode *newAstNode(enum AstNodeType type, NodeValue *val, int line_number)
{
	AstNode *node = (AstNode *)malloc(sizeof(AstNode));
	
	node->nodetype_ast = type;
	
	if (type == Number)
		node->value.value_number = val->value_number;
	else
		strcpy(node->value.value_string, val->value_string);

	free(val);	/*因val所占的内存空间是在函数newNodeValue()中动态分配的，所以使用完后需要释放，防止内存泄漏*/
	val = NULL;

	node->linenumber = line_number;

	/*初始化时将指向第一个孩子和下一个兄弟的指针赋空指针，实际指向在linkAstNode()函数中赋值*/
	node->firstchild = node->nextsibling = NULL;	

	return node;
}

/*将父节点和第一孩子相连，并将第一个孩子和它自己的兄弟相连，因不确定兄弟有多少，所以这里使用了变长参数*/
void linkAstNode(AstNode *parentNode, AstNode *first_child, ...)
{
	AstNode *pre_temp, *temp;
	va_list ap;
	va_start(ap, first_child);
	
	parentNode->firstchild = first_child;
	
	pre_temp = first_child;
	while ((temp = va_arg(ap, AstNode *)) != NULL)
	{
		pre_temp->nextsibling = temp;

		pre_temp = temp;
	}

	va_end(ap);
}

/*按先序遍历的顺序给节点编号，根节点编号为1，递归调用结束后，node_counter的值即为节点总个数+1*/
void initialiseNodeId(AstNode *node)
{
	if (node)
	{
		node->id = node_counter++;

		initialiseNodeId(node->firstchild);
		initialiseNodeId(node->nextsibling);
	}
}

/*判断节点值是string型还是number型，string型返回0.number型返回1*/
int valueIsNumber(enum AstNodeType type)
{
	switch(type)
	{
		case Number: 
				return 1;
		case Identifier:
		case String:
		case Keyword:
		case Operator:
		case Statement:
		case Expression:
		case FunctionDefinition:
		case Declaration:
				return 0;
	}
}

/*后序遍历，释放节点空间*/
void freeAstNode(AstNode *node)
{
	if(node)
	{
		freeAstNode(node->firstchild);
		freeAstNode(node->nextsibling);

		free(node);
		node = NULL;
	}
}