#include <stdio.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct
{
	int row,col; 
	ElementType value;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];
	int rows,clos,nums;
}TSMatrix; 

TSMatrix Change(TSMatrix TS)
{
	int i,j,k;
	TSMatrix TS1;
	TS1.rows=TS.clos;
	TS1.clos=TS.rows;
	TS1.nums=TS.nums;
	if(TS1.nums>0)
	{
		j=1;
		for(k=1;k<=TS.clos;k++)
		{
			for(i=1;i<=TS.nums;i++)
			{
				if(TS.data[i].col==k)
				{
					TS1.data[j].row=TS.data[i].col;
					TS1.data[j].col=TS.data[i].row;
					TS1.data[j].value=TS.data[i].value;
					j++;
				}
			}
		}
	}
	for(i=1;i<=TS1.nums;i++)
	{
		printf("非零元素所在行数：%d\n非零元素所在列数：%d\n非零元素的值：%d\n\n",TS1.data[i].row,TS1.data[i].col,TS1.data[i].value);
	}
}
TSMatrix creat(TSMatrix TS1)
{
	TSMatrix TS;
	printf("请输入稀疏矩阵行数: ");
    scanf("%d",&TS.rows);
    printf("请输入稀疏矩阵列数: ");
    scanf("%d",&TS.clos);
    printf("请输入稀疏矩阵的非零元素个数:");
    scanf("%d",&TS.nums); 
	int i;
    printf("\n");
	for(i=1;i<=TS.nums;i++)
	{
		printf("请输入非零元素在稀疏矩阵中行数: ");
		scanf("%d",&TS.data[i].row);
		printf("请输入非零元素在稀疏矩阵中列数: ");
		scanf("%d",&TS.data[i].col);
		printf("请输入请输入非零元素的值: ");
		scanf("%d",&TS.data[i].value);
        printf("\n");
	}
	printf("\n");
	return TS;
}

TSMatrix add(TSMatrix TS1,TSMatrix TS2)
{
	int n,k,i;
	TSMatrix TS;
	if(TS1.clos!=TS2.clos||TS1.rows!=TS2.rows)
	{
		printf("矩阵不能相加\n");
	}
	else
	{
		for(n=1;n<=TS1.nums;n++)
		{
			for(k=1;k<=TS2.nums;k++)
			{
				if(TS1.data[n].row==TS2.data[k].row&&TS1.data[n].col==TS2.data[k].col)
				{
					TS1.data[n].value+=TS2.data[k].value;
					TS2.data[k].value=0;
				}
			}
		}
		for(k=1;k<=TS2.nums;k++)
		{
			if(TS2.data[k].value!=0)
			{
				TS1.data[TS1.nums+1].col=TS2.data[k].col;
				TS1.data[TS1.nums+1].row=TS2.data[k].row;
				TS1.data[TS1.nums+1].value=TS2.data[k].value;
				TS1.nums++;
			}
		}
	}
	for(i=1;i<=TS1.nums;i++)
	{
		printf("非零元素所在行数：%d\n非零元素所在列数：%d\n非零元素的值：%d\n\n",TS1.data[i].row,TS1.data[i].col,TS1.data[i].value);
	}
}

int main()
{
	TSMatrix TS,TS1,TS2;
    int i;
    printf("*******************************\n");
    printf("*        1:矩阵转置           *\n");
    printf("*        2:矩阵相加           *\n");
    printf("*        0.退出               *\n");
    printf("*******************************\n");
    printf("*     请依照功能选择按键      *\n");
    printf("*******************************\n");
    scanf("%d",&i);
    switch (i)
    {
        case 1:
            TS1=creat(TS);
            Change(TS1);
            break;
        case 2:
            TS1=creat(TS);
            TS2=creat(TS);
            add(TS1,TS2);  
        default:
            break;
    }
}
