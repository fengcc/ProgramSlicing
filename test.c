#include <stdio.h>

int main()
{

	int i = 0;

	if ( i == 0)
	{
		printf("Hello world!\n");
		if (i == 0)
		{
			printf("Hello\n");
		}
		else
		{
			printf("hi\n");
		}
	}

	while (i < 4)
	{
		printf("%d\n", i);
		i++;
	}

	return 0;
}