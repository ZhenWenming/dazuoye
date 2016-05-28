#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N[10]={0};
int I=1;
int max=0;

typedef struct Node
{
   char data;
   struct Node *LChild;
   struct Node *RChild;
}TreeLink,*BTreeLink;

typedef struct node
{
	BTreeLink tree;
	struct node *next;

}Qnode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void initQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(Qnode));
	Q.front->next=Q.rear->next=NULL;
}

void enQueue(LinkQueue &Q, BTreeLink d)
{
    QueuePtr node = (QueuePtr)malloc(sizeof(Qnode));
    node->tree = d;
    node->next = NULL;
    Q.rear->next = node;
    Q.rear = node;
}

BTreeLink deQueue(LinkQueue &Q)
{
	BTreeLink t;
    QueuePtr node = Q.front->next;
    t = node->tree;
    Q.front->next = node->next;
    if(node->next==NULL)
	{
        Q.rear = Q.front;
    }
    free(node);
    return t;
}

void CreateBTree(BTreeLink &B)
{
	char ch;
	printf("输入该结点元素值(若没有则输入#)：");
	scanf("%c",&ch);
	getchar();
	if(ch!='#')
	{
		B=(BTreeLink)malloc(sizeof(BTreeLink));
		B->data=ch;
		B->LChild=NULL;
		B->RChild=NULL;
		printf("\n递归至左孩子\n");
		CreateBTree(B->LChild);
		printf("\n递归至右孩子\n");
		CreateBTree(B->RChild);
	}
}

//求二叉树的结点个数
int CountBTreeNode(BTreeLink B)
{
	int CountLChild, CountRChild;
	int Count;
	if(B==NULL)
	{
		return 0;
	}
	else
	{
		CountLChild=CountBTreeNode(B->LChild);
		CountRChild=CountBTreeNode(B->RChild);
		Count=CountLChild+CountRChild+1;
	}
}

//二叉树的高度
int BTreeDepth(BTreeLink B)
{
    int Lchild_h, Rchild_h;
	int Max;
	if(B==NULL)
	{
		return 0;
	}
	else
	{
		Lchild_h=BTreeDepth(B->LChild);
		Rchild_h=BTreeDepth(B->RChild);
		if(Lchild_h>Rchild_h)
		{
			Max=Lchild_h+1;
		}
		else
		{
			Max=Rchild_h+1;
		}
		return Max;
	}
}

//二叉树的宽度
int BTreeWidth(BTreeLink T)
{
	if(T)
	{
		if(I==1)
		{
			N[I]++;
			I++;
			if(T->LChild)N[I]++;
			if(T->RChild)N[I]++;
		}
		else
		{
			I++;
			if(T->LChild)N[I]++;
			if(T->RChild)N[I]++;
		}
		if(max<N[I])max=N[I];
		BTreeWidth(T->LChild);
		I--;
		BTreeWidth(T->RChild);
	}
	return max;
}

//二叉树的叶子结点个数
int CountLeafNode(BTreeLink B)
{
	int Count, CountLeft, CountRight;
	if(B==NULL)
	{
		return 0;
	}
	else
	{
		if(B->LChild==NULL&&B->RChild==NULL)
		{
			return 1;
		}
		CountLeft=CountLeafNode(B->LChild);
		CountRight=CountLeafNode(B->RChild);
		Count=CountLeft+CountRight;
		return Count;
	}
}

//先序遍历
void PreorderTraversalBTree(BTreeLink B)
{
	if(B!=NULL)
	{
		printf("%c ",B->data);
		PreorderTraversalBTree(B->LChild);
		PreorderTraversalBTree(B->RChild);
	}
}

//中序遍历
void InorderTraversalBTree(BTreeLink B)
{
	if(B!=NULL)
	{
		InorderTraversalBTree(B->LChild);
		printf("%c ",B->data);
		InorderTraversalBTree(B->RChild);
	}
}

//后序遍历
void PostorderTraversalBTree(BTreeLink B)
{
	if(B!=NULL)
	{
		PostorderTraversalBTree(B->LChild);
		PostorderTraversalBTree(B->RChild);
		printf("%c ", B->data);
	}
}

//层序遍历
void ceng(BTreeLink B)
{
	int num=0,num1;
	LinkQueue Q;
	initQueue(Q);
	BTreeLink t;
	num1=CountBTreeNode(B);
	enQueue(Q,B);
	while(num!=num1)
	{
		t=deQueue(Q);
		printf("%c ",t->data);
		num++;
		if(t->LChild)
		enQueue(Q,t->LChild);
		if(t->RChild)
		enQueue(Q,t->RChild);
	}
}

//复制
void copy(BTreeLink B,BTreeLink &T)
{
	char ch;
	if(B!=NULL)
	{
		ch=B->data;
		T=(BTreeLink)malloc(sizeof(BTreeLink));
		T->data=ch;
		T->LChild=NULL;
		T->RChild=NULL;
		copy(B->LChild,T->LChild);
		copy(B->RChild,T->RChild);
	}
}

//销毁
void DestroyBiTree(BTreeLink &T)
{
	if(T)
	{
		if(T->LChild)
		{
			DestroyBiTree(T->LChild);
		}
		if(T->RChild)
		{
			DestroyBiTree(T->RChild);
		}
		free(T);
		T=NULL;
	}
}

int main()
{
    BTreeLink B[10]={0};
    int num;
    int i,n,m;
    int h,w,count,NumberLeaf;
	printf("0.退出\n1.创建二叉树\n2.遍历二叉树\n3.二叉树的计算\n4.复制二叉树\n5.销毁二叉树\n");
	printf("\n");

	while(1)
	{
		printf("输入上述所要实现功能的序号：");
		scanf("%d",&num);

    	if(num==1)
    	{
    		getchar();
    		printf("输入你要创建二叉树的编号：");
    		scanf("%d",&n);
    		getchar();
    		printf("开始创建二叉树%d:\n",n);
			CreateBTree(B[n-1]);
			printf("\n");
		}
		else if(num==2)
		{
			getchar();
    		printf("输入你要遍历的树的编号:");
    		scanf("%d",&n);
    		getchar();
			printf("\n先序遍历该二叉树：");
			PreorderTraversalBTree(B[n-1]);
			printf("\n\n");
			printf("中序遍历该二叉树：");
			InorderTraversalBTree(B[n-1]);
			printf("\n\n");
			printf("后序遍历该二叉树：");
			PostorderTraversalBTree(B[n-1]);
			printf("\n\n");
			printf("层序遍历该二叉树：");
			ceng(B[n-1]);
			printf("\n\n");
		}

		else if(num==3)
		{
			for(i=0;i<10;i++)
			{
				N[i]=0;
			}
			I=1;
			max=0;

			getchar();
			printf("输入你要计算的树的编号: ");
    		scanf("%d",&n);
    		getchar();

    		printf("\n当前二叉树的高度: ");
			h=BTreeDepth(B[n-1]);
			printf("%d",h);

			printf("\n\n当前二叉树的宽度: ");
			w=BTreeWidth(B[n-1]);
			printf("%d",w);

			printf("\n\n目前二叉树的结点个数: ");
			count=CountBTreeNode(B[n-1]);
			printf("%d",count);

			NumberLeaf=CountLeafNode(B[n-1]);
			printf("\n\n二叉树的叶子结点个数: %d",NumberLeaf);
			printf("\n\n");
		}

		else if(num==4)
		{
			getchar();
			printf("输入你要复制的树的编号（从哪棵到哪棵）:");
			scanf("%d%d",&n,&m);
			copy(B[n-1],B[m-1]);
			printf("复制完毕");
			printf("\n\n");
		}

		else if(num==5)
		{
			getchar();
			printf("输入你要销毁的树的编号:");
    		scanf("%d",&n);
    		DestroyBiTree(B[n-1]);
    		printf("该树已销毁\n\n");
		}

		else if(num==0)
		{
			return 0;
		}
	}
	return 0;
}
