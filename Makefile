#which complier
CC = gcc

ProgramSlicing: flex_c.l bison_c.y main.o ast_node.o cfg_node.o graph_to_dot.o
	bison -d bison_c.y
	flex flex_c.l
	$(CC) -o $@ bison_c.tab.c lex.yy.c main.o ast_node.o cfg_node.o graph_to_dot.o -lfl

main.o: main.c bison_c.tab.h ast_node.h cfg_node.h graph_to_dot.h
ast_node.o: ast_node.c ast_node.h
cfg_node.o: cfg_node.c cfg_node.h ast_node.h
graph_to_dot.o: graph_to_dot.c graph_to_dot.h cfg_node.h ast_node.h