#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[1000]={NULL},d[1000]={NULL};
	int k=0,i=0,n=0,m=0,j=0;
	printf("请输入字符串s:");
	for(i=0;(s[i]=getchar())!='\n';i++);
	
	for(i=1;s[i]!='!';i++)
	if(s[i]==s[i-1])k++;
	
	if(k==0)printf("\n无等值子串");
	else
	{
		for(i=0;s[i]!='!';i++)
		{
			if(s[i]==s[i+1])
			{
				for(j=i;s[j+1]==s[j];j++);
				if(n<j-i+1)	n=j-i+1;
			
			}
		}
		for(i=0;s[i]!='!';i++)
		{
			if(s[i]==s[i+1])
			{
				for(j=i;s[j+1]==s[j];j++);
				if(j-i+1==n)
				{
                printf("一个长度最大的等值子串:");
				for(k=i;s[k+1]==s[k];k++)
				printf("%c",s[k]);
				printf("%c",s[k-1]);
				m++;
				}
			if(m!=0)break;
			}
		}
		printf("\n%d",n);
		
	}
	
	
	return 0;
}
