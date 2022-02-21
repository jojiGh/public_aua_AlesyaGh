#include <stdio.h>

int main() {
	int h = 10;
	int w = 20;
	int i = w - 2;
	int count_w = 0;
	int count_h = 0;
	int count_i = 0;
	while (count_w < w) {
		printf("*");
		count_w++;
	}
	printf("\n");
	count_w = 0;
	while (count_h < h) {
		printf("*");
		while (count_i < i) {
			printf(" ");
			count_i++;
		}
		printf("*\n");
		count_i = 0;
		count_h++;
	}
	while (count_w < w) {
	printf("*");
	count_w++;
	}
	return 0;
}

