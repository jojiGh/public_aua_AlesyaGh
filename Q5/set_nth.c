#include <stdio.h>

int main ()
{
	int N, p, r;

	printf("Please enter the number:\n");
	scanf("%d", &N);
	printf("Please enter the position of the bit to set:\n");
	scanf("%d", &p);

	r = (1 << p) | N;

	printf("The result is %d", r);

	return 0;
}
