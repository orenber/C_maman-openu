#include "linkList.h"

// Stack size

struct symbolTable* create_symbol_table() {
	struct symbolTable* newNode = malloc(sizeof(struct symbolTable));
	newNode->next = NULL;
	return newNode;

}

struct memoryTable* create_memory_table() {
	struct memoryTable* newNode = malloc(sizeof(struct memoryTable));
	newNode->next = NULL;
	return newNode;
}

struct dataTable* create_data_table() {
	struct dataTable* newNode = malloc(sizeof(struct dataTable));
	newNode->next = NULL;
	return newNode;
}

/**
* Functiont to push a new element in stack.
*/
void push_memory_table(struct memoryTable** link_list, int *address)
{
	
	/* Create a new node and push to stack */
	struct memoryTable * newNode = (struct memoryTable *) calloc(1,sizeof(struct memoryTable));
	/* Assign data to new node in stack */
	newNode->address = *address;
	
 
	// Next element after new node should be current top element
	newNode->next = *link_list;
	// Make sure new node is always at top
	*link_list = newNode;
	
	printf("\nData: %d pushed to stack.\n", (*address));

	(*address)++;
}

void push_symbol_table(struct symbolTable ** link_list, int address, char symbol[], TypeSymbol type, BOOL isInternal)
{

	// Create a new node and push to stack
	struct symbolTable * newNode = (struct symbolTable *) malloc(sizeof(struct symbolTable));

	// Assign data to new node in stack
	newNode->address = address;
	strcpy(newNode->symbol, symbol);
	newNode->characterization = type;
	newNode->isInternal = isInternal;

	// Next element after new node should be current top element
	newNode->next = *link_list;
	// Make sure new node is always at top
	*link_list = newNode;

	printf("\nSymbol: %s", symbol);
	printf("\tAddress: %d", address);
	printf("\tType: %d", type);

	printf("Data pushed to stack.\n");

}

/* push and update*/
void push_and_update_memory_table(struct memoryTable** link_list, int *address, int binaryArray[])
{

	/* Create a new node and push to stack */
	struct memoryTable * newNode = (struct memoryTable *) calloc(1, sizeof(struct memoryTable));
	/* Assign data to new node in stack */
	newNode->address = *address;
	arrayAssign(newNode->binaryMachineCode, binaryArray, 0, 23);

	// Next element after new node should be current top element
	newNode->next = *link_list;
	// Make sure new node is always at top
	*link_list = newNode;

	printf("\nData: %d pushed to stack.\n", (*address));

	(*address)++;
}

void push_and_update_data_table(struct dataTable ** link_list, int *address, char name[], int binaryArray[]) {


	// Create a new node and push to stack
	struct dataTable * newNode = (struct dataTable *) malloc(sizeof(struct dataTable));

	// Assign data to new node in stack
	newNode->address = (*address);
	strcpy(newNode->name, name);
	arrayAssign(newNode->binaryMachineCode, binaryArray, 0, 23);

	// Next element after new node should be current top element
	newNode->next = *link_list;
	// Make sure new node is always at top
	*link_list = newNode;

	printf("\nData: %d pushed to stack.\n", (*address));
	(*address)++;

}


/* update */

void update_memory_table(struct memoryTable * link_list, int address, int binaryArray[]) {
	
	while (link_list != NULL) {

		if (link_list->address== address){
			arrayAssign(link_list->binaryMachineCode, binaryArray, 0, 23);
			printf("\n Address: %d update .\n", address);
			break;
		}
		link_list = link_list->next;
	}
 }

void update_symbol_table(struct symbolTable * link_list, char symbol[], TypeSymbol type, BOOL isInternal) {

	while (link_list != NULL) {

		if (strcmp(link_list->symbol, symbol) == 0) {
			link_list->isInternal = isInternal;
			link_list->characterization = type;

			break;
		}
		link_list = link_list->next;
	}
}


/* size */

int size_symbol_table(struct symbolTable * link_list) {

	
	int size = 0;

	while (link_list != NULL) {

		++size;
		link_list = link_list->next;
	};
	return size;
}

int size_data_table(struct dataTable * link_list) {


	int size = 0;

	while (link_list != NULL) {

		++size;
		link_list = link_list->next;
	};
	return size;
}

int size_memory_table(struct memoryTable * link_list) {


	int size = 0;

	while (link_list != NULL) {

		++size;
		link_list = link_list->next;
	};
	return size;
}


/* serach */

struct addressData get_code_data(struct memoryTable* link_list, int address[]) {


	struct addressData  data;

	while (link_list != NULL) {

		if (link_list->address == address) {
			data.address = link_list->address;
			arrayAssign(data.binaryMachineCode, link_list->binaryMachineCode, 0, 23);

			break;

		}
		link_list = link_list->next;
	}

	return data;
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

int serach_symbol_address(struct symbolTable  *link_list, char symbol[]) {

	int address = NULL;
	while (link_list != NULL) {
		
		if (strcmp(link_list->symbol, symbol)==0) {
			address = link_list->address;
			break;

		}
		link_list = link_list->next;
	}

	return address;
}

BOOL serach_symbol_type(struct symbolTable  *link_list, char symbol[], TypeSymbol type) {

	BOOL exist = False;

	while (link_list != NULL) {

		if ((strcmp(link_list->symbol, symbol) == 0)
			&&(link_list->characterization ==type )) {
			exist = True;
			break;

		}
		link_list = link_list->next;
	}

	return exist;
}

BOOL is_symbol_exist(struct symbolTable  *link_list, char symbol[]) {

	BOOL exist = False;

	while (link_list != NULL) {

		if (strcmp(link_list->symbol, symbol) == 0) {

			exist = True;
			break;

		}
		link_list = link_list->next;
	}

	return exist;
}

 

/* print */

void print_symbol_table(struct symbolTable * link_list) {

	while (link_list != NULL) {

		printf("\nsymbol:  %s\t", link_list->symbol);
		printf("address: %d\t", link_list->address);
		printf("Type: %d\t", link_list->characterization);
		printf("isInternal: %d\t", link_list->isInternal);
		link_list = link_list->next;
	}
}
 
void print_memory_table(struct memoryTable* link_list) {

	while (link_list != NULL) {
 
		printf("\naddress: %d:\n", link_list->address);
		printArray(link_list->binaryMachineCode,24);
 
		link_list = link_list->next;
	}

}

void print_data_table(struct dataTable* link_list) {

	while (link_list != NULL) {

		printf("\naddress: %d:\t", link_list->address);
		printf("name: %s:\t", link_list->name);
		printArray(link_list->binaryMachineCode,24);

		link_list = link_list->next;
	}

}



