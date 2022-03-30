#include <stdio.h>

int main()
{
	int a[5] = {1, 2, 3, 5, 7};

	for(int i = 0; i < 5; i++)
	{
		if((a[i] == 5) && (a[i + 1] == 7))
		{
			a[i + 1] = 1;
		}
	}

	for(int i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}
