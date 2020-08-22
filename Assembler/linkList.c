#include "linkList.h"

// Stack size

struct symbolTable* symbolTable_create() {
	struct symbolTable* newNode = malloc(sizeof(struct symbolTable));
	newNode->next = NULL;
	return newNode;

}

struct addressTable* addressTable_create() {
	struct addressTable* newNode = malloc(sizeof(struct addressTable));
	newNode->next = NULL;
	return newNode;
}

struct dataTable* dataTable_create() {
	struct dataTable* newNode = malloc(sizeof(struct dataTable));
	newNode->next = NULL;
	return newNode;
}

/**
* Functiont to push a new element in stack.
*/
void push_operationFunc(struct addressTable* link_list, int *address)
{
	
	/* Create a new node and push to stack */
	struct addressTable * newNode = (struct addressTable *) calloc(1,sizeof(struct addressTable));
	/* Assign data to new node in stack */
	newNode->address = *address;
	
 
	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;
	
	printf("\nData: %d pushed to stack.\n", (*address));

	(*address)++;
}

void push_update_operationFunc(struct addressTable* link_list, int *address, int binaryArray[])
{

	/* Create a new node and push to stack */
	struct addressTable * newNode = (struct addressTable *) calloc(1, sizeof(struct addressTable));
	/* Assign data to new node in stack */
	newNode->address = *address;
	arrayAssign(link_list->binaryMachineCode, binaryArray, 0, 23);

	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;

	printf("\nData: %d pushed to stack.\n", (*address));

	(*address)++;
}

void update_operationFunc(struct addressTable * link_list, int address, int binaryArray[]) {
	
	while (link_list != NULL) {

		if (link_list->address== address){
			arrayAssign(link_list->binaryMachineCode, binaryArray, 0, 23);
			printf("\n Address: %d update .\n", address);
			break;
		}
		link_list = link_list->next;
	}



 }


struct addressData get_code_data(struct addressTable* link_list, int address[]) {

	
	struct addressData  data;

	while (link_list != NULL) {

		if ( link_list->address == address) {
			data.address = link_list->address;
			arrayAssign(data.binaryMachineCode, link_list->binaryMachineCode, 0, 23);
 
			break;

		}
		link_list = link_list->next;
	}

	return data;
}

void push_symbol_table(struct symbolTable * link_list ,char symbol[], int address,  TypeSymbol type)
{
 
	// Create a new node and push to stack
	struct symbolTable * newNode = (struct symbolTable *) malloc( sizeof(struct symbolTable));

	// Assign data to new node in stack
	newNode->address = address;
	strcpy(newNode->symbol , symbol);
	newNode->characterization = type;
 
	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;

	printf("\nSymbol: %s", symbol);
	printf("\tAddress: %d", address);
	printf("\tType: %d", type);

	printf("Data pushed to stack.\n");
}

void update_symbol_table(struct symbolTable * link_list, char symbol[], int address, TypeSymbol type) {
	
	printf("\nSymbol: %s", symbol);
	printf("\tAddress: %d", address);
	printf("\tType: %d", type);

	strcpy(link_list->symbol, symbol);
	link_list->address = address;
	link_list->characterization = type;

}

void push_update_data_table(struct dataTable * link_list,int *address, char name[], int binaryArray[]) {
	 

	// Create a new node and push to stack
	struct dataTable * newNode = (struct dataTable *) malloc(sizeof(struct dataTable));

	// Assign data to new node in stack
	newNode->address = (*address);
	strcpy(newNode->name, name);
	arrayAssign(link_list->binaryMachineCode, binaryArray, 0, 23);

	// Next element after new node should be current top element
	newNode->next = link_list->next;
	// Make sure new node is always at top
	link_list->next = newNode;

	printf("\nData: %d pushed to stack.\n", (*address));
	(*address)++;

}

int size_list(struct symbolTable * link_list) {

	int size = 0;

	while (link_list != NULL) {

		++size;
		link_list = link_list->next;
	};
	return size;
}

int serach_symbol_address(struct symbolTable * link_list, char symbol[]) {

	int address = NULL;
	while (link_list != NULL) {

		if (strcmp(link_list->symbol, symbol) == 0) {
			address = link_list->address;
			break;

		}
		link_list = link_list->next;
	}

	return address;
}


struct symbolData get_symbol_data(struct symbolTable * link_list, char symbol[]) {

	 
	struct symbolData  row;

	while (link_list != NULL) {

		if (strcmp(link_list->symbol, symbol) == 0) {
			row.address = link_list->address;
			row.characterization = link_list->characterization;
			row.isInternal = link_list->isInternal;
			strcpy(row.symbol, symbol);

			break;

		}
		link_list = link_list->next;
	}

	return row;
}
