#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int value;
	struct Node *next;

}NODE;

void print(NODE *hptr)
{
	printf("PRINT ::");

	while(hptr)
	{
		printf("%d\n", hptr->value);
		hptr = hptr->next;	
	}

}
void add_middle(NODE **hptr, int value)
{

	/// create Head Pointer
	if(*hptr == NULL){
		*hptr = calloc(1, sizeof(NODE));
		if(*hptr == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		//printf("ENTER INTO FIRST TIME ::%u\n",*hptr);
		(*hptr)->value = value;
		(*hptr)->next = NULL;
		return ;
	}

NODE *tmpNode = *hptr;

while(tmpNode)
{
     
	/// ADD AT BEGING
	if((*hptr)->value > value){
	
		NODE *newNode = calloc(1, sizeof(NODE));
		if(newNode == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		newNode->value = value;
		newNode->next = *hptr;
		*hptr = newNode;
		break;
	}
	else if((tmpNode->next != NULL) && ((tmpNode->next)->value > value)){
		
		NODE *newNode = calloc(1, sizeof(NODE));
		if(newNode == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		newNode->value = value;
		
		newNode->next = tmpNode->next;
		tmpNode->next = newNode;
		break;
	}
	else if((tmpNode->next == NULL)){
		
		NODE *newNode = calloc(1, sizeof(NODE));
		if(newNode == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		newNode->value = value;
		newNode->next = tmpNode->next;
		tmpNode->next = newNode;	
		break;		
	}
	tmpNode = tmpNode->next;	
}
}
void freeMemory(NODE *hptr)
{

	NODE *tmpNode;
	while(hptr)
	{
	    tmpNode = hptr;
		hptr = hptr->next;
		free(tmpNode);
	}

}

int main()
{
	
	NODE *hptr = NULL;
	int value = 0;
	char ch;
	do {
		printf("ENTER VALUE ::");
		scanf("%d", &value);
		add_middle(&hptr, value);
		printf("DO U WANT TO ADD ONE MORE ELEMENT TYPE(Y/y)::");
		scanf(" %c", &ch);
		printf("\n");
	}while(ch == 'Y' || ch == 'y');		

	print(hptr);
	
	freeMemory(hptr);
	

}
