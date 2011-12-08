#include<stdio.h>
#include<time.h>
void main()
{
FILE *fp,*ft,*fs;
int i,c;
char ch;
clock_t start,stop;
double duration;
//Opend one file to read from and two files to write in it
fp=fopen("test.txt","r");
ft=fopen("test1.txt","w");
fs=fopen("test2.txt","w");
//started clock to record teh execution time
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
	//put the every character of file test.txt to test1.txt and test2.txt
		fputc(ch,ft);
		fputc(ch,fs);
}
}
}
fclose(fp);
fclose(ft);
fclose(fs);
//stop the recording of time
stop=clock();
//calculating the duration to find the time taken for execution of this Input Output process
duration=(double)(stop-start)/CLOCKS_PER_SEC;
printf("\n Time elapsed for IObound Process is: %.8lf\n",duration);
}
