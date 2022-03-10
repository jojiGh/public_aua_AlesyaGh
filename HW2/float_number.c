#include <stdio.h>

int main() {
	float a, b, result;

	printf("This program multiplies two floating numbers.\n");
	printf("Please enter the first number:\n");
	scanf("%f", &a);
	printf("Please enter the second number:\n");
	scanf("%f", &b);

	//useding temp variable here
	result = a * b;

	printf("Here is the result:\n%f * %f = %f", a, b, result);

	return 0;
}
