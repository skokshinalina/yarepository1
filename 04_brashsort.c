#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortirovka1(int *array, int array_len)
{
    int temp =0;

	    
		int jump = array_len, i;
		int step = 1;
		while (jump > 1 || step)
		{
			if (jump > 1){
				jump /= 1.24733;
			}
			step = 0;
			for (i = 0; i + jump < array_len; ++i)
				if (array[i + jump] > array[i])
				{
				    temp++;
					int tmp;
					tmp = array[i];
					array[i] = array[i + jump];
					array[i + jump] = tmp;
					step = 1;
					temp ++;
				}
			
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
rez = sortirovka1(a,n[f]);
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
