#include <stdio.h>
#include <stdlib.h>

int piramida(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}
int main() {
	int n, st = 0;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	while (1) {
		int b = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i * 2 + 2 + st < n)
			{
				if (a[i + st] > a[i * 2 + 1 + st] || a[i + st] > a[i * 2 + 2 + st])
				{
					if (a[i * 2 + 1 + st] < a[i * 2 + 2 + st])
					{
						piramida(&a[i + st], &a[i * 2 + 1 + st]);
						b = 1;
					}
					else if (a[i * 2 + 2 + st] < a[i * 2 + 1 + st])
					{
						piramida(&a[i + st], &a[i * 2 + 2 + st]);
						b = 1;
					}
				}
			}
			else if (i * 2 + 1 + st < n)
			{
				if (a[i + st] > a[i * 2 + 1 + st]) {
					piramida(&a[i + st], &a[i * 2 + 1 + st]);
					b = 1;
				}
			}
		}
		if (!b) st++;
		if (st + 2 == n) break;
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

