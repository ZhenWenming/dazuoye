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
	printf("�������ַ�������#������:");
	InvertStore(a);
	printf("���������洢���ַ�����");
	printf("%s",a);
	return 0;
}
