#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	printf("请输入你想读取的文件的路径：");
	char path[500]={NULL};
	int i=0,j=0,k=0,m=0,n=0;
	for(i=0;(path[i]=getchar())!='\n';i++);
	printf("请输入你想读取的文件的类型：");
	char w[10]={NULL};
	for(i=0;(w[i]=getchar())!='\n';i++);
	fp=fopen(path,w);
	
	
	
}
