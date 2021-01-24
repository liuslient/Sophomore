#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node,*Linktop;

typedef struct
{
	Linktop top;
	int count;
}LinkStack;

int Init(LinkStack *p);
int push(LinkStack *p,int n);
int output(LinkStack *p);

int main()
{
	LinkStack stack;
	Init(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	output(&stack);
	printf("\n");
	pop(&stack);
	output(&stack);	
}

int Init(LinkStack *p)
{
	if(p==NULL)
	{
		return 0;
	}
	p->top=NULL;
	p->count++;
}
int push(LinkStack *p,int n)
{
	Node *s=(Node *)malloc(sizeof(Node));
	s->data=n;
	s->next=p->top;
	p->top=s;
	p->count++;
}
int pop(LinkStack *p)
{
	Node *s=p->top;
	p->top=s->next;
	free(s);
	p->count--;
}
int output(LinkStack *p)
{
	Node *h=p->top;
	while(h)
	{
		printf("%d ",h->data);
		h=h->next;
	}
}
