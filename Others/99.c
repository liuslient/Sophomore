#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
    int pwd;
    int num;
    struct Node *next;
}Node,*LinkList;

LinkList CreateList(int n,Node *L)
{
    LinkList p,s;
    int i;
    s=L;
    for(i=1;i<=n;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        p->num=i;
        scanf("%d",&p->pwd);
        s->next=p;
        s=p;
    }
    L=L->next;
    s->next=L;
    return L;
}

void OutputList(int m,int n,Node* L)
{
    LinkList p;
    int h,i;
    p=L;
    for(i=1;i<m;i++)
      p=p->next;
    while(n)
    {
        h=p->next->pwd;
        printf("%d ",p->next->num);
        p->next=p->next->next;
        for(i=1;i<h;i++)
            p=p->next;
        n--;
    }
}

int main()
{
    Node L;
    int m,n;
    scanf("%d",&n);
    scanf("%d",&m);
    CreateList(n,&L);
    OutputList(m,n,&L);
}
