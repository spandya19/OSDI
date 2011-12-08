#include<stdio.h>
#include<time.h>
void main()
{
FILE *fp,*ft,*fs;
char line[10000];
int col=0,i,y,c,j;
clock_t start,stop;
double duration;
fp=fopen("test.txt","w");
ft=fopen("test1.txt","w");
fs=fopen("test2.txt","w");

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
	if(y==1)
	{
	fprintf(fp,"%d",i);
	fprintf(ft,"%d",i);
	fprintf(fs,"%d",i);
	}
}
}
fclose(fp);
fclose(ft);
fclose(fs);
stop=clock();
duration=(double)(stop-start)/CLOCKS_PER_SEC;
printf("\n The time elapsed for IOCPUbound is: %.8lf\n",duration);
}
