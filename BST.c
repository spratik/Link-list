#include<stdio.h>
#include<malloc.h>
typedef struct st
{
	struct st *left;
	int num;
	struct st *right;
}tree;
//typedef struct st tree;

tree * search(tree *ptr,int n);
void pre_order(tree *ptr);

tree *add_tree(tree **ptr,int n);
void post_order(tree *ptr);
void in_order(tree *ptr);
main()
{
tree *hptr=0;
int n;
char ch;

do
{
printf("enter the number\n");
scanf("%d",&n);
printf("do u enter the tree node?(y/Y)\n");
scanf(" %c",&ch);

add_tree(&hptr,n);

}while((ch=='y')||(ch=='Y'));

int a;
printf("enter the number that u want to search\n");
scanf("%d",&a);
tree *p = search(hptr,a);
if(p)
{
printf("%u\n",p);
printf("num=%d\n",p->num);
}

printf("post_order..\n");
post_order(hptr);

printf("pre_order..\n");
pre_order(hptr);

printf("in_order..\n");
in_order(hptr);
}

tree * search(tree *ptr,int n)
{
	if(ptr==NULL)
	{
		printf("no number is present\n");
		return 0;	
	}
	else if( ptr->num==n)
	{	
		printf("numebr is present\n");
		return(ptr);
	}

	else if(ptr->num > n)
	search(ptr->left,n);
	else
	search(ptr->right,n);
}

tree *add_tree(tree **ptr,int n)
{
	if((*ptr)==NULL)
	{
		(*ptr)=(tree *)malloc(sizeof(tree));
		(*ptr)-> num=n;
		(*ptr)->right=(*ptr)->left=0;
	}
	else if((*ptr)-> num > n)
	 add_tree(&(*ptr)->left,n);
	else
	add_tree (&(*ptr)->right,n);
}

void post_order(tree *ptr)
{
	if(ptr)
	{
		post_order(ptr->left);
		post_order(ptr->right);
		printf("%d-- >",ptr->num);
	}

}

void pre_order(tree *ptr)
{
	if(ptr)
	{
		printf("%d-- >",ptr->num);
		post_order(ptr->left);
		post_order(ptr->right);
	}
}
void in_order(tree *ptr)
{
	if(ptr)
	{
		post_order(ptr->left);
		printf("%d-- >",ptr->num);
		post_order(ptr->right);
	}
}
