#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} linklist;
linklist *creat();
void output(linklist *k);


int main()
{
	linklist *p;
	p=creat();
	output(p);
}
//头插法（带头节点）
/*
linklist *creat()
{
	linklist *head,*s;
	int n,i;
	head=(linklist*)malloc(sizeof(linklist));
	head->next=NULL;
	printf("请输入链表数据个数:\n");
	scanf("%d",&n);
	printf("请输入你的数据:\n");
	for(i=0;i<n;i++)
	{
		s=(linklist*)malloc(sizeof(linklist));
		scanf("%d",&s->data);
		s->next=head->next;
		head->next=s;
	}
	return head;
}
*/

//头插法（不带头节点）
/*
linklist *creat()
{
	linklist *head,*s;
        int n,i;
        head=(linklist*)malloc(sizeof(linklist));
        head->next=NULL;
	head->data=888;
        printf("请输入链表数据个数:\n");
        scanf("%d",&n);
        printf("请输入你的数据:\n");
        for(i=0;i<n-1;i++)
        {
                s=(linklist*)malloc(sizeof(linklist));
                scanf("%d",&s->data);
                s->next=head;
                head=s;
        }
        return head;
}
*/

//尾插法（带头节点）
/*
linklist *creat()
{
        linklist *head,*s,*end;
        int n,i;
        head=(linklist*)malloc(sizeof(linklist));
        head->next=NULL;
	end=head;
        printf("请输入链表数据个数:\n");
        scanf("%d",&n);
        printf("请输入你的数据:\n");
        for(i=0;i<n;i++)
        {
                s=(linklist*)malloc(sizeof(linklist));
                scanf("%d",&s->data);
                end->next=s;
		end=s;
        }
	end->next=NULL;
        return head;
}
*/
//尾插法（不带头节点）
linklist *creat()
{
        linklist *head,*s,*end;
        int n,i;
        head=(linklist*)malloc(sizeof(linklist));
        head->next=NULL;
	head->data=888;
        end=head;
        printf("请输入链表数据个数:\n");
        scanf("%d",&n);
        printf("请输入你的数据:\n");
        for(i=0;i<n-1;i++)
        {
                s=(linklist*)malloc(sizeof(linklist));
                scanf("%d",&s->data);
                end->next=s;
                end=s;
        }
        end->next=NULL;
        return head;
}



void output(linklist *k)
{
	while(k->next!=NULL)
	{
		k=k->next;
		printf("%d ",k->data);
	}
}
