#include "interface.h"



void table_funct_opcode(char func[], struct operationFunc *opcodeFunc) {
	int *binaryArr;

	strcpy(opcodeFunc->name, func);

	if (strcmp(func, "mov") == 0) {
		opcodeFunc->opcode = 0;
		opcodeFunc->funct = NULL;

	}
	else if (strcmp(func, "cmp") == 0) {
		opcodeFunc->opcode = 1;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "add") == 0) {

		opcodeFunc->opcode = 2;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "sub") == 0) {

		opcodeFunc->opcode = 2;
		opcodeFunc->funct = 2;

	}
	else if (strcmp(func, "lea") == 0) {

		opcodeFunc->opcode = 4;
		opcodeFunc->funct = NULL;

	}
	else if (strcmp(func, "clr") == 0) {

		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "not") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 2;
	}
	else if (strcmp(func, "inc") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 3;
	}
	else if (strcmp(func, "dec") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 4;
	}
	else if (strcmp(func, "jmp") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "bne") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 2;
	}
	else if (strcmp(func, "jsr") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 3;
	}
	else if (strcmp(func, "red") == 0) {
		opcodeFunc->opcode = 12;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "prn") == 0) {
		opcodeFunc->opcode = 13;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "rts") == 0) {
		opcodeFunc->opcode = 14;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "stop") == 0) {
		opcodeFunc->opcode = 15;
		opcodeFunc->funct = NULL;
	}

	binaryArr = decimal2binaryArray(opcodeFunc->opcode, 6);
	arrayAssign(opcodeFunc->opcodeBinaryArr, binaryArr, 0, 5);
	printArray(opcodeFunc->opcodeBinaryArr, 6);
	if (opcodeFunc->funct != NULL) {

		binaryArr = decimal2binaryArray(opcodeFunc->funct, 5);
	}
	else {

		binaryArr = decimal2binaryArray(0, 5);
	}

	arrayAssign(opcodeFunc->functBinaryArr, binaryArr, 0, 4);
	printArray(opcodeFunc->functBinaryArr, 5);
}