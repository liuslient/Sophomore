#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef char BItype;
typedef struct Node
{
	BItype data;
	struct Node *lchild;
	struct Node *rchild;
}BiNode,*BITree;

typedef BITree Type;
typedef struct 
{
	Type data[MAX];
	int top;
} Stack;

Stack *initstack()
{
	Stack *s;
	s=malloc(sizeof(Stack));
	s->top=-1;
	return s;
}

int Empty(Stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int push(Stack *s,Type e)
{
	if (s->top==MAX-1)
	{
		return 0;
	}
	s->top++;
	s->data[s->top]=e;
	return 1;
}

int pop(Stack *s,Type *e)
{
	if(s->top==-1)
	{
		return 0;
	}
	*e=s->data[s->top];
	s->top--;
	return 1;
}

void creatBiTree(BITree *root)
{
	BItype ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		*root=NULL;
	}
	else
	{
		*root=(BITree )malloc(sizeof(BiNode));
		if(!*root)
		{
			exit(-1);
		}
		(*root)->data=ch;
		creatBiTree(&(*root)->lchild);
		creatBiTree(&(*root)->rchild);
	}
}

void PreOrder(BITree root){
	if(root==NULL)
		return;
		
	printf("%c",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}


int main()
{
	BITree h1;
	creatBiTree(&h1);
	PreOrder(h1);
}
