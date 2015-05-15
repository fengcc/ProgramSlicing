#ifndef GRAPH_TO_DOT_H
#define GRAPH_TO_DOT_H

#include <stdio.h>

#include "cfg_node.h"
#include "program_slicing.h"

void graph_to_dot(CfgNode *root);

/*深度优先遍历控制流图，由graph_to_dot()函数调用*/
void DFSTraverse(CfgNode *node, FILE *dotfile, RecordCfgNode **visited_node);

#endif