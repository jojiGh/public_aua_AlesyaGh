#include <stdio.h>

int main() {
	
	int i, s, nums[10]; 

	printf("Please enter the size of an array:\n");
	scanf("%d", &s);
	printf("Please enter the numbers:\n");

	for(i = 0; i < s; i++) {
		scanf("%d", &nums[i]);
	}
	
	for(i = 0; i < s; i++) {
		if(nums[i] < 0) {
			printf("%d,", nums[i]);
		}
	}

	return 0;
}
