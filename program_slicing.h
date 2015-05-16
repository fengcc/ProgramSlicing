#ifndef PROGRAM_SLICING_H
#define PROGRAM_SLICING_H

#include "cfg_node.h"

/*记录每次遍历时访问过的节点，以便在遍历结束时将visited标记置为访问前的值*/
typedef struct RecordCfgNode
{
	int visit_count;	/*专门为循环节点设置，其它节点不需要使用*/
	CfgNode *node_cfg;
	struct RecordCfgNode *next;
}RecordCfgNode;

/*成功返回0, 失败返回1*/
int programSlicing(CfgNode *entry, int lineno, Symbol *var);

/*在控制流图中查找节点，返回相应节点的指针，由programSlicing()函数调用*/
CfgNode *searchNode(CfgNode *node_cfg, int lineno);

/*深度优先遍历控制流图，由searchNode()函数调用*/
CfgNode *DFSSearch(CfgNode *node_cfg, int lineno, RecordCfgNode **visited_node);

/*利用深度优先遍历进行切片，由programSlicing()函数调用*/
void DFSSlicing(CfgNode *node_cfg, Symbol **relevant, 
	RecordCfgNode **visited_node, RecordCfgNode **slicing_list);

/*复制符号链表*/
Symbol *copySymbolList(Symbol *s);

void insertSlicingResult(RecordCfgNode **slicing_list, CfgNode *node_cfg);

#endif