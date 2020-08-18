#include "interface.h"

static struct flagTable *l;
static struct addressTable *addresstable;

Register R0 = r0, R1 = r1, R2 = r2,
R3 = r3, R4 = r4, R5 = r5,
R6 = r6, R7 = r7;

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
	addresstable = addressTable_create();


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

	do {
		printf("%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, BUFFERSIZE, filePointer);
		if (output != NULL) {
			command_manager(output);
		}
	} while (output != NULL);



	getchar();

	return 0;
}

void command_manager(char command_original[]) {

	static int IC = 100,DC = 0;
	char *command_section = "",
		command[MEM] = "",
		command_left[MEM], input_str[MEM];
	BOOL end_line = False, isFlag;
	struct operationFunc opcodeFunc;
	strcpy(command, command_original);
	strcpy(command_left, command_original);
	IC++;

	while (end_line != True) {

		remove_substring(&command_left, command_section);
		strcpy(command, command_left);
		/* parse the command into 5 category */
		command_section = strtok(command, seperator);

		if (command_section == NULL || assertIsEmpty(command_section)) {
			/* Empty sentence ?*/
			end_line = True;
		}
		else if (assert_command(command_section, &flag_legal, 6, "")) {
			/* ist aflag? */
			flag_manger(command_section, IC);
		}
		 
		else if (command_section[0] == ';') {
			
			/* comment sentence */
			end_line = True;
		}
		else if (assert_command(command_section, &instructionType, 16, ""))
		{
			/*Instructional sentence*/
			remove_substring(&command_left, command_section);
			remove_substring_parts(&command_left, seperator);

			instructional_sentence(command_section, command_left, &opcodeFunc);
			end_line = True;

		}
		else if (assert_command(command_section, &guidanceType, 4, ""))
		{
			/* Guidance sentence */
			remove_substring(&command_left, command_section);
			remove_substring_parts(&command_left, seperator);

			guidance_sentence(command_section, command_left);
			end_line = True;
		}

	}

}

void flag_manger(char flag[], int value) {
	static int number_update = 0;
	++number_update;
	printf("\nthis is flag: %s\n", flag);
	if (number_update == 1) {
		update_flag_table(l, flag, value);
	}
	else {
		/* insert the flag in the table flage  - link list */
		push_flag_table(l, flag, value);
	}
}

void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc) {

	int *binaryArray;

	printf("\nthis is function: %s\n", fun);
	printf("\nthis is input: %s\n", input_str);

	table_funct_opcode(fun, opcodeFunc);
	set_operation_command(fun, input_str, opcodeFunc);

	binaryArray = createBinaryArray(opcodeFunc);

	push_operationFunc(addresstable , binaryArray);

}


void guidance_sentence(char varType[], char var[]) {

	printf("\nthis is varType: %s\n", varType);

	printf("\nthis is var: %s\n", var);
	if (strcmp(varType, ".string") == 0) {
		
		string_sentence(var);
	}
	else if (strcmp(varType, ".data") == 0) {
		
		data_sentence(var);
	}
	else if (strcmp(varType, ".extern") == 0) {
		
		extern_sentence(var);
	}
	else if (strcmp(varType, ".entry") == 0) {
		
		entry_sentence(var);
	}

}

void string_sentence(char var[]) {

	int length;
	int i = 0,
		ascii;
	int *binaryArr;
	const char seperetor[] = { '/','"' };
	
	remove_substring_parts(var, seperetor);
	length = strlen(var);

	for (i; i <= length; ++i) {
		/* convert to Ascii number*/
		ascii = (int)var[i];
		/* convert to binary array*/
		binaryArr = decimal2binaryArray(ascii, bitrray);
		printf("%c:\t", var[i]);
		printArray(binaryArr, bitrray);
		/* pushe data to the table  */
		push_operationFunc(addresstable, binaryArr);
	}

}

void data_sentence(char var[]) {

	 
	int i ;
	int *binaryArr,
		*arr, *length[1] ;
	int len = 0;

	arr = string2array(var,&length);
	len = (int)length[0];
	printArray(arr,len);
	for (i = 0; i<len; ++i) {
       
		/* convert to binary array*/
		binaryArr = decimal2binaryArray(arr[i], bitrray);
		printArray(binaryArr, bitrray);
		/* pushe data to the table  */
		push_operationFunc(addresstable, binaryArr);
		 
	}

}

void extern_sentence(char var[]) {



}


void entry_sentence(char var[]) {



}

int * createBinaryArray(struct operationFunc *opcodeFunc) {

	int binaryArray[24];
	zeros(&binaryArray, 24);
	/*ARE*/
	arrayAssign(binaryArray, opcodeFunc->ARE.x, 0, 2);
	printArrayReverse(binaryArray, 24);

	/*funct*/
	arrayAssign(binaryArray, opcodeFunc->functBinaryArr, 3, 7);
	printArrayReverse(binaryArray, 24);

	/* register Destination */
	arrayAssign(binaryArray, opcodeFunc->registerDestination, 8, 10);
	printArrayReverse(binaryArray, 24);

	/* address Destination */
	arrayAssign(binaryArray, opcodeFunc->addressDestination, 11, 12);
	printArrayReverse(binaryArray, 24);

	/* register source */
	arrayAssign(binaryArray, opcodeFunc->registerSource, 13, 15);
	printArrayReverse(binaryArray, 24);

	/* address source */
	arrayAssign(binaryArray, opcodeFunc->addressSource, 16, 17);
	printArrayReverse(binaryArray, 24);

	/* opcode */
	arrayAssign(binaryArray, opcodeFunc->opcodeBinaryArr, 18, 23);
	printArrayReverse(binaryArray, 24);

	return binaryArray;

}



void set_operation_command(char func[], char input_str[], struct operationFunc *opcodeFunc) {

	if (strcmp(func, "mov") == 0) {

		mov_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "cmp") == 0) {

		cmp_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "add") == 0) {

		add_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "sub") == 0) {

		sub_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "lea") == 0) {

		lea_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "clr") == 0) {

		clr_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "not") == 0) {

		not_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "inc") == 0) {

		inc_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "dec") == 0) {

		dec_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "jmp") == 0) {

		jmp_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "bne") == 0) {

		bne_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "jsr") == 0) {

		jsr_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "red") == 0) {

		red_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "prn") == 0) {

		prn_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "rts") == 0) {

		rts_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "stop") == 0) {

		stop_from_user(input_str, opcodeFunc);
	}

}


void mov_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void cmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void add_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	twoInputRegistretion *inputs;
	int *binaryArr;

	inputs = set_address_register(nargin_str, opcodeFunc);
	if (inputs->call_operation == True) {

		add(inputs->firstInput, &inputs->secondInput);
		binaryArr = decimal2binaryArray((int)inputs->secondInput, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}
}



struct twoInputRegistretion* set_address_register(char nargin_str[], struct operationFunc *opcodeFunc) {

	char *firstInput, *secondInput;
	char command_input[MEM] = "";  /* copy of input string */
	int nargin = 2;               /* number of input argument*/
	int addressType_first, addressType_second;
	int *binaryArr;
	Register *regi;
	twoInputRegistretion inputRegistretion;
	inputRegistretion.call_operation = False;

	strcpy(command_input, nargin_str);

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	/* first input*/
	firstInput = strtok(command_input, ",");
	addressType_first = cheakAddresingType(firstInput);

	binaryArr = decimal2binaryArray(addressType_first, 2);
	arrayAssign(opcodeFunc->addressSource, binaryArr, 0, 1);

	if (addressType_first == 3) {
		regi = getRegisterVar(firstInput);
		inputRegistretion.firstInput = regi;
		binaryArr = decimal2binaryArray((int)*regi, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}
	/* second input*/
	secondInput = strtok(NULL, ",");
	addressType_second = cheakAddresingType(secondInput);

	binaryArr = decimal2binaryArray(addressType_second, 2);
	arrayAssign(opcodeFunc->addressDestination, binaryArr, 0, 1);

	if (addressType_second == 3) {
		regi = getRegisterVar(firstInput);
		binaryArr = decimal2binaryArray(regi, 3);
		arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
	}
	else {
		/* defult fill zeros */
		binaryArr = decimal2binaryArray(0, 3);
		arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
	}
	return &inputRegistretion;

}



void sub_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void lea_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void clr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void not_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void inc_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void dec_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void jmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void bne_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void jsr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void red_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void prn_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

void rts_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void stop_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

int cheakAddresingType(char inputString[]) {

	int addresingType = NULL;


	if (char_apperance(inputString, '#') == 1) {
		strtok(inputString, '#');
		if (isdigit(inputString) == 1) {

			addresingType = 0;
		};
	}


	else if (assert_command(inputString, flag_legal, 6, "")) {
		addresingType = 1;

	}

	else if (char_apperance(inputString, '&') == 1) {
		strtok(inputString, '&');
		if (assert_command(inputString, flag_legal, 6, "")) {

			addresingType = 2;
		}
	}
	else if (assert_command(inputString, register_leagal, 8, "")) {

		addresingType = 3;
	}

	return addresingType;

}


/* get Register name and return Register pointer to the Register varible */
Register* getRegisterVar(char registerName[]) {

	int i;
	for (i = 0; LEN_Register > i; i++) {
		if (strcmp(registerDictionary[i].name, registerName) == 0) {
			return registerDictionary[i].reg;
		}
	}

	return registerDictionary[LEN_Register].reg;
}

























