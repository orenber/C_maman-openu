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

	

	printf("\nthis is function: %s\n", fun);
	printf("\nthis is input: %s\n", input_str);

	table_funct_opcode(fun, opcodeFunc);
	set_operation_command(fun, input_str, opcodeFunc);


}


void create_binary_machine_code(struct operationFunc *opcodeFunc) {

	int *binaryArray;

	binaryArray = createBinaryArray(opcodeFunc);

	push_operationFunc(addresstable, binaryArray);




}

void set_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc) {


	int *binaryArray  ;
	int  binary_machine_code[bitrray];
	int i = 0,  j = 0;

	zeros(&binary_machine_code, bitrray);

	binaryArray =  createBinaryArray(opcodeFunc);
	
	for ( i = 0, j = 0; bitrray - 1 >= i; ++i, j++) {
		binary_machine_code[i] = binaryArray[j];

	};
	/*arrayAssign(binary_machine_code, binaryArray, 0, 23);*/
	printArray(binary_machine_code, bitrray);
	push_operationFunc(addresstable, binary_machine_code);

	if (setup.firstValue.value != NULL) {
		insert_binary_machine_code(setup.firstType, setup.firstValue, opcodeFunc->ARE);
	}

	if (setup.secondValue.value != NULL) {
		insert_binary_machine_code(setup.secondType, setup.secondValue, opcodeFunc->ARE);
	}


}

void insert_binary_machine_code(AdressType type, polymorfType st, ARE are) {
		
	int *binaryArray;
	int  binary_machine_code[bitrray];
	zeros(&binary_machine_code, bitrray);

		switch(type)
		{
		case (Immediate):
			binaryArray = decimal2binaryArray(st.value, 21);
			arrayAssign(&binary_machine_code, binaryArray, INDEX(23), INDEX(3));
			arrayAssign(&binary_machine_code, are.x, INDEX(2), INDEX(0));
			printArray(binary_machine_code, bitrray);
			push_operationFunc(addresstable, &binary_machine_code);
			break;

		case (Direct):
			binaryArray = decimal2binaryArray(0, 21);
			arrayAssign(&binary_machine_code, binaryArray, INDEX(23), INDEX(3));
			/*ARE */

			arrayAssign(&binary_machine_code, are.x, INDEX(2), INDEX(0));
			printArray(binary_machine_code, bitrray);
			push_operationFunc(addresstable, &binary_machine_code);
			break;
		case (Relative):

			break;
		case (Register_Direct):

			break;

		default:
			break;
		}
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
	arrayAssign(binaryArray, opcodeFunc->ARE.x, INDEX(2), INDEX(0));
	printArray(binaryArray, 24);

	/*funct*/
	arrayAssign(binaryArray, opcodeFunc->functBinaryArr, INDEX(7), INDEX(3));
	printArray(binaryArray, 24);

	/* register Destination */
	arrayAssign(binaryArray, opcodeFunc->registerDestination, INDEX(10), INDEX(8));
	printArray(binaryArray, 24);

	/* address Destination */
	arrayAssign(binaryArray, opcodeFunc->addressDestination, INDEX(12), INDEX(11));
	printArray(binaryArray, 24);

	/* register source */
	arrayAssign(binaryArray, opcodeFunc->registerSource, INDEX(15), INDEX(13));
	printArray(binaryArray, 24);

	/* address source */
	arrayAssign(binaryArray, opcodeFunc->addressSource, INDEX(17), INDEX(16));
	printArray(binaryArray, 24);

	/* opcode */
	arrayAssign(binaryArray, opcodeFunc->opcodeBinaryArr, INDEX(23), INDEX(18));
	printArray(binaryArray, 24);

	return binaryArray;

}


struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc) {

	char *firstInput, *secondInput;
	char command_input[MEM] = "";  /* copy of input string */
								   /* number of input argument*/
	int *binaryArr;
	Register *regi;

	struct setupRegistretion inputRegistretion;


	strcpy(command_input, nargin_str);


	/* first input*/
	firstInput = strtok(command_input, ",");
	inputRegistretion.firstType = getAddresingType(firstInput);

	binaryArr = decimal2binaryArray((int)inputRegistretion.firstType, 2);
	arrayAssign(opcodeFunc->addressSource, binaryArr, 0, 1);
	switch (inputRegistretion.firstType) {

	case Immediate:
		/*ARE*/
		binaryArr = decimal2binaryArray(4, 3);
		arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
		/* value*/
		inputRegistretion.firstValue.value = atoi(firstInput);
		printf("%d", inputRegistretion.firstValue.value);
		break;
	case Relative:
		/*ARE*/
		binaryArr = decimal2binaryArray(4, 3);
		arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
		break;
	case Direct:
		/*ARE*/
		/* defult fill zeros */
		binaryArr = decimal2binaryArray(0, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
		/* copy value*/
		strcpy(inputRegistretion.firstValue.label, firstInput);

		break;
	case Register_Direct:
		/*ARE*/
		binaryArr = decimal2binaryArray(4, 3);
		arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

		regi = getRegisterVar(firstInput);
		inputRegistretion.firstValue.Register = regi[0];
		binaryArr = decimal2binaryArray((int)inputRegistretion.firstValue.Register, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
		break;
	}
	/* second input*/
	secondInput = strtok(NULL, ",");

	if (secondInput != NULL) {

		inputRegistretion.secondType = getAddresingType(secondInput);

		binaryArr = decimal2binaryArray((int)inputRegistretion.secondType, 2);
		arrayAssign(opcodeFunc->addressDestination, binaryArr, 0, 1);
		switch (inputRegistretion.secondType) {

		case Relative:

			break;
		case Immediate:
			/* defult fill zeros */
			binaryArr = decimal2binaryArray(0, 3);
			arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
			break;

		case Direct:

			/* defult fill zeros */
			binaryArr = decimal2binaryArray(0, 3);
			arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
			/* copy value*/
			strcpy(inputRegistretion.secondValue.label, secondInput);
			break;
		case Register_Direct:
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

			regi = getRegisterVar(secondInput);
			inputRegistretion.secondValue.Register = regi[0];
			binaryArr = decimal2binaryArray((int)inputRegistretion.secondValue.Register, 3);
			arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
		}



	}
	else {

		inputRegistretion.secondValue.value = NULL;

		binaryArr = decimal2binaryArray(0, 2);
		arrayAssign(opcodeFunc->addressDestination, binaryArr, 0, 1);

		binaryArr = decimal2binaryArray(0, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);

		binaryArr = decimal2binaryArray(0, 3);
		arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
	}
	return inputRegistretion;

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
	
	struct setupRegistretion register_setup;
	BOOL call_operation = False;
	int *binaryArr;
	int nargin = 2;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	if (call_operation == True) {

		mov(register_setup.firstType, &register_setup.secondType);
		binaryArr = decimal2binaryArray((int)register_setup.secondValue.Register, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void cmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	BOOL call_operation = False;
	int *binaryArr;
	int nargin = 2;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	if (call_operation == True) {

		cmp(register_setup.firstType, &register_setup.secondType);
		binaryArr = decimal2binaryArray((int)register_setup.secondValue.Register, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void add_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	BOOL call_operation = False;
	int *binaryArr;
	int nargin = 2;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	if (call_operation == True) {

		add(register_setup.firstType, &register_setup.secondType);
		binaryArr = decimal2binaryArray((int)register_setup.secondValue.Register, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}

	set_binary_machine_code(register_setup, opcodeFunc);
 
	
}

void sub_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	BOOL call_operation = False;
	int *binaryArr;
	int nargin = 2;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	if (call_operation == True) {

		sub(register_setup.firstType, &register_setup.secondType);
		binaryArr = decimal2binaryArray((int)register_setup.secondValue.Register, 3);
		arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void lea_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 2;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	if (call_operation == True) {

		lea(register_setup.firstValue.Register, register_setup.firstValue.value);
		/* TODO: add adjusment*/
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void clr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		clr(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void not_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		not(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void inc_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		inc(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void dec_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		dec(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void jmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		jmp(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void bne_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		bne(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void jsr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		jsr(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void red_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation = False;

	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* condition for call function*/
	call_operation = (register_setup.firstType == Register_Direct) ? True : False;

	if (call_operation == True) {

		red(&register_setup.firstValue.Register);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}


void prn_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	int *binaryArr;
	BOOL call_operation;
	int nargin = 1;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	call_operation = (register_setup.firstValue.value) != NULL ? True : False;

	if (call_operation == True) {

		prn(register_setup.firstValue.value);
	}

	set_binary_machine_code(register_setup, opcodeFunc);

}

void rts_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}


void stop_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {


}

AdressType getAddresingType(char inputString[]) {

	AdressType addresingType;
	const char hashTag[] = "#";
	const char andTag[] = "&";


	if (char_apperance(inputString, hashTag[0]) == 1) {
		remove_substring_parts(inputString, hashTag);
		if (assert_number(inputString)) {

			addresingType = Immediate;
		};
	}


	else if (assert_command(inputString, flag_legal, 6, "")) {
		addresingType = Direct;

	}

	else if (char_apperance(inputString, andTag[0]) == 1) {
		strtok(inputString, andTag);
		if (assert_command(inputString, flag_legal, 6, "")) {

			addresingType = Relative;
		}
	}
	else if (assert_command(inputString, register_leagal, 8, "")) {

		addresingType = Register_Direct;
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

