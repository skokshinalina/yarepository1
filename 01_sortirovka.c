#include <stdio.h>
#include <stdlib.h>

void sortirovka1(int *array, int array_len)
{
	if (array && array_len)
	{
		int jump = array_len, i;
		int step = 1;
		while (jump > 1 || step)
		{
			if (jump > 1)
				jump /= 1.24733;
			step = 0;
			for (i = 0; i + jump < array_len; ++i)
				if (array[i + jump] > array[i])
				{
					int tmp;
					tmp = array[i];
					array[i] = array[i + jump];
					array[i + jump] = tmp;
					step = 1;
				}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	sortirovka1(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (array[i]));
	}
	printf("\n");
}
