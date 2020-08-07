#include "interface.h"

// Stack size
static int size = 0;

/**
* Functiont to push a new element in stack.
*/
void push(char sorceCode[] ,struct operationFunc *opcodeFunc)
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
	newNode->address[5] = size++;
	newNode->binaryMachineCode[] = opcodeFunc->opcode;
	newNode->sourceCode[] = sorceCode;
	// Next element after new node should be current top element
	newNode->next = top;

	// Make sure new node is always at top
	top = newNode;

	// Increase element count in stack
	size++;

	printf("Data pushed to stack.\n");
}


/**
* Function to pop element from top of stack.
*/
int pop()
{
	int data = 0;
	struct stack * topNode;

	// Check stack underflow
	if (size <= 0 || !top)
	{
		printf("Stack is empty.\n");

		// Throw empty stack error/exception
		// Since C does not have concept of exception
		// Hence return minimum integer value as error value
		// Later in code check if return value is INT_MIN, then
		// stack is empty
		return INT_MIN;
	}

	// Copy reference of stack top to some temp variable
	// Since we need to delete current stack top and make
	// Stack top its next element
	topNode = top;

	// Copy data from stack's top element
	data = top->data;

	// Move top to its next element
	top = top->next;

	// Delete the previous top most stack element from memory
	free(topNode);

	// Decrement stack size
	size--;

	return data;
}