#include <stdio.h>
#include <stdlib.h>

void sortirovka2(int *array, int array_len)
{
	int i, j, jump;
	int tmp;
	for (jump = array_len / 2; jump > 0; jump /= 2)
		for (i = jump; i < array_len; i++)
		{
			tmp = array[i];
			for (j = i; j >= jump; j -= jump)
			{
				if (tmp < array[j - jump])
					array[j] = array[j - jump];
				else
					break;
			}
			array[j] = tmp;
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
	sortirovka2(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (array[i]));
	}
	printf("\n");
}
