#ifndef MAIN_H
#define MAIN_H

typedef struct treenode
{
    char sex;
    int num;
    int degree;
    char name[20];
    char fathername[20];
    struct treenode *child;
    struct treenode *brother;
    struct treenode *parent;
}tree;

struct person
{
	char Name[15];
	char fatherName[15];
	char Sex;
}person;

tree *read_from_file();
tree *rebuild(tree **root, struct person s[], int len);
tree *find_point(tree *root, char name[]);
tree *add_zuxian(tree *root, char Name[], char Sex);
int find(tree *root, char name[]);
int get_choice(char *choice_t);
int find_parent(tree *root, char parent[]);
int find_connect(tree *root, char name1[], char name2[]);
int find_same(tree *root, int class_num);
void chu();
void show_main();
void show_add(tree **root);
void show_del(tree *root);
void show_find(tree *root);
void show_creat(tree *root);
void show_change(tree *root);
void show(tree *root);
void find_three(tree *root, char name[]);
void change(tree *root, char Name[], char Name_changed[]);
void Delete(tree *root, char name[]);
void save_as_string(tree *root, char str[]);
void write_to_file(tree **root);
void create(tree *root);
void add(tree *root, char Name[], char father_name[], char Sex, int *flag);
void change_degree(tree *root);
void recreate(tree **root, char Name[], char Sex);
void readd(tree *root, char Name[], char father_name[], char Sex);


int get_choice(char *choice_t)
{
    int i;
    i = atoi(choice_t);
    if(i<0||i>9){
    	return 9;
	}else{
		return i;
	}
}

#endif


