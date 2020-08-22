 #include "Interface.h"



static struct symbolTable *symbol_table;
static struct addressTable *addresstable;
static struct dataTable *data_table;

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

static struct {
	int IC,
		DC,
		Pass_num;
}state;

int main(int argc, char* argv[])
{
	/*run_test();*/

	char file_to_read[MEM] = "";         /* file name that i read from*/
	char line_read[BUFFERSIZE] = "";     /* digit number string*/
	char *output = "";                   /* output from the user */
	BOOL is_file_read_exist = False,     /* is the file that i read from exist?*/
		is_file_write_exist = False;    /* is the file that i write to exist?*/
	FILE* filePointer;
	struct operationFunc opcodeFunc;

	int  nargin = argc;                  /* number of input in */

	state.DC = 0;
	state.IC = 100;
	state.Pass_num = 1;

	symbol_table = symbolTable_create();
	addresstable = addressTable_create();
	data_table = dataTable_create();


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
	
	/* first pass*/
	do {
		printf("\n%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, BUFFERSIZE, filePointer);
		if (output != NULL) {
			first_pass(output);
		}
	} while (output != NULL);

	
	/* second pass*/
	filePointer = fopen(file_to_read, "r");
	state.DC = 0;
	state.IC = 99;
	state.Pass_num = 2;
	do {
		printf("\n%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, BUFFERSIZE, filePointer);
		if (output != NULL) {
			second_pass(output);
		}
	} while (output != NULL);

	getchar();


	return 0;
}

void writeObFile() {

	int address = 100;
	struct addressData data;
	/* get number of command*/

	/* convert  num to string */

	/* get number of data */

	/* convert  data num to string */

	/* write text row*/
	/*-------------------------*/

	for (address = 100; address < 133; ++address) {
		/* get address*/

		/* get binary machine code*/

		/* convert addres to string*/

		/* convert binary machine code to hexadecimal sring*/

		/* concatinate to one row */

		/* write text row*/

	}
}



void first_pass(char command_original[]) {

	
	char *command_section = "", *next_command = "",
		command[MEM] = "",
		command_left[MEM], input_str[MEM];
	BOOL end_line = False, isFlag;
	struct operationFunc opcodeFunc;
	TypeSymbol type_symbol;

	strcpy(command, command_original);
	strcpy(command_left, command_original);

	
 
	while (end_line != True) {

		remove_substring(&command_left, command_section);
		strcpy(command, command_left);
		/* parse the command into 5 category */
		command_section = strtok(command, seperator);

		if (command_section == NULL || assertIsEmpty(command_section)) {
			/* Empty sentence ?*/
			end_line = True;
		}

		else if (command_section[0] == ';') {
			/* comment sentence */
			end_line = True;
		}

		else if (assert_command(command_section, &flag_legal, 6, "")) {
			/* ist asymbol */
			
			next_command = strtok(NULL, seperator);

			if (assert_command(next_command, &instructionType, 16, "")) {
				type_symbol = code;
			}
			else if (assert_command(next_command, &guidanceType, 4, "")) {
				type_symbol = data;

			}

			flag_manger(command_section, state.IC, type_symbol);
			 
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

void second_pass(char command_original[]) {


	char *command_section = "",
		command[MEM] = "",
		command_left[MEM], input_str[MEM];
	BOOL end_line = False, isFlag;
	struct operationFunc opcodeFunc;
	strcpy(command, command_original);
	strcpy(command_left, command_original);
	

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
			 /* this is flag*/
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
			end_line = True;
		}

	}

}



void flag_manger(char symbol[], int address, TypeSymbol type) {
	static int number_update = 0;
	++number_update;



	if (number_update == 1) {
		update_symbol_table(symbol_table, symbol, address, type);
	}
	else {
		/* insert the flag in the table flage  - link list */
		push_symbol_table(symbol_table, symbol, address, type);
	}
}

void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc) {

	

	printf("\nthis is function: %s\n", fun);
	printf("\nthis is input: %s\n", input_str);

	table_funct_opcode(fun, opcodeFunc);
	set_operation_command(fun, input_str, opcodeFunc);


}


void create_space_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc) {

	int *binaryArray;
	int  binary_machine_code[bitrray];
	int i = 0, j = 0;

 
	push_operationFunc(addresstable, &state.IC);

	if (setup.firstValue.value != NULL) {
		set_space_binary_machine_code(setup.firstType);
	}

	if (setup.secondValue.value != NULL) {
		set_space_binary_machine_code(setup.secondType);
	}




}

void set_space_binary_machine_code(AdressType type) {


	switch (type)
	{
	case (Immediate):

		push_operationFunc(addresstable, &state.IC);
		break;

	case (Direct):

		push_operationFunc(addresstable, &state.IC);
		break;
	case (Relative):

		push_operationFunc(addresstable, &state.IC);
		push_operationFunc(addresstable, &state.IC);

		break;
	case (Register_Direct):

		break;

	default:
		break;
	}
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
	update_operationFunc(addresstable,++state.IC, binary_machine_code);

	if (setup.firstValue.value != NULL) {
		update_binary_machine_code(setup.firstType, setup.firstValue, opcodeFunc->ARE);
	}

	if (setup.secondValue.value != NULL) {
		update_binary_machine_code(setup.secondType, setup.secondValue, opcodeFunc->ARE);
	}


}

 
void update_binary_machine_code(AdressType type, polymorfType st, ARE are) {
		
	int *binaryArray;
	int  binary_machine_code[bitrray], 
		address_symbol;
	struct symbolData symbol_data;


	zeros(&binary_machine_code, bitrray);
		switch(type)
		{
		case (Immediate):
			binaryArray = decimal2binaryArray(st.value, 21);
			arrayAssign(&binary_machine_code, binaryArray, INDEX(23), INDEX(3));
			arrayAssign(&binary_machine_code, are.x, INDEX(2), INDEX(0));
			printArray(binary_machine_code, bitrray);
			update_operationFunc(addresstable,  ++state.IC,&binary_machine_code);
			break;

		case (Direct):

			/* get the label data*/
			symbol_data = get_symbol_data(symbol_table, st.label);

			binaryArray = decimal2binaryArray(symbol_data.address, 21);
			arrayAssign(&binary_machine_code, binaryArray, INDEX(23), INDEX(3));
			/*ARE */
			/* if internal ARE = 010*/
			if (symbol_data.isInternal) {
				are.x[0] = False; are.x[1] = True; are.x[2] = False;
			}
			else {
				/* f external ARE = 001*/
				are.x[0] = False; are.x[1] = False; are.x[2] = True;
			}
			arrayAssign(&binary_machine_code, are.x, INDEX(2), INDEX(0));
			printArray(binary_machine_code, bitrray);
			update_operationFunc(addresstable, ++state.IC, &binary_machine_code);
			break;



			break;
		case (Relative):
			/* get the label data*/
			symbol_data = get_symbol_data(symbol_table, st.label);
			/* jump curent */
			binaryArray = decimal2binaryArray(symbol_data.address - state.IC, 21);
			arrayAssign(&binary_machine_code, binaryArray, INDEX(23), INDEX(3));
			/*ARE */
			are.x[0] = True;
			are.x[1] = False;
			are.x[2] = False;

			arrayAssign(&binary_machine_code, are.x, INDEX(2), INDEX(0));
			printArray(binary_machine_code, bitrray);
			update_operationFunc(addresstable, ++state.IC, &binary_machine_code);
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
		push_operationFunc(addresstable, & state.IC);
		push_update_data_table(data_table, &state.DC, var, binaryArr);
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
		push_update_operationFunc(addresstable, &state.IC, binaryArr);
		
	    push_update_data_table(data_table, &state.DC, var, binaryArr);
		 
	}

}

void extern_sentence(char var[]) {

}

void entry_sentence(char var[]) {

}

void update_or_insert_machine_code(struct setupRegistretion register_setup, struct operationFunc *opcodeFunc) {

	switch (state.Pass_num) {
	case 1:
		create_space_binary_machine_code(register_setup, opcodeFunc);
		break;
	case 2:
		set_binary_machine_code(register_setup, opcodeFunc);
		break;


	}

}
int * createBinaryArray(struct operationFunc *opcodeFunc) {

	int binaryArray[24];
	zeros(&binaryArray, 24);
	/*ARE*/
	arrayAssign(binaryArray, opcodeFunc->ARE.x, INDEX(2), INDEX(0));

	/*funct*/
	arrayAssign(binaryArray, opcodeFunc->functBinaryArr, INDEX(7), INDEX(3));

	/* register Destination */
	arrayAssign(binaryArray, opcodeFunc->registerDestination, INDEX(10), INDEX(8));

	/* address Destination */
	arrayAssign(binaryArray, opcodeFunc->addressDestination, INDEX(12), INDEX(11));

	/* register source */
	arrayAssign(binaryArray, opcodeFunc->registerSource, INDEX(15), INDEX(13));

	/* address source */
	arrayAssign(binaryArray, opcodeFunc->addressSource, INDEX(17), INDEX(16));

	/* opcode */
	arrayAssign(binaryArray, opcodeFunc->opcodeBinaryArr, INDEX(23), INDEX(18));

	return binaryArray;

}


struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc) {

	char *inputs;
	char command_input[MEM] = "";  /* copy of input string */
								   /* number of input argument*/
	int *binaryArr;
	int input_num = 0;
	Register *regi;

	struct setupRegistretion inputRegistretion;
	strcpy(command_input, nargin_str);

	/* set defult values*/
	resetValues(&inputRegistretion, opcodeFunc);

	/* check for number of inputs */
	input_num = inputs_check(nargin_str, ',');
	inputs = strtok(command_input, ",");

	if (input_num == 2) {
		/* first input*/
	
		inputRegistretion.firstType = getAddresingType(inputs);

		binaryArr = decimal2binaryArray((int)inputRegistretion.firstType, 2);
		arrayAssign(opcodeFunc->addressSource, binaryArr, 0, 1);
		switch (inputRegistretion.firstType) {

		case Immediate:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
			/* value*/
			inputRegistretion.firstValue.value = atoi(inputs);
			printf("%d", inputRegistretion.firstValue.value);
			break;

		case Direct:
			
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
			/* copy value*/
			strcpy(inputRegistretion.firstValue.label, inputs);

			break;

		case Relative:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
			break;

		case Register_Direct:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

			regi = getRegisterVar(inputs);
			inputRegistretion.firstValue.Register = regi[0];
			binaryArr = decimal2binaryArray((int)inputRegistretion.firstValue.Register, 3);
			arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);
			break;
		}

	
	/* second input*/
	inputs = strtok(NULL, ",");
	}

	if (inputs != NULL) {

		inputRegistretion.secondType = getAddresingType(inputs);

		binaryArr = decimal2binaryArray((int)inputRegistretion.secondType, 2);
		arrayAssign(opcodeFunc->addressDestination, binaryArr, 0, 1);
		switch (inputRegistretion.secondType) {
        
		case Immediate:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
			/* value*/
			inputRegistretion.secondValue.value = atoi(inputs);
			break;
		
		case Direct:

			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

			/* copy value*/
			strcpy(inputRegistretion.secondValue.label, inputs);

			break;

		case Relative:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);
			strcpy(inputRegistretion.secondValue.label, inputs);
			break;

		case Register_Direct:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

			regi = getRegisterVar(inputs);
			inputRegistretion.secondValue.Register = regi[0];
			binaryArr = decimal2binaryArray((int)inputRegistretion.secondValue.Register, 3);
			arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
		}



	}
	else {


	}
	return inputRegistretion;

}


void resetValues(struct setupRegistretion *inputRegistretion,struct operationFunc *opcodeFunc) {

	int *binaryArr;

	inputRegistretion->firstValue.value  = NULL;
	inputRegistretion->secondValue.value = NULL;

	/* reset  source*/
	binaryArr = decimal2binaryArray(0, 2);
	arrayAssign(opcodeFunc->addressDestination, binaryArr, 0, 1);

	binaryArr = decimal2binaryArray(0, 2);
	arrayAssign(opcodeFunc->addressSource, binaryArr, 0, 2);
	
	/* reset  register*/
	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign(opcodeFunc->registerSource, binaryArr, 0, 2);

	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign(opcodeFunc->registerDestination, binaryArr, 0, 2);
	
	/*ARE*/
	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign(opcodeFunc->ARE.x, binaryArr, 0, 2);

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

	else if (inputString[0] == andTag[0] ) {

		remove_substring_parts(inputString, andTag);

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

