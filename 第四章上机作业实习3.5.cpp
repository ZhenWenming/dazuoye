#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	printf("�����������ȡ���ļ���·����");
	char path[500]={NULL};
	int i=0,j=0,k=0,m=0,n=0;
	for(i=0;(path[i]=getchar())!='\n';i++);
	printf("�����������ȡ���ļ������ͣ�");
	char w[10]={NULL};
	for(i=0;(w[i]=getchar())!='\n';i++);
	fp=fopen(path,w);
	
	
	
}
