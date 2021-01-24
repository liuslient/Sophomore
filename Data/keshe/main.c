#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int a, b, flag1, c, d, e;
tree *p, *q;
int point;

void chu()
{
    flag1 = 0;//标记变量
    c = 0;//标记变量
    d = 0;//标记变量
    e = 0;//标记变量
    a = 0;//标记name1的辈份
    b = 0;//标记name2的辈份
    p = NULL;
    q = NULL;
}

int find(tree *root, char name[])
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, name) == 0)//找到
        {
            printf("--------------------------------------------------\n");
            printf("姓   名：%s\n", name);
            printf("性   别：%c\n", root->sex);
            printf("辈   份：%d\n", root->degree);
            printf("子女数量：%d\n", root->num);
            if(strcmp(root->fathername, "wu") == 0)//成员为祖先
            {
                printf("没有父亲信息!\n");
            }
            else
            {
                printf("父亲姓名：%s\n", root->fathername);
            }
            printf("--------------------------------------------------\n");
            c = 1;
            p = root;
            return 1;
        }
        else
        {
            find(root->child, name);//递归查找左孩子
            find(root->brother, name);//递归查找右兄弟
        }
    }
    if(c == 0)
    {
        return 0;
    }
}

int find_parent(tree *root, char parent[])
{
    if(root == NULL || root->child == NULL)//递归边界
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, parent) == 0)//找到
        {
            printf("%s一共有%d个孩子\n", root->name, root->num);
            tree *p = root->child;
            printf("################\n");
            find(p, p->name);//第一个孩子信息
            tree *q = p->brother;
            while(p->brother)
            {
                printf("################\n", c);
                find(q, q->name);//孩子的兄弟信息
                p = q;//name1的辈份大于name2的辈份
                q = q->brother;
            }
            d = 1;
            return 1;
        }
        find_parent(root->child, parent);//递归查找左孩子
        find_parent(root->brother, parent);//递归查找右兄弟
    }
    if(d == 0)
    {
        return 0;
    }
}

int find_connect(tree *root, char name1[], char name2[])
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, name1) == 0)//找到name1
        {
            a = root->degree;//记录name1辈份
            p = root;//记录name1位置;

        }
        else if(strcmp(root->name, name2) == 0)//找到name2
        {
            b = root->degree;//记录name2辈份
            q = root;//记录name2位置
        }
        find_connect(root->child, name1, name2);//递归查找左孩子
        find_connect(root->brother, name1, name2);//递归查找右兄弟
    }
    if(a != 0 && b != 0)
    {
        printf("--------------------------------------------------\n");
        if(a < b)//name1的辈份大于name2的辈份
        {
            printf("%s是长%s %d代的长辈\n", name1, name2, b-a);
        }
        else if(a > b)//name1的辈份小于name2的辈份
        {
            printf("%s是小%s %d代的晚辈\n", name1, name2, a-b);
        }
        else
        {
            if(strcmp(p->fathername, q->fathername) == 0)//是同一父亲
            {
                printf("%s和%s是亲兄弟\n", name1, name2);
            }
            else
            {
                while(strcmp(p->fathername, q->fathername) != 0)//一直到p和q是一个父亲为止
                {
                    p = p->parent;
                    q = q->parent;
                    e++;//记录相隔几代
                }
                printf("%s和%s是相隔%d代的堂兄弟\n", name1, name2, e);
            }
        }
        printf("--------------------------------------------------\n");
        a = 0;
        b = 0;
        c = 1;
        return 1;
    }
    if(c == 0)
        return 0;
}

int find_same_class(tree *root, int class_num)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(root->degree == class_num)//找到这个辈份的人
        {
            find(root, root->name);//输出信息
            flag1 = 1;//标记有该辈份的人
        }
        find_same_class(root->child, class_num);//递归查找左孩子
        find_same_class(root->brother, class_num);//递归查找右孩子
    }
    if(flag1 == 0)//没有找到过该辈份的人
    {
        return 0;
    }
}

void find_three(tree *root, char name[])
{
    tree *r;
    printf("--------------------------------------------------\n");
    printf("此人信息：\n");
    chu();
    if(!find(root, name))
    {
        printf("没有此人信息！\n");
        return;
    }
    printf("--------------------------------------------------\n");
    printf("%s父亲信息：\n", name);
    r = p;
    chu();
    if(!find(root, r->fathername))
    {
        printf("没有此人信息！\n");
    }
    chu();
    printf("--------------------------------------------------\n");
    printf("%s孩子信息:\n");
    if(!find_parent(root, name))
    {
        printf("没有此人信息！\n");
    }
    printf("--------------------------------------------------\n");
}

tree *find_point(tree *root, char name[])
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(strcmp(root->name, name)==0)//查找成功
        {
            p = root;
        }
        else
        {
            find_point(root->child, name);
            find_point(root->brother, name);
        }
    }
    return p;
}

void create(tree *root)
{
    printf("*************请输入祖先的姓名、性别：**************\n");
    scanf("%s %c", root->name, &root->sex);
    if(strlen(root->name) > 12)                  //判断输入长度是否合法
    {
        printf("您输入的名字长度太长！\n");
        return;
    }
    strcpy(root->fathername, "wu");
    root->num = 0;
    root->degree = 1;
    root = (tree *)malloc(sizeof(struct treenode));  //新建根结点
    root->child = NULL;
    root->parent = NULL;
    root->brother = NULL;
    printf("*************家谱树创建成功**************\n");
}

void add(tree *root, char Name[], char father_name[], char Sex, int *flag)
{
    tree *p, *q;
    if(strlen(Name) > 12)
    {
        printf("您输入的名字长度太长！\n");
        printf("添加成员失败！\n");
        *flag = 0;
        return;
    }
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);              //更新成员以及父亲信息
    strcpy(p->fathername, father_name);
    if(root == NULL)
    {
        return ;
    }
    if(strcmp(root->name, p->fathername) == 0)   //找到父亲
    {
        *flag = 1;
        p->degree = root->degree+1;         //更新辈份
        if(root->child == NULL)              //左孩子为空直接添加为左孩子
        {
            root->child = p;
            root->num++;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
        }
        else                    //不为空添加在兄弟结点上
        {
            q = root->child;
            while(q->brother)
            {
                q = q->brother;
            }
            q->brother = p;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
            root->num++;
        }
        return ;
    }
    add(root->child, Name, father_name, Sex, flag);              //递归寻找创建
    add(root->brother, Name, father_name, Sex, flag);
}

tree *add_zuxian(tree *root, char Name[], char Sex)
{
    if(strlen(Name) > 12)
    {
        printf("您输入的名字长度太长！\n");
        return 0;
    }
    tree *p;
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);
    strcpy(p->fathername, "wu");
    p->degree = 1;          //更改祖先的个人信息
    p->brother = NULL;
    p->parent = NULL;
    p->child = root;
    p->num = 1;
    root->parent = p;
    strcpy(root->fathername, Name);
    change_degree(root);    //每个人的辈份降低
    printf("添加祖先成功！\n");
    root = p;
    return p;
}

void change_degree(tree *root)
{
    if(root == NULL)    
    {
        return;
    }
    else
    {
        root->degree++;        //每个人的辈份降低
    }
    change_degree(root->child);   //递归更改辈份
    change_degree(root->brother);
}

void recreate(tree **root, char Name[], char Sex)
{
	printf("进了重构函数\n");
	*root = (tree *)malloc(sizeof(struct treenode));  //新建根结点
	(*root)->sex = Sex;
	strcpy((*root)->name, Name);
    strcpy((*root)->fathername, "wu");
	(*root)->num = 0;
    (*root)->degree = 1;
    (*root)->child = NULL;
    (*root)->parent = NULL;
    (*root)->brother = NULL;
}

void readd(tree *root, char Name[], char father_name[], char Sex)
{
    tree *p, *q;
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);              //更新成员以及父亲信息
    strcpy(p->fathername, father_name);
    if(root == NULL)
    {
        return ;
    }
    if(strcmp(root->name, p->fathername) == 0)   //找到父亲
    {
        p->degree = root->degree+1;         //更新辈份
        if(root->child == NULL)              //左孩子为空直接添加为左孩子
        {
            root->child = p;
            root->num++;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
        }
        else                    //不为空添加在兄弟结点上
        {
            q = root->child;
            while(q->brother)
            {
                q = q->brother;
            }
            q->brother = p;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
            root->num++;
        }
        return ;
    }
    readd(root->child, Name, father_name, Sex);              //递归寻找创建
    readd(root->brother, Name, father_name, Sex);
}

void show_main()
{
    tree *root;
    char str[1500];
    int choice;
    root = (tree *)malloc(sizeof(struct treenode));
    while(1)
    {
        printf("****************家谱树操作********************\n");
        printf("*          1、新建家谱树                     *\n");
        printf("*          2、成员添加                       *\n");
        printf("*          3、成员信息查询                   *\n");
        printf("*          4、删除家谱成员                   *\n");
        printf("*          5、成员信息修改                   *\n");
        printf("*          6、家谱树显示                     * \n");
        printf("*          7、从文件中读取信息重建家谱树     *\n");
        printf("*          8、保存家谱到文件                 *\n");
        printf("*          0、退出                           *\n");
        printf("**********************************************\n");
        printf("请输入您的选择：");
        int i, n,aa;
        char order[105];
        scanf("%s", order);
        choice = get_choice(order);
        switch(choice)
        {
        case 1:
            show_creat(root);
            break;
        case 2:
            show_add(&root);
            break;
        case 3:
            show_find(root);
            break;
        case 4:
            show_del(root);
            break;
        case 5:
            show_change(root);
            break;
        case 6:
            show(root);
            printf("\n");
            break;
        case 7:
            root = (tree *)read_from_file();
            break;
        case 8:
            write_to_file(&root);
            printf("文件保存成功\n");
            break;
        case 0:
            
            return;
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }
        printf("***************按ENTER键继续**************\n");
        getchar();  
    }
}

void show_find(tree *root)
{
    while(1)
    {
        printf("***************成员信息查询****************\n");
        printf("           1、查找成员信息\n");
        printf("           2、查找成员孩子信息\n");
        printf("           3、查找两个人的关系\n");
        printf("           4、查找成员三代人信息\n");
        printf("           5、查找同一辈份成员信息\n");
        printf("           0、退出\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, class, i,choice;
        char name[15], name1[15], order[105];
        scanf("%s", order);
        choice = get_choice(order);
        switch(choice)
        {
        case 1:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            chu();
            if(!find(root, name))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 2:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            chu();
            if(!find_parent(root, name))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 3:
            printf("请输入两个查询成员的姓名（名字之间用空格隔开）:\n");
            scanf("%s %s%*c", name, name1);
            chu();
            if(!find_connect(root, name, name1))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 4:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            find_three(root, name);
            break;
        case 5:
            printf("请输入要查询辈份:");
            scanf("%d%*c", &class);
            chu();
            if(!find_same_class(root, class))
            {
                printf("没有该辈份成员信息！\n");
            }
            break;
        case 0:
            return;
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }
        printf("***************按ENTER键继续**************\n");
        getchar();     
    }
}

void show(tree *root)
{
    long long int aa;
    if(root == NULL) return ;//家谱树为空
    else
    {
        for(aa = 1; aa < root->degree; aa++)
        {
            printf("\t\t");
        }
        printf("（%d代）%s\n", aa,root->name);
        show(root->child);//输出孩子信息
        show(root->brother);//输出兄弟信息
    }
}

void show_del(tree *root)
{
    char Name[15], for_sure, order[105];
    int num,choice;
    while(1)
    {
        printf("*****************选择你的操作****************\n");
        printf("***************1：删除某一成员****************\n");
        printf("******************0：退出****************\n");
        scanf("%s", order);
        choice = get_choice(order);
        switch(choice)
        {
            case 1:
                printf("***********请输入要删除成员的名字***************\n");
                scanf("%s%*c", Name);
                printf("***********您确认删除吗（y/n）***************\n");
                scanf("%c", &for_sure);
                if(for_sure == 'y')
                {
                    Delete(root, Name);
                }
                break;
            case 0:
                return ;
            default:
                printf("输入错误，请重新输入！\n");
        }
    }
}

void show_creat(tree *root)
{
    while(1)
    {
        printf("***************新建家谱树*****************\n\n");
        printf("           1、建立家谱\n");
        printf("           0、退出\n\n");
        printf("           （性别：男 M;  女 F）\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n,choice;
        char order[105];
        scanf("%s", order);
        choice = get_choice(order);
        switch(choice)
        {
        case 1:
            create(root);
            break;
        case 0:
            return;
            break;
        default:
            printf("输入错误，请重新输入！\n");
        } 
    }
}

void show_change(tree *root)
{
    while(1)
    {
        printf("******************成员信息修改**************\n\n");
        printf("           1、信息修改\n");
        printf("           2、确认修改\n");
        printf("           3、撤销修改\n");
        printf("           0、退出\n\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, d,choice;
        char order[105];
        scanf("%s", order);
        choice = get_choice(order);
        char name[15], name1[15];
        switch(choice)
        {
        case 1:
            printf("请输入要修改成员的姓名：");
            scanf("%s%*c", name);
            printf("请输入修改后的姓名：");
            scanf("%s%*c", name1);
            printf("是否确认修改？\n");
            scanf("%d%*c", &d);
            if(d == 2)
            {
                change(root, name, name1);
            }
            else
            {
                printf("撤销成功！");
            }
            break;
        case 0:
            return;
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }   
    }
}

void Delete(tree *root, char name[])
{
    tree *temp_child, *temp;
    chu();//初始化
    temp_child = (tree *)find_point(root, name);//查看是否存在
    if(temp_child && temp_child == root)//存在且为祖先
    {
        printf("你不能删除祖先！\n");
        return ;
    }
    if(temp_child == NULL)//不存在
    {
        printf("没有该成员信息！\n");
        return ;
    }
    if(temp_child->parent->child == temp_child)//该成员直接连接在父亲上
    {
        temp_child->parent->child = NULL;
        temp_child->parent->child = temp_child->brother;
    }
    else
    {
        temp = temp_child->parent->child;//连接该孩子的上一个指针
        while(temp->brother != temp_child  && temp)
        {
           temp = temp->brother;
        }
        temp->brother = temp->brother->brother;
    }
    printf("该成员已被删除！\n");
}

void change(tree *root, char Name[], char Name_changed[])
{
    tree *temp;
    temp = (tree *)find_point(root, Name);//查看该成员是否存在
    if(temp == NULL)//不存在
        printf("没有该成员信息！\n");
    else
    {
        strcpy(temp->name, Name_changed);//修改成员信息
        printf("该成员的信息已经成功修改！\n");
    }
}

void show_add(tree **root)
{
	tree *temp, *temp1;
    while(1)
    {
        printf("******************成员添加****************\n\n");
        printf("       1、添加新成员作为整个家谱的祖先\n");
        printf("       2、添加新成员作为某一成员的孩子\n");
        printf("       0、退出\n\n");
        printf("           （性别：男 M;  女 F）\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, flag = 0,choice;
        char name[105], ch, name1[105], order[105];
        scanf("%s", order);
        choice = get_choice(order);
        switch(choice)
        {
        case 1:
            printf("请输入祖先姓名：");
            scanf("%s%*c", name);
            printf("请输入祖先性别：");
            scanf("%c%*c", &ch);
            chu();
            temp = (tree *)find_point(*root, name);//查找成员位置
            if(temp == NULL)//未找到
	            *root = add_zuxian(*root, name, ch);
	        else
	        	printf("家谱中已存在该成员！\n");
            break;
        case 2:
            printf("请输入新成员姓名：");
            scanf("%s%*c", name);
            printf("请输入新成员父亲姓名：");
            scanf("%s%*c", name1);
            printf("请输入新成员性别：");
            scanf("%c%*c", &ch);
            chu();
            temp = (tree *)find_point(*root, name);//查找成员位置
            chu();
            temp1 = (tree *)find_point(*root, name1);//查找父亲位置
            if(temp1)//找到父亲
			{
				if(temp == NULL)
					add(*root, name, name1, ch, &flag);
				else
					printf("家谱中已存在该成员！\n");
			}
	        else
	        	printf("添加成员失败！\n");
            if(flag)//添加成功
            {
                printf("添加成功！\n");
            }
            break;
        case 0:
            return;
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }  
    }
}

void save_as_string(tree *root, char str[])
{
	if(root == NULL)
		return ;
	if(root)
	{
		int i;
		int len = strlen(root->name);
		for(i = 0; i < len; i++)
		{
			str[point++] = root->name[i];
		}
		str[point++] = '-';
		len = strlen(root->fathername);
		for(i = 0; i < len; i++)
		{
			str[point++] = root->fathername[i];
		}
		str[point++] = '-';
		str[point++] = root->sex;
		str[point++] = '\n';

		save_as_string(root->child, str);
		save_as_string(root->brother, str);
	}	
}

void write_to_file(tree **root)
{
	point = 0;
	char str[2000];
	save_as_string(*root, str);
	str[point] = '\0';
	FILE *fp;
	fp = fopen("jiapu.txt", "w");
	fprintf(fp, "%s", str);
	fclose(fp);
}

tree *read_from_file()
{
	FILE *fp;
	fp = fopen("jiapu.txt", "r+");
	int i = 0;
	struct person s[1000];
	tree *root, *temp;
	int la, lb;
	while(fscanf(fp, "%[^-]-%[^-]-%c%*c", s[i].Name, s[i].fatherName, &s[i].Sex) != EOF)
	{
		i++;
	}
	root = rebuild(&temp, s, i);
	fclose(fp);
	printf("文件已读入，正在重构家谱树……\n");
	return root;
}

tree *rebuild(tree **root, struct person s[], int len)
{
	*root = (tree *)malloc(sizeof(struct treenode));
	if(len == 0)
		printf("输入错误，请重新输入！\n");
	int j = 0;
	struct person t;
	t = s[j];
	printf("-----%s %s %c\n", t.Name, t.fatherName, t.Sex);
	recreate(root, t.Name, t.Sex);
	j++;
	while(j < len)
	{
		t = s[j];
		printf("-----%s %s %c\n", t.Name, t.fatherName, t.Sex);
		readd(*root, t.Name, t.fatherName, t.Sex);
		j++;
	}
	return *root;
}

int main()
{
    printf("******************************************\n");
    printf("*           欢迎来到家谱管理系统         *\n");
    printf("******************************************\n\n\n");
    printf("***************按ENTER键继续**************\n");
    getchar();
    show_main();//家谱树展示界面
    return 0;
}
