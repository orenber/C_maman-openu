/* ***********************************************************************
Assembly         :
Author           : Oren Berkovitch
Created          : 22-07-2020
Last Modified By : Oren Berkovitch
Last Modified On : 31-08-2020
***********************************************************************
<summary>
 
</summary>
**********************************************************************
*/

#include "assembler.h"


static struct symbolTable *symbol_table;
static struct memoryTable *memory_table;
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

struct STATE state;
struct ERROR_HANDLER valid;


int main(int argc, char* argv[])
{

	int filesNumber = 1;
	FILE *filepointer = NULL; 
	
	
	while (argv[filesNumber] != NULL) {

		 
		filepointer = open_files(argc, argv[filesNumber]);
		analize_files(filepointer, argv[filesNumber++]);
		 
		 
	}

	return 0;

}

void analize_files(FILE *filePointer,char filename[]) {

	strcpy(valid.file_name, filename);
	 
	first_pass(filePointer);
	if (!valid.pass_successful) {
		printError(GENERAL);
		return;
	}
	 
	/*print_memory_table(memory_table);*/

	second_pass(filePointer);

	create_files_output(filename, memory_table, data_table, symbol_table);
	
	free_memory();

}



void first_pass(FILE* filePointer) {

	char line_read[MAX_LINE_WIDTH] = "";     /* digit number string*/
	char *output; /* output from the user */

	valid.line_num = 0;
	valid.pass_num = 1;
	valid.pass_successful = True;

    state.DC = 0;
	state.IC = 100;
	
	 
	/* first pass*/
	do {
		/*printf("%d %s\n ", valid.line_num, line_read );*/
		/* get the input from the file - read line by line*/
		output = fgets(line_read, MAX_LINE_WIDTH, filePointer);
		if (output != NULL) {
			valid.line_num++;
			
			commands_first_pass(output);
		}
	} while (output != NULL);

	/* update final position */
	state.ICF = state.IC;
	state.DCF = state.DC;

	/*print_symbol_table(symbol_table);*/
	/*print_data_table(data_table);*/
	/*print_memory_table(memory_table);*/
	if (valid.pass_successful) {
		update_symbol_table_address(symbol_table, data, state.ICF);
		/*print_symbol_table(symbol_table);*/
		update_memory_table_from_data_table(&memory_table, data_table, state.ICF);
	}
	/*print_data_table(data_table);*/
	/*print_memory_table(memory_table);*/

}

void commands_first_pass(char command_original[]) {

	
	char *command_section="" , *next_command="",
		command[MAX_LINE_WIDTH],
		command_left[MAX_LINE_WIDTH];
	BOOL end_line = False;
	struct operationFunc opcodeFunc;
	TypeSymbol type_symbol;

	
	strcpy(command, command_original);
	strcpy(command_left, command_original);

	
	
	while (end_line != True) {

		remove_substring(command_left, command_section);
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


		else if (assert_command(command_section, instructionType, INSTRUCTION_NUM, ""))
		{
			/*Instructional sentence*/
			remove_substring(command_left, command_section);
			remove_substring_parts(command_left, seperator);

			instructional_sentence(command_section, command_left, &opcodeFunc);
			
			end_line = True;

		}

		else if (assert_command(command_section, guidanceType, GUIDANCE_NUM, ""))
		{
			/* Guidance sentence */
			remove_substring(command_left, command_section);
			

			guidance_sentence(command_section, command_left);
			end_line = True;
		}

		else if (is_legal_label(command_section)) {
			/* ist asymbol */

			next_command = strtok(NULL, seperator);

			if (assert_command(next_command, instructionType, INSTRUCTION_NUM, "")) {
				type_symbol = code;
			}
			else if (assert_command(next_command, guidanceType, GUIDANCE_NUM, "")) {
				type_symbol = data;

			}
			
			flag_manger(command_section, type_symbol);

		}
		else {

			printError(CANNOT_PARSE_LINE);
			end_line = True;
		}

	}

}

void second_pass(FILE* filePointer) {
	

	char line_read[MAX_LINE_WIDTH] = "";     /* digit number string*/
	char *output ;                   /* output from the user */

	/* second pass*/
	valid.pass_num = 2;
	valid.line_num = 0;
	
	state.DC = 0;
	state.IC = 99;
	

	/* reset line read*/
	fseek(filePointer, 0, SEEK_SET);
	do {
		printf("\n%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, MAX_LINE_WIDTH, filePointer);
		if (output != NULL) {
	
			valid.line_num++;
			commands_second_pass(output);
			
		}
	} while (output != NULL);

	

	print_memory_table(memory_table);
	print_symbol_table(symbol_table);




}

void commands_second_pass(char command_original[]) {


	char *command_section = "";
	char command[MAX_LINE_WIDTH] = "",
		command_left[MAX_LINE_WIDTH];
	BOOL end_line = False;
	struct operationFunc opcodeFunc;

	strcpy(command, command_original);
	strcpy(command_left, command_original);
	

	while (end_line != True) {

		remove_substring(command_left, command_section);
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
		else if (assert_command(command_section, instructionType, INSTRUCTION_NUM, ""))
		{
			/*Instructional sentence*/
			remove_substring(command_left, command_section);
			remove_substring_parts(command_left, seperator);

			instructional_sentence(command_section, command_left, &opcodeFunc);
			end_line = True;

		}
		else if (assert_command(command_section, guidanceType, GUIDANCE_NUM, ""))
		{
			/* Guidance sentence */
			remove_substring(command_left, command_section);
			remove_substring_parts(command_left, seperator);
			 if (strcmp(command_section, ".entry") == 0) {

				entry_sentence(command_left);
			}
			end_line = True;
		}
		
		else
		{
				 
			/* this is flag or somthing else */
				 
		}

	}

}



void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc) {

	table_funct_opcode(fun, opcodeFunc);
	set_operation_command(fun, input_str, opcodeFunc);
	 

}

void guidance_sentence(char varType[], char var[]) {

	 
	if (strcmp(varType, ".string") == 0) {
		
		string_sentence(var);
	}
	else if (strcmp(varType, ".data") == 0) {
		
		data_sentence(var);
	}
	else if (strcmp(varType, ".extern") == 0) {
		
		extern_sentence(var);
	}


}

void flag_manger(char label[], TypeSymbol type) {

	char symbol[NAME + 1];/*  more 1 for extra ':' char*/
	const char sep[] = { ':','\n',' ','\0' };


	strcpy(symbol, label);
	remove_substring_parts(symbol, sep);

	if (!is_legal_symbol(symbol)) {
		printError(INVALID_SYMBOL);
		return;
	}
	/* check if symbol already difine in the symbol table */
	if (is_symbol_exist(symbol_table, symbol)) {
		printError(SYMBOL_ALREADY_EXISTS);
		return;
	}

	/* insert the flag in the table flage  - link list */
	switch (type) {
	case code:
		push_symbol_table(&symbol_table, state.IC, symbol, type, True);
		break;
	case data:
		push_symbol_table(&symbol_table, state.DC, symbol, type, True);
		break;
	case external:
		push_symbol_table(&symbol_table, 0, symbol, type, False);
		break;
	case entry:
		/* will be handel in the second pass*/
		break;

	}


}


void string_sentence(char str[]) {

	int length;
	int i = 0,
		ascii;
	unsigned int *binaryArr;
	const char quats = '"';
	char latter[] = { ' ','\0' };
	
	/* check if ther is quate in the string */
	if (!is_legel_string_data(str)) {

		printError(MISSING_QUATS);
		return;
	}


	str_inside(str, quats);
	remove_substring(str, "\"");
	strtok(str, "\n");
	length = strlen(str);

	for ( ; i <= length; ++i) {
		 
		/* convert to Ascii number*/
		ascii = (int)str[i];
		latter[0] = str[i];
		/* convert to binary array*/
		binaryArr = decimal2binaryArray(ascii, BITARRAY);
		 
		 

		/*push_and_update_memory_table(&memory_table, &state.IC, latter, binaryArr);*/
		push_and_update_data_table(&data_table, &state.DC, latter, binaryArr);
	 
	}

}

void data_sentence(char var[]) {


	int i;
	unsigned int *binaryArr;
	
	int len ;
	const char comma = ',';
	const char sep[] = { ' ','\t','\n','\0' };
        const char seperator[] = {',','\0' };

	remove_substring_parts(var, sep);
	if (!is_legal_number(var)) {
		printError(CANNOT_PARSE_LINE);
		return;
	}
	
	len = char_apperance(var, comma)+1;
	 strtok(var,seperator);

	
         for(i = 0;i<len;++i){
	
		/* convert to binary array*/
		binaryArr = decimal2binaryArray(atoi(var), BITARRAY);
	
		/*sprintf(var, "%d", arr[i]);*/
		/* push data to the table  */

		/*push_and_update_memory_table(&memory_table, &state.IC, var, binaryArr);*/
		push_and_update_data_table(&data_table, &state.DC, var, binaryArr);

                 var = strtok(NULL,seperator);
	 
	}

}

void extern_sentence(char symbol[]) {
	
	char sep[] = {'\n',' ','\0' };
	remove_substring_parts(symbol, sep);
	if (!is_legal_symbol(symbol)) {
		printError(INVALID_SYMBOL);
		return;
	}
	flag_manger(symbol, external);
	
}

void entry_sentence(char symbol[]) {


	/* check if the symbol exist*/
	if (serach_symbol_address(symbol_table, symbol) != -1) {
	   
		/* update symbol table */
		update_symbol_table(symbol_table, symbol, entry, True);
	
	}
	else {
	/* throw exeption */

	}

   
}



void free_memory() {

	free_symbol_table(&symbol_table);
	free_data_table_table(&data_table);
	
	free_memory_table(&memory_table);
	
	
}



unsigned int * createBinaryArray(struct operationFunc *opcodeFunc) {

	unsigned int *binaryArray = calloc(BITARRAY,sizeof(*binaryArray));
	zeros(binaryArray, BITARRAY);
	/*ARE*/
	arrayAssign(binaryArray,  opcodeFunc->ARE.x, INDEX(2), INDEX(0));

	/*funct*/
	arrayAssign(binaryArray,  opcodeFunc->functBinaryArr, INDEX(7), INDEX(3));

	/* register Destination */
	arrayAssign(binaryArray,  opcodeFunc->registerDestination, INDEX(10), INDEX(8));

	/* address Destination */
	arrayAssign(binaryArray,  opcodeFunc->addressDestination, INDEX(12), INDEX(11));

	/* register source */
	arrayAssign(binaryArray,  opcodeFunc->registerSource, INDEX(15), INDEX(13));

	/* address source */
	arrayAssign(binaryArray,  opcodeFunc->addressSource, INDEX(17), INDEX(16));

	/* opcode */
	arrayAssign(binaryArray,  opcodeFunc->opcodeBinaryArr, INDEX(23), INDEX(18));

	return  binaryArray;

}


void update_or_insert_machine_code(struct setupRegistretion register_setup, struct operationFunc *opcodeFunc) {

	if (valid.pass_successful) {

		switch (valid.pass_num) {
		case 1:
			create_space_binary_machine_code(register_setup, opcodeFunc->name);
			break;
		case 2:
			set_binary_machine_code(register_setup,opcodeFunc);
			break;
		}
	}

}

void create_space_binary_machine_code(struct setupRegistretion setup, char instrction_name[]) {
 
	int adress_take_more_space[] = { Immediate, Direct, Relative };

	push_memory_table(&memory_table, &state.IC, instrction_name);

	if (assertIsMember(setup.firstOperand.Type,  adress_take_more_space, 3)) {
		set_space_binary_machine_code(setup.firstOperand.Type, setup.firstOperand.label);
	}

	if (assertIsMember(setup.secondOperand.Type,adress_take_more_space, 3)) {
		set_space_binary_machine_code(setup.secondOperand.Type, setup.secondOperand.label);
	}

}

void update_binary_machine_code(AdressType type, polymorfType st, ARE are) {

	unsigned int *binaryArray;
	unsigned int  binary_machine_code[BITARRAY];
	char label[NAME];
	struct symbolData symbol_data;


	zeros(binary_machine_code, BITARRAY);
	switch (type)
	{
	case (Immediate):
		binaryArray = decimal2binaryArray(st.value, 21);
		arrayAssign( binary_machine_code, binaryArray, INDEX(23), INDEX(3));
		arrayAssign( binary_machine_code,  are.x, INDEX(2), INDEX(0));

		update_memory_table(memory_table, ++state.IC, binary_machine_code);
		break;

	case (Direct):

		/* get the label data*/
		symbol_data = get_symbol_data(symbol_table, st.label);

		binaryArray = decimal2binaryArray(symbol_data.address, 21);
		arrayAssign( binary_machine_code, binaryArray, INDEX(23), INDEX(3));
		/*ARE */
		/* if internal ARE = 010*/
		if (symbol_data.isInternal) {
			are.x[0] = False; are.x[1] = True; are.x[2] = False;
		}
		else {
			/* f external ARE = 001*/
			are.x[0] = False; are.x[1] = False; are.x[2] = True;
		}
		arrayAssign( binary_machine_code, are.x, INDEX(2), INDEX(0));

		update_memory_table(memory_table, ++state.IC, binary_machine_code);
		break;

	case (Relative):
		/* get the label data*/
		strcpy(label, st.label);
		symbol_data = get_symbol_data(symbol_table, strtok(label, "&"));
		/* jump curent */
		binaryArray = decimal2binaryArray(symbol_data.address - state.IC, 21);
		arrayAssign( binary_machine_code,  binaryArray, INDEX(23), INDEX(3));
		/*ARE */
		are.x[0] = True;
		are.x[1] = False;
		are.x[2] = False;

		arrayAssign( binary_machine_code,  are.x, INDEX(2), INDEX(0));

		update_memory_table(memory_table, ++state.IC, binary_machine_code);
		break;
	case (Register_Direct):

		break;

	default:
		break;
	}
}

void set_space_binary_machine_code(AdressType type, char lableName[]) {


	switch (type)
	{
	case (Immediate):

		push_memory_table(&memory_table, &state.IC, lableName);
		break;

	case (Direct):

		push_memory_table(&memory_table, &state.IC, lableName);
		break;
	case (Relative):

		push_memory_table(&memory_table, &state.IC, lableName);

		break;
	case (Register_Direct):

		break;

	default:
		break;
	}
}

void set_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc) {


	unsigned int *binaryArray;
	unsigned int  binary_machine_code[BITARRAY];
	int i , j ;
	int adress_take_more_space[] = { Immediate, Direct, Relative };

	zeros(binary_machine_code, BITARRAY);

	binaryArray = createBinaryArray(opcodeFunc);

	for (i = 0, j = 0; BITARRAY - 1 >= i; ++i, j++) {
		binary_machine_code[i] = binaryArray[j];

	}

	update_memory_table(memory_table, ++state.IC, binary_machine_code);
	/*printArray(binary_machine_code,24);*/
	if (assertIsMember(setup.firstOperand.Type,  adress_take_more_space, 3) == True) {
		update_binary_machine_code(setup.firstOperand.Type, setup.firstOperand, opcodeFunc->ARE);
	}

	if (assertIsMember( setup.secondOperand.Type,  adress_take_more_space, 3)==True) {
		update_binary_machine_code(setup.secondOperand.Type, setup.secondOperand, opcodeFunc->ARE);
	}


}

void resetValues(struct setupRegistretion *setup,struct operationFunc *opcodeFunc) {

	unsigned int *binaryArr;
  
	setup->firstOperand.Type = UNDIFINE;
	setup->secondOperand.Type = UNDIFINE;
	/* reset  source*/
	binaryArr = decimal2binaryArray(0, 2);
	arrayAssign( opcodeFunc->addressDestination, binaryArr, 0, 1);

	binaryArr = decimal2binaryArray(0, 2);
	arrayAssign( opcodeFunc->addressSource,  binaryArr, 0, 2);
	
	/* reset  register*/
	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign( opcodeFunc->registerSource,  binaryArr, 0, 2);

	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign( opcodeFunc->registerDestination,  binaryArr, 0, 2);
	
	/*ARE*/
	binaryArr = decimal2binaryArray(0, 3);
	arrayAssign( opcodeFunc->ARE.x,  binaryArr, 0, 2);

}


AdressType getAddresingType(char inputString[]) {

	AdressType addresingType;
	char str[NAME+1]; /* one more hashtag char*/
    const char hashTag[] = "#";
    const char andTag[] = "&";

	strcpy(str, inputString);

	if (char_apperance(str, hashTag[0]) == 1) {
		remove_substring_parts(str, hashTag);
		if (assert_number(str)) {

			addresingType = Immediate;
		}
	}

	else if (str[0] == andTag[0]) {

		remove_substring_parts(str, andTag);

		if (is_undefine_label(str)) {

			addresingType = Relative;
		}
	}
	else if (assert_command(str, register_leagal, REGISTER_NUM, "")) {

		addresingType = Register_Direct;
	}
	else if (is_undefine_label(str)) {
		
		addresingType = Direct;

	}




	return addresingType;

}

/* get Register name and return Register pointer to the Register varible */
Register* getRegisterVar(char registerName[]) {

	int i;
	for (i = 0; REGISTER_NUM > i; i++) {
		if (strcmp(registerDictionary[i].name, registerName) == 0) {
			return registerDictionary[i].reg;
		}
	}

	return registerDictionary[REGISTER_NUM].reg;
}

