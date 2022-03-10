#include <stdio.h>

int main() {
	int temp, first, second;

	printf("This program swaps two inputted numbers\n");
	printf("Please enter the first number:\n");
	scanf("%d", &first);
	printf("Please enter the second number:\n");
	scanf("%d", &second);

	temp = first;
	first = second;
	second = temp;

	printf("Here is the result:\nThe first number became %d\nThe second number became %d.", first, second);
	
	return 0;
}
