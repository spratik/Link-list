// design the delet  which has to delet a particular node in given link list and

#include<stdio.h>
#include<stdlib.h>
struct st
{
	int rollno;
	struct st *next;
};

typedef struct st ST;

int count_node(ST *p);
void add_end(ST **ptr);
void print(ST *p);
void delet_node(ST **ptr,int r);
void freeMemory(ST *hptr)
{

	ST *tmpNode;
	while(hptr)
	{
	    tmpNode = hptr;
		hptr = hptr->next;
		free(tmpNode);
	}

}
main()
{
	char ch;
	int c;
	ST *headptr=0,*p;// for remove the garbage addrress
	do
	{
		add_end(&headptr);//hear i am using call by refrence because of the data i  is not erased..

		printf("do you want to add another node..(y/Y)\n");
		scanf(" %c",&ch);
	}
	while(ch=='y' || ch=='Y');

	print(headptr);
	c=count_node(headptr);
	printf("%d\n",c);

	int num = 0;
	printf("Enter roll number to be detelted :");
	scanf("%d", &num);
	delet_node(&headptr,num);

	print(headptr);	
	
	freeMemory(headptr);	

}



void delet_node(ST **ptr,int r)
{
	ST *temp,*temp1;

	temp=*ptr;

	while(temp)
	{
		if(temp->rollno==r)
		{
			if(temp==*ptr)// 1st node
			{
				*ptr=temp->next;
				free(temp);
				return;
			}
			else// last and middle node
			{
				temp1->next=temp->next;
				free(temp);
				return;
			}
		}

		temp1=temp;
		temp=temp->next;
	}
}



int count_node(ST *p)
{
	int c=0;

	while(p)
	{
		c++;
		p=p->next;
	}
	return c;

}

void print(ST *p)
{
	while(p)
	{
		printf("%d \n",p->rollno);
		p=p->next;
	}
}



void add_end(ST **ptr)
{
	ST *temp,*temp1;// hear define the local temp that is teminate while funcation is terminate

	temp=malloc(sizeof(ST));// allocate dynamic memory

	printf("\nEnter the rollno:");
	scanf("%d",&temp->rollno);
	
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}

	else
	{
		temp1=*ptr;


		while(temp1->next)
			temp1=temp1->next;


		temp->next=temp1->next;
		temp1->next=temp;

	}
}

