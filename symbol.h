#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct Symbol
{
	char name[20];
	struct Symbol *next;
}Symbol;

/*集合s1减去集合s2，结果保存在集合s1中，返回1表示s1中元素减少了，否则返回0*/
int subtractSymbol(Symbol **s1, Symbol *s2);
/*求两个集合的并集*/
void mergeSymbol(Symbol **s1, Symbol *s2);

#endif