#include <stdio.h>
#include <stdlib.h>

void bistro(int* arr, int arr_len) {
	int size = arr_len;
	int r = 0;
	int t = arr[(int)(arr_len / 2)];
	int tmp = 0;
	do {
		while (arr[r] < t) r++;
		while (arr[arr_len] > t) arr_len--;

		if (r <= arr_len) {
			tmp = arr[r];
			arr[r] = arr[arr_len];
			arr[arr_len] = tmp;
			r++;
			arr_len--;
		}
	} while (r <= arr_len);
	if (arr_len > 0) bistro(arr, arr_len);
	if (arr_len > 0) bistro(arr + r, size - r);
}
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	bistro(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (arr[i]));
	}
	printf("\n");
}
