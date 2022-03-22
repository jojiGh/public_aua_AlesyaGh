#include <stdio.h>

int main()
{
	int num, pos, res;

	printf("Please enter a number:\n");
	scanf("%d", &num);

	printf("Please enter the position of the bit to check:\n");
	scanf("%d", &pos);

	res = (num >> pos) & 1;

	printf("The %d bit is set to %d", pos, res);

	return 0;
}
