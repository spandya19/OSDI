#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Nodes
{
	char *ncmd;
	char *npid;
	char *nppid;
	struct Nodes *stree;
};

struct Nodes * insert(struct Nodes **root, char *cmd, char *ppid,
char *pid)
{
	while(*root)
	{
		printf("npid %s, ppid %s, pid %s ,compare %d , ncmd %s, cmd %s \n",(*root)->npid,ppid,pid,strcmp((*root)->npid,ppid),(*root)->ncmd,cmd);
		if(strcmp((*root)->npid,ppid)==0)
		{
			printf("equals\n");
			*root=malloc(1000);
			(*root)->stree=0;
			(*root)->ncmd=strdup(cmd);
			return(*root);
		}
		if(strcmp((*root)->npid,pid)!=0)
		{
			root=&((*root)->stree);
		}
	}
		printf("new\n");
		*root=malloc(1000);
		(*root)->stree=0;
		(*root)->ncmd=strdup(cmd);
		return(*root);
}
int i=0;
void print(struct Nodes *root)
{
if(root->stree)
{
	printf("\t %d. %s, %s, %s\n",i,root->ncmd,root->npid,root->nppid);
	i=i+1;
	print(root->stree);
}
i=i+1;
}
void print1(struct Nodes *root)
{
	if(strcmp(root->npid,root->stree->nppid)==0)
	{
	printf("Equals : %s, %s, %s\n",root->ncmd,root->npid,root->nppid);
	print1(root->stree);
	}
	if(strcmp(root->npid,root->stree->nppid)<0)
        {
        printf("Not Equals : %s, %s, %s\n",root->ncmd,root->npid,root->nppid);
        //print1(root->stree);
        }
	return;
	print1(root->stree);
}
int main()
{
	FILE *fp;
	char line[100];
	fp=popen("ps -axl","r");
	char cmd[100];
	char pid[100];
	char ppid[100];

	struct Nodes *tree;
	while(fgets(line,sizeof line,fp))
	{
	sscanf(line,"%*s %*s %*s %*s %*s %*s %s %s %*s %*s %s",pid,ppid,cmd);
	if(strcmp(pid,"PID")!=0)
	{
		insert(&tree,cmd,ppid,pid);
	}
	}
	printf("tree: %s\n", (tree)->stree->ncmd);
	print(tree);
return(0);
}
