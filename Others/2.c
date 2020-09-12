#include<stdio.h>

int main()
{
        int tmp[10],n,i,j;
        printf("请输入8个数:");
        for(i=0;i<8;i++)
        {
                scanf("%d",&tmp[i]);
        }
        
        
        for(j=0;j<8;j++)
        {
               for(i=0;i<7-j;i++)
	       {
		       if(tmp[j]>tmp[j+1])
		       {
			       n=tmp[j+1];
			       tmp[j+1]=tmp[j];
			       tmp[j]=n;
		       }
	       }
        }
	printf("%d  %d",tmp[7],tmp[6]);

}

