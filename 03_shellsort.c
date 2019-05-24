#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int  sortirovka2(int *array, int array_len)
{
	int i, j, jump,temp=0;
	int tmp;
	for (jump = array_len / 2; jump > 0; jump /= 2)
		for (i = jump; i < array_len; i++)
		{
			tmp = array[i];
			for (j = i; j >= jump; j -= jump)
			{
				if (tmp < array[j - jump]){
					array[j] = array[j - jump];
					temp++;
				}
				else{
				    temp++;
					break;
				}
			}
			temp++;
			array[j] = tmp;
			
		}
		return temp;
}

int main()
{
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
a[i] = rand()%  10000 - 8419;
} 
rez = sortirovka2(a,n[f]);
sr_rez +=rez;
}
stop = clock();
printf("%d\n %f \n",n[f],sr_rez/1000);
sr_rez = 0;
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
}
