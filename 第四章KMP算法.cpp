#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getnext(char t[],int next[])
{
	int i=1;
	next[1]=0;
	int j=0;
	while(i<t[0])
	{
		if(j==0||t[i]==t[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else j=next[j];
	}
	
}

int kmp(char s[],char t[],int pos,int next[])
{
	int i=0;
	i=pos;
	int j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0||s[i]==t[j])
		{
			++i;++j;
		}
		else j=next[j];
	}
	if(j>t[0]) return i-t[0];
	else return 0;
}

int main()
{
	int i=0,j=0,k=0,m=0,pos=0;
	int tn[5000]={0};
	char s[5000]={NULL},t[5000]={NULL};
	printf("����������s:");
	for(i=1;(s[i]=getchar())!='\n';i++);
	s[0]=i-1;
	i=1;
	printf("������ģʽ��t:");
	for(i=1;(t[i]=getchar())!='\n';i++);
	t[0]=i-1;
	getnext(t,tn);
	printf("������s���ĵڼ�λ���ҵ�t��:");
	scanf("%d",&pos);
	m=kmp(s,t,pos,tn);
	if(m==0)printf("s����û���Ӵ���t��ƥ��");
	else printf("s���ĵ�%dλ�����Ӧ�����Ӵ���t��ƥ��",m);
	return 0;
}
