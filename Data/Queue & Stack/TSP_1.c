#include<stdio.h>
#include<stdlib.h>
#define W 8
#define H 8
int book[H][W]={0};
int next[8][2]={{-2,1}, 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
	            
void dfs(int x,int y,int step)
{
	int i,j;
	
	if(step==W*H)
	{
		for(i=0;i<H;i++)
		{ 
			for(j=0;j<W;j++)
					printf("%4d",book[i][j]);
			 	printf("\n");
			} 
			printf("\n");
	}

	int k,tx,ty;
	for(k=0;k<8;k++)
	{
		tx = x+next[k][0];
		ty = y+next[k][1]; 
		
		if(tx<0||ty<0||tx>=H||ty>=W)
		{
			continue;
		}
		if(book[tx][ty]==0)
		{
			book[tx][ty]=step+1;
			dfs(tx,ty,step+1);
			
			book[tx][ty]=0;
		}
	}
	return;
}

int main()
{
	book[0][0]=1;
	dfs(0,0,1);
}
