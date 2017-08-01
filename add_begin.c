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
void add_begin(NODE **hptr, int value)
{
	if(*hptr == NULL){
		*hptr = calloc(1, sizeof(NODE));
		if(*hptr == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}
		printf("ENTER INTO FIRST TIME ::%u\n",*hptr);
		(*hptr)->value = value;
		(*hptr)->next = NULL;
	}else{
	
		NODE *tmp = calloc(1, sizeof(NODE));
		if(tmp == NULL){
			printf("MEMORY IS NOT ALLOCATED\n");
			exit(0);
		}

		tmp->next = *hptr;
		*hptr = tmp;
		(*hptr)->value = value;
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
		add_begin(&hptr, value);
		printf("DO U WANT TO ADD ONE MORE ELEMENT TYPE(Y/y)::");
		scanf(" %c", &ch);
		printf("\n");
	}while(ch == 'Y' || ch == 'y');		

	print(hptr);

}
