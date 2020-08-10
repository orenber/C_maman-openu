#include "interface.h"

// Stack size
static int size = 100;
static int size_flag = 100;

/**
* Functiont to push a new element in stack.
*/
void push_operationFunc(char sorceCode[] ,struct operationFunc *opcodeFunc)
{
	// Check stack overflow
	if (size >= CAPACITY)
	{
		printf("Stack Overflow, can't add more element to stack.\n");
		return;
	}

	// Create a new node and push to stack
	struct addressTable * newNode = (struct addressTable *) calloc(23,sizeof(struct addressTable));

	// Assign data to new node in stack
	newNode->address = size;
	newNode->binaryMachineCode[5] =opcodeFunc->opcode;
	newNode->sourceCode[5] = sorceCode;
	// Next element after new node should be current top element
	newNode->next = top;

	// Make sure new node is always at top
	top = newNode;

	// Increase element count in stack
	size++;

	printf("Data pushed to stack.\n");
}

 

void push_flag_table(char flag[], int address)
{
	// Check stack overflow
	if (size_flag >= CAPACITY)
	{
		printf("Stack Overflow, can't add more element to stack.\n");
		return;
	}

	// Create a new node and push to stack
	struct flagTable * newNode = (struct flagTable *) malloc( sizeof(struct flagTable));

	// Assign data to new node in stack
	newNode->address = address;
	strcpy(newNode->symbol ,flag);
 
	// Next element after new node should be current top element
	newNode->next = top;

	// Make sure new node is always at top
	top = newNode;

	// Increase element count in stack
	size_flag++;

	printf("Data pushed to stack.\n");
}





