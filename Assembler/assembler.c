#include "interface.h"

static struct flagTable *l;
static struct addressTable *addresstable;

Register R0=r0, R1 = r1, R2 = r2, 
         R3= r3, R4 = r4, R5 = r5,
	     R6 = r6,R7 = r7;

struct {
	char name[2];
	Register *reg;
}registerDictionary[] = {
	{ "r0",&R0 },{ "r1",&R1 },{ "r2",&R2 },
	{ "r3",&R3 },{ "r4",&R4 },{ "r5",&R5 },
	{ "r6",&R6 },{ "r7",&R7 },{ "#",NULL }
};



int main(int argc, char* argv[])
{  
	run_test();

	char file_to_read[MEM] = "";         /* file name that i read from*/
	char line_read[BUFFERSIZE] = "";     /* digit number string*/
	char *output = "";                   /* output from the user */
    BOOL is_file_read_exist = False,     /* is the file that i read from exist?*/
		 is_file_write_exist = False;    /* is the file that i write to exist?*/
	FILE* filePointer;
	struct operationFunc opcodeFunc;

	int  nargin = argc;                  /* number of input in */
	
	l = flagTable_create();
 

	/* check file name inputs */
	if ((nargin >= 2) && (argv[1] != NULL)) {
		strcpy(file_to_read, argv[1]);
		/* check if the file read exist*/
		is_file_read_exist = file_exists(file_to_read);
		if (is_file_read_exist == True) {
			filePointer = fopen(file_to_read, "r");
		}
		else if (is_file_read_exist == False) {
			/* if the file not exist the programe shoude stop*/
			exit(1);
		}
	}
	
	do{
		printf("%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, BUFFERSIZE, filePointer);
		if (output != NULL) {
			command_manager(output);
			push_operationFunc(line_read, &opcodeFunc);
		}
	} while (output != NULL);
	
	 

	getchar();

	return 0;
}

void command_manager(char command_original[]) {
	
	static int address = 100;
	char *command_section = "",
		command[MEM] = "",
		command_left[MEM], input_str[MEM];
	BOOL end_line = False, isFlag;
	 struct operationFunc opcodeFunc;
	 strcpy(command, command_original);
	 strcpy(command_left, command_original);
	 address++;
	
	 while (end_line != True) {

		 remove_substring(&command_left, command_section);
		 strcpy(command, command_left);
		 /* parse the command into 3 category */
		 command_section = strtok(command, seperator);
		

		 /* ist aflag? */
		 isFlag = assert_command(command_section, &flag_legal, 6, "");
		 if (isFlag)
		 {
			 flag_manger(command_section, address);
		 }
		 else if (assert_command(command_section, &function_legal, 16, ""))
		 {
			/* isFunction = assert_command(command_section, &function_legal, 16, "");*/
			
				

				 remove_substring(&command_left, command_section);

				 remove_substring_parts(&command_left,seperator);

				 function_manger(command_section, command_left, &opcodeFunc);
				 end_line = True;
			
		 }
		 else if (assert_command(command_section, &varType, 2, ""))
		 {
			 remove_substring(&command_left, command_section);

			 remove_substring_parts(&command_left, seperator);

			 varType_manger(command_section, command_left);
			 end_line = True;
		 }
		
	 }
	
}

void flag_manger(char flag[],int value) {
	static int number_update = 0;
	++number_update;
	printf("\nthis is flag: %s\n", flag);
	if (number_update ==1) {
		update_flag_table(l, flag, value);
	}
	else {
		/* insert the flag in the table flage  - link list */
		push_flag_table(l, flag, value);
	}
}

void function_manger(char fun[],char input_str[], struct operationFunc *opcodeFunc) {
	
	printf("\nthis is function: %s\n", fun);
	printf("\nthis is input: %s\n", input_str);

	table_funct_opcode(fun, opcodeFunc);
	set_operation_command(fun, input_str);

	push_operationFunc(addresstable, fun, &opcodeFunc);


	
}

void varType_manger(char varType[],char var[]) {

	printf("\nthis is varType: %s\n", varType);

	printf("\nthis is var: %s\n", var);


}



void set_operation_command(char func[], char input_str[]) {
	
	if (strcmp(func, "mov") == 0) {
 
		mov_from_user(input_str);
	}
	else if (strcmp(func, "cmp") == 0) {
		
		cmp_from_user(input_str);
	}
	else if (strcmp(func, "add") == 0) {
		
		add_from_user(input_str);
	 
	}
	else if (strcmp(func, "sub") == 0) {

		sub_from_user(input_str);

	}
	else if (strcmp(func, "lea") == 0) {

		lea_from_user(input_str);

	}
	else if (strcmp(func, "clr") == 0) {

		clr_from_user(input_str);
	 
	}
	else if (strcmp(func, "not") == 0) {
		
		not_from_user(input_str);
	}
	else if (strcmp(func, "inc") == 0) {
		
		inc_from_user(input_str);
	}
	else if (strcmp(func, "dec") == 0) {
		
		dec_from_user(input_str);
	}
	else if (strcmp(func, "jmp") == 0) {
	 
		jmp_from_user(input_str);
	}
	else if (strcmp(func, "bne") == 0) {
		 
		bne_from_user(input_str);
	}
	else if (strcmp(func, "jsr") == 0) {
		 
		jsr_from_user(input_str);
	}
	else if (strcmp(func, "red") == 0) {

		red_from_user(input_str);
 
	}
	else if (strcmp(func, "prn") == 0) {
	 
		prn_from_user(input_str);
	}
	else if (strcmp(func, "rts") == 0) {
		 
		rts_from_user(input_str);
	}
	else if (strcmp(func, "stop") == 0) {
		 
		stop_from_user(input_str);
	}

}


void mov_from_user(char nargin_str[]) {


}

void cmp_from_user(char nargin_str[]) {


}

void add_from_user(char nargin_str[]) {

	char *firstInput,*secondInput;
	char command_input[MEM] = "";  /* copy of input string */
	int nargin = 2;               /* number of input argument*/
	int addressType_first, addressType_second;

	strcpy(command_input, nargin_str);

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return;}
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return;}

	/* first input*/
	firstInput = strtok(command_input,",");
	addressType_first = cheakAddresingType(firstInput);

	/* second input*/
	secondInput = strtok(NULL, ",");
	addressType_second = cheakAddresingType(secondInput);


}

void sub_from_user(char nargin_str[]) {


}

void lea_from_user(char nargin_str[]) {


}

void clr_from_user(char nargin_str[]) {


}


void not_from_user(char nargin_str[]) {


}


void inc_from_user(char nargin_str[]) {


}


void dec_from_user(char nargin_str[]) {


}


void jmp_from_user(char nargin_str[]) {


}

void bne_from_user(char nargin_str[]) {


}


void jsr_from_user(char nargin_str[]) {


}


void red_from_user(char nargin_str[]) {


}


void prn_from_user(char nargin_str[]) {


}

void rts_from_user(char nargin_str[]) {


}


void stop_from_user(char nargin_str[]) {


}

int cheakAddresingType(char inputString[]) {


	

}


/* get complex name and return complex pointer to the complex varible */
Register* getRegisterVar(char registerName) {

	int i;
	for (i = 0; LEN_Register > i; i++) {
		if (registerDictionary[i].name == registerName) {
			return registerDictionary[i].reg;
		}
	}

	return registerDictionary[LEN_Register].reg;
}












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
	if (opcodeFunc->funct != NULL){

		binaryArr = decimal2binaryArray(opcodeFunc->funct, 5);
	}
	else {

		binaryArr = decimal2binaryArray(0, 5);
	}

	arrayAssign(opcodeFunc->functBinaryArr, binaryArr, 0, 4);
	printArray(opcodeFunc->functBinaryArr, 5);
}












