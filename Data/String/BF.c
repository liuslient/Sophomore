#include<stdio.h>
int BF(char *S,char *T);
//返回字串在主串中能匹配的第一个位置 
int BF(char *S,char *T)
{
	int i=0;
	int j=0;
	while(S[i]&&T[j])
	{
		if(S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;
			j=0;
		}
	}
	if(T[j]==0)
	    return i-j;
	else
	    return -1;
}


int main()
{
	char str1[100];
	char str2[20];
	int a;
	printf("输入主串\n");
	gets(str1);
	printf("输入子串\n");
	gets(str2);
	a=BF(str1,str2);
	printf("%d",a);
}


