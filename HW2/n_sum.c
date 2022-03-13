#include <stdio.h>

int main() {
	int n, s = 0;

	printf("This program calculates the sum of all natural numbers until the inputted number.\nPlease enter a positive integer:\n");
       scanf("%d", &n);

	for(int i = 0; i <= n; i++) {
		s += i;
	}       
	
	printf("The sum is %d", s);

	return 0;
}
