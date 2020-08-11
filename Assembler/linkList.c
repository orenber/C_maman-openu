#include "interface.h"

// Stack size

struct flagTable* flagTable_create() {
	struct flagTable* l = malloc(sizeof(struct flagTable));
	l->next = NULL;
	return l;

}


struct addressTable* addressTable_create() {
	struct addressTable* l = malloc(sizeof(struct addressTable));
	l->next = NULL;
	return l;
}
/**
* Functiont to push a new element in stack.
*/
void push_operationFunc(struct addressTable* link_list,char sorceCode[] ,struct operationFunc *opcodeFunc)
{
	 

	// Create a new node and push to stack
	struct addressTable * newNode = (struct addressTable *) calloc(23,sizeof(struct addressTable));

	// Assign data to new node in stack
	newNode->address = opcodeFunc->funct;
	newNode->binaryMachineCode[5] =opcodeFunc->opcode;
	newNode->sourceCode[5] = sorceCode;
	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;
	

	printf("Data pushed to stack.\n");
}

 

void push_flag_table(struct flagTable * link_list ,char flag[], int address)
{
 
	// Create a new node and push to stack
	struct flagTable * newNode = (struct flagTable *) malloc( sizeof(struct flagTable));

	// Assign data to new node in stack
	newNode->address = address;
	strcpy(newNode->symbol ,flag);
 
	// Next element after new node should be current top element
	newNode->next =link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;

	printf("Data pushed to stack.\n");
}

int serach_address(struct flagTable * link_list, char flag[]) {

	int address = NULL;
	while (link_list != NULL) {
		
		if (strcmp(link_list->symbol,flag)==0) {
			address = link_list->address;
			break;

		}
		link_list = link_list->next;
	}


}





