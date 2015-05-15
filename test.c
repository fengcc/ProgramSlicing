#include <stdio.h>

int main()
{
	int i;
	int sum =0;
	int product =1;

	i = 0;
	while (i < 5)
	{
		sum = sum + i;
		product = product * i;

		i = i + 1;
	}

	printf("%d\n", sum);
	printf("%d\n", product);

	return 0;
}