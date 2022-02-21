#include <stdio.h>

int increment(int i) {
	int a = i + 1;
	return a;
}

int main() {
	int n = 0;
	printf("Enter an integer\n");
	scanf("%d", &n);
	n = increment(n);
	printf("%d", n);
	return 0;
}
