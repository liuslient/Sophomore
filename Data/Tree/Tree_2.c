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

int n=0;//定义一个全局变量，用来计算叶子结点

Stack *initstack()
{
	Stack *s;
	s=(Stack *)malloc(sizeof(Stack));
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

int GetTop(Stack *s,Type *e)
{
    if(s->top==-1)
    {
        return 0;
    }
    else
    {
        *e=s->data[s->top];
        return 1;
    }
    
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

void PreOrder_Stack(BITree root){
	BITree p;
	Stack *S;
	S = initstack();
	p = root;
	while(p!=NULL||Empty(S)==0){
		
		while(p!=NULL){     
			printf("%c",p->data); 
			push(S,p); 
			p=p->lchild;
		}
		if(Empty(S)==0){
			pop(S,&p);
			p=p->rchild;
		} 
		
	}	
}

void InOrder(BITree root){
	if(root==NULL)
		return;
	InOrder(root->lchild);
    printf("%c",root->data);
	InOrder(root->rchild);
}

void InOrder_Stack(BITree root){
	BITree p;
	Stack *S;
	S = initstack();
	p = root;
	while(p!=NULL||Empty(S)==0){
		
		while(p!=NULL){      
			push(S,p);
			p=p->lchild; 
		}
		if(Empty(S)==0){
			pop(S,&p);
            printf("%c",p->data);
			p=p->rchild;
		} 
		
	}	
}

void PostOrder(BITree root){
	if(root==NULL)
		return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
    printf("%c",root->data);
}

void PostOrder_Stack(BITree root){
	BITree p,q;
	Stack *S;
	S = initstack();
	q = NULL;
	p = root;
	while(p!=NULL||Empty(S)==0){
		while(p!=NULL){ 
			push(S,p);  
			p=p->lchild; 
		}
		if(Empty(S)==0){
			GetTop(S,&p);
			if(p->rchild==NULL||p->rchild==q){ 
				pop(S,&p);
				printf("%c",p->data);
				q=p;
				p=NULL; 
			}else{ 
				p=p->rchild;
			}
		}
	
	}
	
} 
void leafcount(BITree root){
    if (root!=NULL)
    {
        if(root->lchild==NULL&&root->rchild==NULL)
        {
            n++;
        }
        leafcount(root->lchild);
        leafcount(root->rchild);
    }
    
}
int Depth(BITree root){
    int i,j,k;
    if (root!=NULL)
    {
        i=Depth(root->lchild);
        j=Depth(root->rchild);
        k=i>j?i:j;
        return k+1;
    }else
    {
        return 0;
    } 
}

int main()
{
	BITree h1;
	creatBiTree(&h1);
    printf("前序遍历\n");
	PreOrder(h1);
	printf("\n");
	printf("中序遍历\n");
    InOrder(h1);
	printf("\n");
	printf("后序遍历\n");
    PostOrder(h1);
	printf("\n");
	printf("前序遍历(非递归)\n");
    PreOrder_Stack(h1);
	printf("\n");
	printf("中序遍历(非递归)\n");
    InOrder_Stack(h1);
	printf("\n");
	printf("后序遍历(非递归)\n");
    PostOrder_Stack(h1);
	printf("\n");
    leafcount(h1);
    printf("统计叶子节点:%d\n",n);
    printf("二叉树深度：%d",Depth(h1));
}
