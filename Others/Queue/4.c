#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct Node 
{
	int data;//结点数据域
	struct Node* next;//结点指针域
} Node,*Linktop;
 
//链栈的数据结构
typedef struct
{
	Linktop top;   //栈顶结点,指向上个结构体的指针
	int count;//元素个数
}LinkStack;

int output(LinkStack* stack);
int InitLink(LinkStack* stack);
int push(LinkStack *ph,int n);
int pop(LinkStack *ph,int *n);

int main()
{
	LinkStack stack;
	InitLink(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	output(&stack);
}

int output(LinkStack* stack)
{
	Node *p=stack->top;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int InitLink(LinkStack* stack)
{
	if(stack==NULL)
	{
		return 0;
	}
	stack->top=NULL;
	stack->count++;
}

int push(LinkStack *ph,int n)
{
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=n;
	p->next=ph->top;
	ph->top=p;
	ph->count++;
	return 1;
}

int pop(LinkStack *ph,int *n)
{
	Node *p=ph->top;
	*n=p->data;
	ph->top=p->next;
	free(p);
	ph->count--;
	return 1;
}
