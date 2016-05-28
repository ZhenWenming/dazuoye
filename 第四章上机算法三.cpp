#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void InvertStore(char A[])
{
	char ch;
	static int i =0;
	scanf("%c",&ch);
	if(ch!='#')
	{
		InvertStore(A);
		A[i]=ch;
		i++;
	}
	A[i]='\0';
}

int main()
{
	char a[5000]={NULL};
	printf("请输入字符串（以#结束）:");
	InvertStore(a);
	printf("这就是逆序存储的字符串：");
	printf("%s",a);
	return 0;
}
