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
void add_end(NODE **hptr, int value)
{
	if(*hptr == NULL){
		*hptr = calloc(1, sizeof(NODE));
		if(*hptr == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		//printf("ENTER INTO FIRST TIME ::%u\n",*hptr);
		(*hptr)->value = value;
		(*hptr)->next = NULL;
	}else{
	
		NODE *newNode = calloc(1, sizeof(NODE));
		if(newNode == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		NODE *tmpNode = *hptr;
		NODE *currentNode  = NULL;
		while(tmpNode){
			currentNode = tmpNode;
			tmpNode = tmpNode->next; 
		}
		
		currentNode->next = newNode;
		newNode->next = NULL;
		newNode->value = value;
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

int countNumberOfNode(NODE *hptr)
{
	int count = 0;
	while(hptr){
		count++;
		hptr = hptr->next;
	}

	return count;
}


void reverse_data(NODE *hptr)
{
	NODE *tmpNode = hptr;
	int countNode = countNumberOfNode(tmpNode);
	printf("Count :: %d\n", countNode);
	
	int middleCount = (countNode/2);
	
	NODE *middleNode = hptr;
	for(int i = 0; i < middleCount; i++){
			middleNode = middleNode->next;
	}
	
	int temp;
	NODE *firstNode = hptr;
	NODE *lastNODE = NULL;
	for(int i = 0; i < middleCount; i++){
		  
		  lastNODE = middleNode;
		  for(int j = 0; j < (middleCount - i - 1); j++){
		  		lastNODE = lastNODE->next;
		  }
		  
		  temp = lastNODE->value;
		  lastNODE->value = firstNode->value;
		  firstNode->value = temp;
		  
		  firstNode = firstNode->next;
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
		add_end(&hptr, value);
		printf("DO U WANT TO ADD ONE MORE ELEMENT TYPE(Y/y)::");
		scanf(" %c", &ch);
		printf("\n");
	}while(ch == 'Y' || ch == 'y');		
	printf("Before Reverse DATA :: ");
	print(hptr);
	reverse_data(hptr);
	printf("After Reverse Data : ");
	print(hptr);
    freeMemory(hptr);
}