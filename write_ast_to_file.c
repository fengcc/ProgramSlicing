#include <stdio.h>
#include <stdlib.h>

#include "write_ast_to_file.h"

/*遍历抽象语法树
  按先序遍历顺序初始化节点中的索引值index，即给节点编号，根节点编号为1,便于识别;
  按后序遍历顺序将节点信息写入文件，这种顺序便于以后建立语法树;
  函数递归调用结束后，node_counter的值即为总节点数.*/
void writeNodeToFile(AstNode *root, FILE *file_stream)
{
	if(root)
	{
		writeNodeToFile(root->firstchild, file_stream);		/*写入孩子节点*/
		writeNodeToFile(root->nextsibling, file_stream);	/*写入兄弟节点*/

		/*---------------写入节点信息------------------*/
		/*写入节点索引*/
		fprintf(file_stream, "@%-7d", root->id);
		/*写入节点类型*/
		fprintf(file_stream, "type      : %-8d", root->nodetype_ast);
		/*写入节点值，并换行*/
		if (valueIsNumber(root->nodetype_ast))
			fprintf(file_stream, "value     : %-39.6lf\n", root->value.value_number);
		else
			fprintf(file_stream, "value     : %-39s\n", root->value.value_string);

		/*写入行号，前面加入空格，保持对齐*/
		fprintf(file_stream, "        linenumber: %-8d", root->linenumber);
		
		/*写入第一个孩子的索引，若不存在则写入-1*/
		fprintf(file_stream, "firstchild: %-8d", root->firstchild ? root->firstchild->id : -1);
		/*写入兄弟节点的索引，若不存在则写入-1;并换行*/
		fprintf(file_stream, "nextsibling: %-7d\n\n", root->nextsibling ? root->nextsibling->id : -1);
	}
}

/*将抽象语法树写入文件中*/
void writeAstToFile(AstNode *root)
{
	FILE *file_stream;

	file_stream = fopen("astfile", "w");

	/*写入节点总数*/
	fprintf(file_stream, "TheTotalNumberOfNodes: %-8d\n\n", node_counter-1);

	writeNodeToFile(root, file_stream);

	fclose(file_stream);
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