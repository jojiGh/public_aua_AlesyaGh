#include <stdio.h>

int main() {
	int a, b, c;
	
	printf("This program finds the largest number among three different numbers.\nPlease enter three different numbers:\n");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a > c) {
		printf("%d is the largest number\n", a);
	} else if (b > a, b > c) {
		printf("%d is the largest number\n", b);
	} else 	printf("%d is the largest number\n", c);
	
	return 0;
}
