#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define H 8
#define W 8 
typedef struct
{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAX];
	int top;
} Stack;

Stack *init()
{
	Stack *s;
	s=(Stack *)malloc(sizeof(Stack));
	s->top=-1;
	return s;
}

int push(Stack *s,Elemtype e)
{
	if(s->top==MAX-1)
	{
		return 0;
	}
	s->top++;
	s->data[s->top]=e;
	return 1;
}

int pop(Stack *s,Elemtype *e)
{
	if(s->top==-1)
	{
		return 0;
	}
	*e=s->data[s->top];
	s->top--;
	return 1;
}

Stack *S;

int book[W][H]={0};
int next[8][2]={{-2,1}, 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
	        
void dfs(Elemtype e)
{
	int k,step=1;
	Elemtype e1=e,e2;
	e1.direction=0;
	
	while(step!=64)
	{
		for(k=e1.direction;k<8;k++)
		{
			e2.x=e1.x+next[k][0];
			e2.y=e1.y+next[k][1];
			e1.direction=k;
			if(e2.x<0||e2.x>=H||e2.y<0||e2.y>=W)
				continue;
			if(book[e2.x][e2.y]==0)
			{
				book[e1.x][e1.y]=step;
				push(S,e1);
				e1=e2;
				e1.direction=0;
				step++;
				break;
			}
		}
		if(k==8)
		{
			pop(S,&e1);
			book[e1.x][e1.y]=0; 
			step--;
			e1.direction++;
		}
	}
	book[e1.x][e1.y]=step;
	
	int i,j;
	if(step==W*H)
	{
		for(i=0;i<H;i++){ 
			for(j=0;j<W;j++)
				printf("%4d",book[i][j]);
		 	printf("\n");
		} 	
	}
}

    
int main()
{
	Elemtype e;
	S=init();
	printf("请输入起点坐标：\n");
	printf("X=");  
    scanf("%d", &e.x);  
    printf("Y="); 
    scanf("%d", &e.y);
	dfs(e);
}
