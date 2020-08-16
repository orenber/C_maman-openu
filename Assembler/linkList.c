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
void push_operationFunc(struct addressTable* link_list,int address)
{
 
	/* Create a new node and push to stack */
	struct addressTable * newNode = (struct addressTable *) calloc(1,sizeof(struct addressTable));
	/* Assign data to new node in stack */
	newNode->address = address;

	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;
	
	printf("Data pushed to stack.\n");
}

void update_operationFunc(struct addressTable * link_list, int address,int binaryArray[]) {
	

	int address = NULL;
	while (link_list != NULL) {

		if (link_list->address== address){
			arrayAssign(link_list->binaryMachineCode, binaryArray, 0, 23);
			break;

		}
		link_list = link_list->next;
	}

	

 }

void push_flag_table(struct flagTable * link_list ,char flag[], int address)
{
 
	// Create a new node and push to stack
	struct flagTable * newNode = (struct flagTable *) malloc( sizeof(struct flagTable));

	// Assign data to new node in stack
	newNode->address = address;
	strcpy(newNode->symbol ,flag);
 
	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;

	printf("Data pushed to stack.\n");
}

void update_flag_table(struct flagTable * link_list, char flag[], int address) {
	
	
	strcpy(link_list->symbol, flag);
	link_list->address = address;
	

}


int size_list(struct flagTable * link_list) {
	
	int size = 0;

	while (link_list != NULL) {
		
		++size;
		link_list = link_list->next;
	};
	return size;
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





