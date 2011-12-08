#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char line[200];
	char cmd[200];
	char pid[200];
	int ppid;
	char e1[200];
	char e2[200];
	char e3[200];
	char ch[100]="PID";
	fp=popen("ps -axl","r");
	while(fgets(line,sizeof line,fp))
	{
	sscanf(line,"%*s %*s %s %d %*s %s %*s %s %s %s",pid,&ppid,e1,e3
        ,e2,cmd);
	if(strcmp(pid,ch)==0){}
	else
	{
		printf("%s , %s, %d \n",cmd,pid,ppid);
	}
	
}	
return (0);
}
