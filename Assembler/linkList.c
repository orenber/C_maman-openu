#include "interface.h"

// Stack size
static int size = 0;

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
	struct addressTable * newNode = (struct addressTable *) malloc(sizeof(struct addressTable));

	// Assign data to new node in stack
	newNode->address[5] = size;
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






