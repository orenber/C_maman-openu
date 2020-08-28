#include "Tables.h"



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

	if (opcodeFunc->funct != NULL) {

		binaryArr = decimal2binaryArray(opcodeFunc->funct, 5);
	}
	else {

		binaryArr = decimal2binaryArray(0, 5);
	}

	arrayAssign(opcodeFunc->functBinaryArr, binaryArr, 0, 4);
	
}




BOOL cheak_legal_address(char func[], AdressType  sourceOperand, AdressType destinationOperand) {
	
	int *binaryArr;
	BOOL ok1 = False, ok2 = False,legal;	
	AdressType  legalSource[3], legalDestination[3];
 

	if (strcmp(func, "mov") == 0) {
		 /* Source*/
		legalSource[0] = 0; legalSource[1] = 1; legalSource[2] = 3;
		ok1 = assertIsMember(sourceOperand, legalSource, 3);
		
		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		ok2 = assertIsMember(destinationOperand, legalDestination,3);

		legal = ok1 * ok2;

	}
	else if (strcmp(func, "cmp") == 0) {
		/* Source*/
		legalSource[0] = 0; legalSource[1] = 1; legalSource[2] = 3;
		ok1 = assertIsMember(sourceOperand, legalSource,3);
		
		/* Destination */
		legalDestination[0] = 0;  legalDestination[1] = 1; legalDestination[2] = 3;
		ok2 = assertIsMember(destinationOperand, legalDestination,3);
		
		legal = ok1 * ok2;

	}
	else if (strcmp(func, "add") == 0) {

		/* Source*/
		legalSource[0] = 0; legalSource[1] = 1; legalSource[2] = 3;
		ok1 = assertIsMember(sourceOperand, legalSource, 3);

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		ok2 = assertIsMember(destinationOperand, legalDestination, 3);

		legal = ok1 * ok2;
 
	}
	else if (strcmp(func, "sub") == 0) {

		/* Source*/
		legalSource[0] = 0; legalSource[1] = 1; legalSource[2] = 3;
		ok1 = assertIsMember(sourceOperand, legalSource, 3);

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		ok2 = assertIsMember(destinationOperand, legalDestination, 3);

		legal = ok1 * ok2;
		 
	}
	else if (strcmp(func, "lea") == 0) {

		/* Source*/
		legalSource[0] = 1;
		ok1 = assertIsMember(sourceOperand, legalSource, 3);

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		ok2 = assertIsMember(destinationOperand, legalDestination, 3);

		legal = ok1 * ok2;

	}
	else if (strcmp(func, "clr") == 0) {
	 

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
		 
	}
	else if (strcmp(func, "not") == 0) {
	 
		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
	}
	else if (strcmp(func, "inc") == 0) {
	 
		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
	}
	else if (strcmp(func, "dec") == 0) {
	 

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
	}
	else if (strcmp(func, "jmp") == 0) {

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 2;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
	}
	else if (strcmp(func, "bne") == 0) {

		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 2;
		legal = assertIsMember(destinationOperand, legalDestination, 3);
	}
	else if (strcmp(func, "jsr") == 0) {


		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 2;
		legal = assertIsMember(destinationOperand, legalDestination, 3);

	}
	else if (strcmp(func, "red") == 0) {


		/* Destination */
		legalDestination[0] = 1; legalDestination[1] = 3;

		legal = assertIsMember(destinationOperand, legalDestination, 3);

	}
	else if (strcmp(func, "prn") == 0) {
		 

		/* Destination */
		legalDestination[0] = 0;legalDestination[1] = 1, legalDestination[1] = 3;

		ok2 = assertIsMember(destinationOperand, legalDestination, 3);

		legal =   ok2;
	}
	else if (strcmp(func, "rts") == 0) {
	 

		legal = True;
	}
	else if (strcmp(func, "stop") == 0) {
		 

		legal = True;
	}
	return legal;

}