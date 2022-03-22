#include <stdio.h>

int main()
{
	int s;

	printf("Please enter the size of the array:\n");
	scanf("%d", &s);

	int fib[s];
	fib[0] = 0;
	fib[1] = 1;

	for(int i = 2; i < s; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	for(int i = 0; i < s; i++)
	{
		printf("%d, ", fib[i]);
	}

	return 0;
}
