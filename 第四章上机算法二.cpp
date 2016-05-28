#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
 char c;
 struct node *next;
}node;


node *creat(node *phead,char h[])//创建一个单链表，储存串
{
 node *p1,*p2;
 int i=0;
 p1=p2=(node *)malloc(sizeof(node));

 p1->c=h[i];
 p1->next=NULL;
 while(h[i]!='#')
 {
  if(phead==NULL)phead=p1;
  else p2->next=p1;
  p2=p1;
  p1=(node *)malloc(sizeof(node));
  i++;
  p1->c=h[i];
  p1->next=NULL;
 }
 return phead;
}

void print(node *phead)
{
	node *p;
	p=phead;
	while(p!=NULL)
	{
	printf("%c",p->c);
	p=p->next;
	}
}



int main()
{
	node *s=NULL,*t=NULL;
	printf("请输入串s(以#结束):");
	char s1[1000]={NULL},t1[1000]={NULL},s2[1000]={NULL};
	int i=0,j=0,k=0,n=0,m=0;
	for(i=0;(s1[i]=getchar())!='\n';i++);
	n=i-1;

	s=creat(s,s1);
	printf("请输入串t(以#结束,不比s长):");
	for(i=0;(t1[i]=getchar())!='\n';i++);
	m=i-1;

	t=creat(t,t1);
	node *ps,*pt,*q;
	pt=t;
	for(ps=s;ps!=NULL;ps=ps->next)
		if(pt->c==ps->c)
		{
			q=ps;
			k++;
			pt=pt->next;
			for(;pt!=NULL;pt=pt->next)
			{
				ps=ps->next;
				if(ps->c==pt->c)k++;
			}
			if(k==m)break;
			else k=0;
		};
	if(k!=m)printf("串s中没有与串t匹配的子串\n");
	else
	{
		k=1;
		node *q1;
		q1=q;
		for(;k<=m;k++)
		{
		s2[k]=q1->c;
		q1=q1->next;
		}
		k--;
		for(;k>=1;k--)
		{
			q->c=s2[k];
			q=q->next;
		}
		printf("匹配子串逆值后的串s:");
		print(s);
	}
	return 0;
}
