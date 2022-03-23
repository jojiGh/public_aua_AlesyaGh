#include <stdio.h>

int main()
{
	int N, p, r;

	printf("Enter a number:\n");
	scanf("%d", %N);
	printf("Enter the position of the bit to clear");
	scanf("%d", &p);

	r = (~(1 << p) & N;
	printf("the result is%d", r);

	return 0;
}
