#include<stdio.h>
#include<time.h>
void main()
{
FILE *fp,*ft,*fs;
int i,c;
char ch;
clock_t start,stop;
double duration;
fp=fopen("test.txt","r");
ft=fopen("test1.txt","w");
fs=fopen("test2.txt","w");
start=clock();
for(c=1;c<25;c++)
{
for(i=1;i<10000000;i++)
{
while(1)
{
	ch=fgetc(fp);
	if(ch==EOF)
		break;
	else
		fputc(ch,ft);
		fputc(ch,fs);
}
}
}
fclose(fp);
fclose(ft);
fclose(fs);
stop=clock();
duration=(double)(stop-start)/CLOCKS_PER_SEC;
printf("\n Time elapsed for IObound Process is: %.8lf\n",duration);
}
