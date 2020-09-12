#include<stdio.h>

int main()
{
	int tmp[10],n,i,j;
	printf("请输入8个数:");
	for(i=0;i<8;i++)
	{
		scanf("%d",&tmp[i]);
	}
	printf("请输入要查的数:");
	scanf("%d",&n);
	for(j=0;j<i;j++)
	{
		if(n==tmp[j])
		{
			printf("%d",n);
		}
	}

}
