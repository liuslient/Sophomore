#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node,*Queueptr;

typedef struct
{
	Queueptr front,rear;
} LinkQueue;

int Init(LinkQueue *p)
{
	p->front=p->rear=(Node *)malloc(sizeof(Node));
	if(p->front==NULL)
	{
		return 0;
	}
	p->front->next=NULL;
}

int EnQueue(LinkQueue *p,int n)
{
	Node *s=(Node *)malloc(sizeof(Node));
	s->data=n;
	s->next=NULL;
	p->rear->next=s;
	p->rear=s;
}

int DeQueue(LinkQueue *q)
{
	Node *p;
	if(q->front==q->rear)
	{
		return 0;
	}
	p=q->front->next;
	q->front->next=p->next;
	if(q->rear=p)
	{
		q->rear=q->front;
	}
	free(p);
	return 1;	
}

int output(LinkQueue *p)
{
	Node *s;
	s=p->front->next;
	while(s)
	{
		printf("%d ",s->data);
		s=s->next;
	}
}

int main()
{
	LinkQueue ph;
	Init(&ph);
	EnQueue(&ph,1);
	EnQueue(&ph,2);
	EnQueue(&ph,3);
	output(&ph);
	printf("\n");
	DeQueue(&ph);
	output(&ph);
}
