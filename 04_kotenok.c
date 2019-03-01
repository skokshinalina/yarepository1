#include <math.h>
#include <stdio.h>
int main (void)
{
int x,y,s=0,j=1;
scanf ("%d", &y);
while (j<=y)
{
scanf ("%d", &x);
s=s+x*(-1);
j++;
}
printf ("%d\n", s);
}
