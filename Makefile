#which complier
CC = gcc

#Options for development
CFLAGS = -g

ProgramSlicing: flex_c.l bison_c.y main.o ast_node.o cfg_node.o \
				graph_to_dot.o write_ast_to_file.o program_slicing.o symbol.o
	bison -d bison_c.y
	flex flex_c.l
	$(CC) -o $@ bison_c.tab.c lex.yy.c main.o ast_node.o cfg_node.o \
	graph_to_dot.o write_ast_to_file.o program_slicing.o symbol.o -lfl

main.o: main.c bison_c.tab.h ast_node.h cfg_node.h symbol.h \
 program_slicing.h graph_to_dot.h write_ast_to_file.h
ast_node.o: ast_node.c ast_node.h
cfg_node.o: cfg_node.c cfg_node.h ast_node.h symbol.h
graph_to_dot.o: graph_to_dot.c graph_to_dot.h cfg_node.h ast_node.h \
 symbol.h program_slicing.h
write_ast_to_file.o: write_ast_to_file.c write_ast_to_file.h ast_node.h
program_slicing.o: program_slicing.c program_slicing.h cfg_node.h \
 ast_node.h symbol.h
symbol.o: symbol.c symbol.h