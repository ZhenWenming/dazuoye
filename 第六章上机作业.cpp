#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tnode
{
	struct tnode *lchild;
	struct tnode *rchild;
	int e;
}tnode,*bitree;

void createbitree( tnode &t)
{
	
}

int xian(tnode *t)//先序遍历
{
	if(t!=NULL)
	{
		printf("%d",t->e);
		xian(t->lchild);
		xian(t->rchild);
	}
	else return 1;
}

int zhong(tnode *t)//中序遍历
{
	if(t!=NULL)
	{
		zhong(t->lchild);
		printf("%d ",t->e);
		zhong(t->rchild);
	}
	else return 1;
}

int hou(tnode *t)//后序遍历
{
	if(t!=NULL)
	{
		hou(t->lchild);
		hou(t->rchild);
		printf("%d ",t->e);
	}
	else return 1;
}

/*int ceng(tnode &t)//层序遍历
{
	int p;
	queue q;
	Initqueue(q);
	if(t!=0)enqueue(q,t);
	while(!queueempty(q))
	{
		dequeue(q,p);
		visit(p->e);
		if(p->lchild)enqueue(q,p->lchild);
		if(p->rchild)enqueue(q,p->rchild);
	}
	return 1;
}*/

void jiedian()//节点数计算
{

}

int yezi(int &i,tnode *t)//叶子数计算
{
	if(t!=NULL)
	{
		if(!t->lchild&&!t->rchild)i++;
		yezi(i,t->lchild);
		yezi(i,t->rchild);
	}
	return 1;
}

void depth()//树的深度计算
{

}

void width()//树的宽度计算
{

}

void destroybitree()//销毁树
{

}

int copybitree(tnode *t,tnode *t1)//复制树
{
	tnode *p;
	if(t!=NULL)
	{
		p=NULL;
		if(!p)return 0;
		p->e=t->e;
		t1=p;
		copybitree(t->lchild,t1->lchild);
		copybitree(t->rchild,t1->rchild);
	}
	else
	{
		t1=t;
	}
	return 1;
}

int main()
{
	printf("**********************************************************\n");
	printf("                     二叉树运算                       \n");
	printf("**********************************************************\n");
	int a=-1;
	while(a)
	{
	printf("功能列表\n\n");
	printf("1.先序遍历\n");
	printf("2.中序遍历\n");
	printf("3.后序遍历\n");
	printf("4.层序遍历\n");
	printf("5.求节点数\n");
	printf("6.求叶子数\n");
	printf("7.求宽度\n");
	printf("8.求深度\n");
	printf("9.复制二叉树\n");
	printf("10.销毁二叉树\n\n");
	printf("输入0退出程序\n\n");
	printf("请输入你想使用功能对应的数字：");
	int a,b,c,d;
	scanf("%d",&a);
	if(a==1)
		{
			tnode *t;
			t=(tnode*)malloc(sizeof(tnode));
			xian(t);
		}//a==1
	else if(a==2)
		{tnode *t;
			zhong(t);
		}//a==2
	else if(a==3)
		{tnode *t;
			hou(t);
		}//a==3
 //	else if(a==4)
//		{tnode *t;
//			ceng(t);
//		}//a==4
 	else if(a==5)
		{
			jiedian();
		}//a==5
 	else if(a==6)
		{int i;tnode *t;
			yezi(i,t);
		}//a==6
 	else if(a==7)
		{
			width();
		}//a==7
 	else if(a==8)
		{
			depth();
		}//a==8
 	else if(a==9)
		{tnode *t,*t1;
			copybitree(t,t1);
		}//a==9
 	else if(a==10)
		{
			destroybitree();
		}//a==10
	else if(a==0)break;
	}//while


	return 0;
}
