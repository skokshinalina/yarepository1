#include <stdlib.h>
#include <stdio.h>


void swapper(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* dejkstri(int array[5][5], int size, int v)
{
	int* array_ = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		if (i == v)
			array_[i] = 0;
		else
			array_[i] = 1000;
	}
	int t, minr, q, bef[5] = { 1, 1, 1, 1, 1 };
	do {
		minr = 1000;
		q = 1000;
		for (int i = 0; i < size; i++) {
			if ((bef[i] == 1) && (array_[i] < 1000)) {
				minr = array_[i];
				q = i;
			}
		}
		if (q != 1000) {
			for (int i = 0; i < size; i++) {
				if (array[q][i] > 0) {
					t = minr + array[q][i];
					if (t < array_[i])
						array_[i] = t;
				}
			}
			bef[q] = 0;
		}
	} while (q < 1000);
	return array_;
}
int findMindCountour(int* a, int g[5][5], int n, int len)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else {
				if (g[i][j] == 0)
					g[i][j] = 1000;
			}
		}
	}
	int temp = 0;
	int z = 0;
	int sum = 0;
	for (int i = 0; i <= n - 1; i++)
		sum += g[a[i % 5]][a[(i + 1) % 5]];
	if (len > sum) {
		len = sum;
	}
	while (z < 119) {
		sum = 0;
		int j = n - 2;
		while (j != -1 && a[j] >= a[j + 1])
			j--;
		if (j == -1)
			z = 119;
		int k = n - 1;
		while (a[j] >= a[k])
			k--;
		{
			swapper(&a[j], &a[k]);
		}
		int l = j + 1, r = n - 1;
		while (l < r)
			swapper(&a[l++], &a[r--]);
		for (int i = 0; i <= n - 1; i++)
			sum += g[a[i % 5]][a[(i + 1) % 5]];
		if (len > sum)
			len = sum;
		z++;
	};
	return len;
}
int main() 
{



	int LengthMass = 0;
	printf("Введите количетсво вершин ");
	scanf("%d", &LengthMass);
	int graph[LengthMass][LengthMass];

	for (int i = 0; i < LengthMass; i++) {
		for (int j = 0; j < LengthMass; j++) {
			printf("Введите вес ребра между вершинами %d %d ", i + 1,j + 1);
			scanf("%d",&graph[i][j]) ;
		}
	}



	int* arr = (int*)malloc(LengthMass * sizeof(int));
	for (int i = 0; i < LengthMass; i++)
		arr[i] = i;
	int z = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	int v;
	printf("Введите начальную вершину\n");
	scanf("%d", &v);
	int* f = dejkstri(graph, LengthMass, v - 1);
	for (int i = 0; i < 5; i++) {
		if (f[i] <= 9999) {
			printf("Минимальный путь %d в %d: %d\n", v, z, f[i]);
		}
		z++;
	}
	int fk = findMindCountour(arr, graph, LengthMass, 9999);
	if (fk <= 9999) {
		printf("Контур минимальной длинны %d\n", fk);
	}
	return 0;
}
