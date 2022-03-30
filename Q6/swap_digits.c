#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main()
{
	int n, f, l, total, temp, res;

	printf("Plese enter a number:\n");
	scanf("%d", &n);

	total = (int) log10(n);
	temp = n;

	while (temp >= 10)
	{
		temp /= 10;
	}

	f = temp;
	l = n % 10;

	res = (l * pow(10, total) + f) + (n - (f * pow(10, total) + l));

	printf("fist = %d\nlast = %d\n", f, l);	
	printf("before: %d\nafter: %d", n, res);

	return 0;
}
