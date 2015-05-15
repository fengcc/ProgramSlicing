#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "symbol.h"

int subtractSymbol(Symbol **s1, Symbol *s2)
{
	Symbol *pre, *p;

	if (!s2)
		return 0;

	if (strcmp((*s1)->name, s2->name) == 0)
	{
		p = *s1;
		*s1 = (*s1)->next;
		free(p);

		return 1;
	}
	else
	{
		pre = *s1;
		p = (*s1)->next;
		while (p)
		{
			if (strcmp(p->name, s2->name) == 0)
			{
				pre->next = p->next;
				free(p);

				return 1;
			}
			pre = p;
			p = p->next;
		}
	}

	return 0;
}

void mergeSymbol(Symbol **s1, Symbol *s2)
{
	Symbol *p;
	int flag;

	while (s2)
	{
		flag = 0;
		p = *s1;
		while (p)
		{
			if (strcmp(p->name, s2->name) == 0)
			{
				flag = 1;
				break;
			}
			p = p->next;
		}

		if (!flag)	/*在s1中没有找到*/
		{
			p = (Symbol *)malloc(sizeof(Symbol));
			strcpy(p->name, s2->name);

			p->next = *s1;
			*s1 = p;
		}

		s2 = s2->next;
	}
}