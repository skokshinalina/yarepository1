#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bistro(int* arr, int arr_len) {
    int tem =0;
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
			tem++;
		}tem++;
	} while (r <= arr_len);
	if (arr_len > 0) {tem+=bistro(arr, arr_len);}
	if (arr_len > 0) {tem+=bistro(arr + r, size - r);}
	return tem;
}

int main()
{
    srand(time(0));
  clock_t start,stop;
unsigned long t;
    double rez,sr_rez = 0;
int n[15] = {1,2,3,4,5,10,15,20,25,30,50,75,100,250,500};
for (int f = 0 ; f <15;f++)
{
int *a;
a = (int*)malloc(n[f] * sizeof(int));
start = clock();
for (int j = 0;j <1000;j++)
{
for (int i = 0;i < n[f]; i ++)
{
a[i] = rand()%10000 - 8000;
} 
rez += bistro(a,n[f]);
}
stop = clock();
printf("%d\n %f \n",n[f],rez/1000);
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
}


