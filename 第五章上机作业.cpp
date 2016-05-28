#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 500
typedef struct{
	int i,j;
	int e;
}triple;

typedef struct{
	triple data[maxsize+1];
	int rpos[30];
	int mu,nu,tu;
}mat;

void createmat(mat &x)
{
	int h,k,q,p;
	printf("\n请输入当前矩阵的非零元数：");
	scanf("%d",&x.tu);
	printf("请以三元组的形式按行序输入该矩阵(每行一个三元组)：");
    for(k=1;k<=x.tu;k++)
    scanf("%d %d %d",&x.data[k].i,&x.data[k].j,&x.data[k].e);
}

void printmat(mat x)
{
	int h,k=1,p,q;
	int gg[25][25]={0};
	for(k=1;k<=x.tu;k++)
		gg[x.data[k].i][x.data[k].j]=x.data[k].e;
	for(k=1;k<=x.mu;k++)
		{
		for(h=1;h<=x.nu;h++) printf("%d ",gg[k][h]);
		printf("\n");
		}
	printf("\n");
}

void addmat(mat x,mat y,mat &z)
{
	createmat(x);

	createmat(y);

	z.mu=x.mu;z.nu=x.nu;z.tu=0;
	int k,ce=0;
	int pa=1,pb=1,pc=1;
	for(k=1;k<=x.mu;k++)
	{
		while(x.data[pa].i<k)pa++;
		while(y.data[pb].i<k)pb++;
		while(x.data[pa].i==k&&y.data[pb].i==k)//行列值都相等的元素
		{
			if(x.data[pa].j==y.data[pb].j)
			{
				ce=x.data[pa].e+y.data[pb].e;
				if(ce)//和不为0
				{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=ce;
					pa++;pb++;pc++;
				}
				else
				{
					pa++;
					pb++;
				}
			}//if
			else if(x.data[pa].j>y.data[pb].j)
			{
					z.data[pc].i=k;
					z.data[pc].j=y.data[pb].j;
					z.data[pc].e=y.data[pb].e;
					pb++;pc++;
			}
			else
			{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=x.data[pa].e;
					pa++;pc++;
			}
        }//while
			while(x.data[pa].i==k)//插入x中剩余的元素(第k行)
			{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=x.data[pa].e;
					pa++;pc++;
			}
			while(y.data[pb].i==k)//插入y中剩余的元素(第k行)
			{
					z.data[pc].i=k;
					z.data[pc].j=y.data[pb].j;
					z.data[pc].e=y.data[pb].e;
					pb++;pc++;
			}
	}//for
	z.tu=pc;
	printf("现在我们得到了结果（阵列形式）：\n");
	printmat(z);
}

void subtmat(mat x,mat y,mat &z)
{
	createmat(x);

	createmat(y);

	z.mu=x.mu;z.nu=x.nu;z.tu=0;
	int k,h,r,ce=0;
	int pa=1,pb=1,pc=1;
	for(k=1;k<=x.mu;k++)
	{
		while(x.data[pa].i<k)pa++;
		while(y.data[pb].i<k)pb++;
		while(x.data[pa].i==k&&y.data[pb].i==k)//行列值都相等的元素
		{
			if(x.data[pa].j==y.data[pb].j)
			{
				ce=x.data[pa].e-y.data[pb].e;
				if(ce)//差不为0
				{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=ce;
					pa++;pb++;pc++;
				}
				else
				{
					if(pa<x.tu)pa++;
					if(pb<y.tu)pb++;
				}
			}//if
			else if(x.data[pa].j>y.data[pb].j)
			{
					z.data[pc].i=k;
					z.data[pc].j=y.data[pb].j;
					z.data[pc].e=y.data[pb].e;
					pb++;pc++;
			}
			else
			{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=x.data[pa].e;
					pa++;pc++;
			}
        }//while
			while(x.data[pa].i==k)//插入x中剩余的元素(第k行)
			{
					z.data[pc].i=k;
					z.data[pc].j=x.data[pa].j;
					z.data[pc].e=x.data[pa].e;
					pa++;pc++;
			}
			while(y.data[pb].i==k)//插入y中剩余的元素(第k行)
			{
					z.data[pc].i=k;
					z.data[pc].j=y.data[pb].j;
					z.data[pc].e=-y.data[pb].e;
					pb++;pc++;
			}
	}//for
	z.tu=pc;
	printf("现在我们得到了结果（阵列形式）：\n");
	printmat(z);
}



void colnum(mat &x)
{
	int num[500]={0},k=0,col=0,p=0,q=0;
	if(x.tu)
	{
		for(k=1;k<=x.tu;++k) ++num[x.data[k].i];
		x.rpos[1]=1;
		for(col=2;col<=x.mu;++col)x.rpos[col]=x.rpos[col-1]+num[col-1];
	}
}

void multmat(mat x,mat y,mat &z)
{
	createmat(x);
		colnum(x);
	createmat(y);
		colnum(y);
	z.mu=x.mu;z.nu=y.nu;z.tu=0;
	int arow=0,brow=0,crow=0,ccol=0,tp=0,t=0,q=0,p=0;
	int h=0;
	int ctemp[500]={0};
	if(x.tu*y.tu!=0)
	{
		for(arow=1;arow<=x.mu;++arow)
		{
			for(h=0;h<=22;h++)ctemp[h]=0;//当前行各元素累加器清零
			z.rpos[arow]=z.tu+1;
			if(arow<x.mu)tp=x.rpos[arow+1];
			else{tp=x.tu+1;}
			for(p=x.rpos[arow];p<tp;++p)
			{
				brow=x.data[p].j;
				if(brow<y.mu)t=y.rpos[brow+1];
				else t=y.tu+1;
				for(q=y.rpos[brow];q<t;++q)
				{
					ccol=y.data[q].j;
					ctemp[ccol]+=x.data[p].e*y.data[q].e;
				}//for q
			}//求得z中第crow（=arow）行的非零元
        for(ccol=1;ccol<=z.nu;++ccol)
			if(ctemp[ccol])
			{
				if(++z.tu>maxsize)printf("抱歉，矩阵的乘积越界");
				z.data[z.tu].i=arow;
				z.data[z.tu].j=ccol;
				z.data[z.tu].e=ctemp[ccol];
			}//if
		}//for arow
	}//if
	printf("现在我们得到了结果（阵列形式）：\n");
	printmat(z);
}

int main()
{
	printf("**********************************************************\n");
	printf("                     稀疏矩阵运算器                       \n");
	printf("**********************************************************\n");
	int a=-1;
	while(a)
	{
	printf("功能列表\n\n");
	printf("1.两个矩阵相加\n");
	printf("2.两个矩阵相减\n");
	printf("3.两个矩阵相乘\n\n");
	printf("输入0退出程序\n\n");
	printf("请输入你想使用功能对应的数字：");
	int a,b,c,d;
	scanf("%d",&a);
	if(a==1)
		{
			mat x,y,z;
			printf("请输入第一个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&x.mu,&x.nu);
			printf("请输入第二个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&y.mu,&y.nu);
			if(x.nu!=y.nu||x.mu!=y.mu)printf("两个矩阵不匹配，无法相加\n\n");
			else	addmat(x,y,z);
		}//a==1
	else if(a==2)
		{
			mat x,y,z;
			printf("请输入第一个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&x.mu,&x.nu);
			printf("请输入第二个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&y.mu,&y.nu);
			if(x.nu!=y.nu||x.mu!=y.mu)printf("两个矩阵不匹配，无法相减\n\n");
			else	subtmat(x,y,z);
		}//a==2
	else if(a==3)
		{
			mat x,y,z;
			printf("请输入第一个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&x.mu,&x.nu);
			printf("请输入第二个矩阵的行数和列数（不超过20）：");
			scanf("%d %d",&y.mu,&y.nu);
			if(x.nu!=y.mu)printf("两个矩阵不匹配，无法相乘\n\n");
			else	multmat(x,y,z);
		}//a==3
	else if(a==0)break;
	}//while
	return 0;
}
