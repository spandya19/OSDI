#include<stdio.h>
#include<time.h>
void main()
{
int i,y,c,j;
clock_t start,stop;
double duration;
start=clock();
for(c=1;c<2;c++)
{
for(i=1;i<=100000;i++)
{
y=1;
for(j=2;j<i;j++)
{
	if(i%j==0)
	{
		y=0;
	}
}
}
}
stop=clock();
duration=(double)(stop-start)/CLOCKS_PER_SEC;
printf("\n Time elapsed for CPUbound Process is: %.8lf \n",duration);
}
