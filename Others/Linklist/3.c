#include <stdio.h>
#include <stdlib.h>

typedef struct line 
{
    struct line * prior;
    int data;
    struct line * next;
}line;
line* initLine(line * head);
void display(line * head);

int main() 
{
    line * head = NULL;
    head = initLine(head);
    display(head);
    return 0;
}
//创建双向循环链表
line* initLine(line * head) 
{
    int i = 0;
    line * list = NULL;
    head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    list = head;
    for (i = 2; i <= 3; i++) 
	{
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;
        list->next = body;
        body->prior = list;
        list = list->next;
    }
    list->next = head;
    head->prior = list;
    return head;
}
//链表的删除
void deletlist(line *head,int n)
{
	line *list=head;
	while(list->next&&i<n)
	{
		list=list->next;
		i++;'
	}

}
//链表的插入
//链表的逆置



//输出链表的功能函数
void display(line * head) 
{
    line * temp = head;
    while (temp->next != head) 
	{
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
