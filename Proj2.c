#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<time.h>

void update(FILE *fp,char *line,char *pid,pid_t pidh)
{
	fp=fopen("pidlist","r");
	char pidstr[100];
	int count=0;
	int *oldpids=malloc(1);
	while(fgets(line,sizeof line,fp))
	{
		sscanf(line,"%s",pid);
		if(pidh==0)
		{
			sprintf(pidstr,"%d",getpid(pidh));
		}
		else
		{
			sprintf(pidstr,"%d",pidh);
		}
		realloc(oldpids,1+sizeof(oldpids));
		oldpids[count]=atoi(line);
		count++;
	}

int i;
FILE *fp1;
fp1=fopen("pidlist","w");
for(i=0;i<10;i++)
{
	if(oldpids[i]!=0)
	{
		fprintf(fp1,"%d\n",oldpids[i]);
	}
}
fclose(fp1);
}

int main(int argc,char *argv[])
{
pid_t pidh;
pid_t pid;
int status;
FILE *fp;
char line[200];
	if(strcmp(argv[1],"list")==0)
	{
		fp=fopen("pidlist","r");
		char line[100];
		while(fgets(line,sizeof line,fp)!=NULL)
		{
			printf("%s\n",line);
		}
		fclose(fp);
	}
	else if(strcmp(argv[1],"sleep1")==0)
	{	pidh=fork();
		if(pidh==0)
		{
		int n=atoi(argv[2]);
		printf("\n\t child process %d created and is sleeping for %d seconds \n \n",getpid(pidh),n);
		fp=fopen("pidlist","a+");
		fprintf(fp,"%d\n",getpid(pidh));
		fclose(fp);
		int s=sleep(n);
		update(fp,line,pid,pidh);
		printf("%d is done sleeping",getpid(pidh));		
		}
	}
	else if(strcmp(argv[1],"kill1")==0)
	{
		pid_t k=atoi(argv[2]);
		int status=kill(k,SIGINT);
		printf("%d",status);
		FILE *fp;
		char line[50];
		char pid[10]="PID";
		update(fp,line,pid,k);
	}
	else if(strcmp(argv[1],"time1")==0)
	{
	//printf("you r right");
		pid_t tt=atoi(argv[2]);
		char command[100];
		FILE *fp;
		char *tp;
		sprintf(command,"ps |grep %d",tt);
		fp=popen(command,"r");
		printf("%s",command);		
		char line[100];
		while(fgets(line,sizeof line,fp))
		{
			tp=strtok(line, " \t");
		}
		while(tp !=NULL)
		{
			if(strchr(tp,":")!=NULL)
			printf("Time %s \n",tp);
			tp=strtok(NULL, " \t");
		}
	}
	return 0;
}
