#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (void)
{
int x,y,j,w,s=0;
scanf ("%d", &x);
for (j=1; j<=x; j++)
{
scanf ("%d", &y);
w= (pow((-1),(j+1))*pow(y,3));
s=s+w;
}
printf ("%d\n",s);
return 0;
}
