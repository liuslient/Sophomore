#include<stdio.h>

void get_next(char *str2,int *next)
{
	int i,j;
	i=0;
	j=-1;
	next[0]=-1;
	while(str2[i])
	{
		if(j==-1||str2[i]==str2[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}

int KMP(char *str1,char *str2)
{
	int i=0;
	int j=0;
	int next[255];
	get_next(str2,next);
	while(str1[i]&&str2[j]||j==-1)
	{
		if(j==-1||str1[i]==str2[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(str2[j]==0)
		return i-j;
	else
		return -1;
}


int main()
{
	char str1[100];
	char str2[20];
	int a;
	printf("输入主串:\n");
	gets(str1);
	printf("输入子串:\n");
	gets(str2);
	a=KMP(str1,str2);
	printf("%d",a);
}
