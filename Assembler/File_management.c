#include "File_management.h"


BOOL write_file(char fileName[], char word[], char write_type[]) {
	
	FILE *filePointer;
	BOOL is_file_exist = True;  /* is the file that i write to, exist?*/

	filePointer = fopen(fileName, write_type);

	if (filePointer == NULL)
	{
		is_file_exist = False;
		fprintf(stderr, "file not exist\n Error!");

		exit(1);
	}

	fprintf(filePointer, "%s\n", word);
	fclose(filePointer);

	return is_file_exist;

}

/* <summary>
file_exists - chack if the file name exist
<input>
const char *file_name - file name to check
</input>
<output>
BOOL - output - return if file exist
</output>
</summary>*/
BOOL file_exists(char fileName[])
{
	FILE *file;
	BOOL state;


	if ((file = fopen(fileName, "r")))
	{
		fclose(file);
		state = True;
	}
	else {
		state = False;

		fprintf(stderr, "%s", fileName);
		fprintf(stderr, "-file not exist - Error!\n");

	}
	return state;
}


FILE * open_files(int argc, char fileName[]) {

	char file_to_read[NAME] = "";        /* file name that i read from*/
	BOOL is_file_read_exist = False;    /* is the file that i read from exist?*/
	int  nargin = argc;                  /* number of input in */
	FILE *filePointer = NULL;
										 /* check file name inputs */
	if ((nargin >= 2) && (fileName != NULL)) {

		/* check if the file read exist*/
		is_file_read_exist = file_exists(fileName);
		if (is_file_read_exist == True) {
			filePointer = fopen(fileName, "r");
		}
		else if (is_file_read_exist == False) {
			/* if the file not exist the programe shoude stop*/
			exit(1);
		}
	}
	return filePointer;
}

void create_files_output(char file_to_read[],struct memoryTable *memory_table, struct dataTable *data_table, struct symbolTable *symbol_table) {

	char *file_to_write;         /* file name that i write to */

								 /* .ob */
	file_to_write = strep(file_to_read, ".as", ".ob");
	write_ob_file(file_to_write, memory_table, data_table);

	/* .ent */
	file_to_write = strep(file_to_read, ".as", ".ent");
	write_ent_file(file_to_write, symbol_table);

	/* .ext*/
	file_to_write = strep(file_to_read, ".as", ".ext");
	write_ext_file(file_to_write, symbol_table, memory_table);

}

void write_ob_file(char fileName[], struct addressTable* addresstable,struct dataTable* dataTable) {

	 
	int commands,
		data_size,
		instruction,
		guidlines, address;
	struct addressData data;
	char *hexadecimal="",
		*straddress ="";
	char snum[10];
	char text[15] = "";
	
	/* get number of command*/
	  commands = size_memory_table(addresstable);
	  instruction = INITIAL_ADDRESS + commands;

	/* get number of data */
	  data_size = size_data_table(dataTable);
	  guidlines = commands - data_size;
	 
	  /* convert  num to string */
	  sprintf(snum,"%7d", guidlines);
	  strcat(text, snum);
	  strcat(text, " ");
	  sprintf(snum, "%d", data_size);
	  strcat(text, snum);
	  /* write text row*/
	  write_file(fileName, text, "w");

	/* write text row*/
	/*-------------------------*/

	for (address = INITIAL_ADDRESS; address < instruction; ++address) {
		/* initilize text*/
		strcpy(text,"");
		/* get address*/
		data = get_code_data(addresstable, address);


		/* convert addres to string*/
		straddress = num2string(data.address);
		strcat(text,straddress);

		/* concatinate to one row */
		strcat(text, " ");

		/* convert binary machine code to hexadecimal sring*/
		hexadecimal = binaryArray2Hexadecimal(data.binaryMachineCode, 24);
		strcat(text, hexadecimal);

		/* write text row*/
		write_file(fileName, text, "a");
	}
}


void write_ent_file(char fileName[], struct symbolTable *symboltable) {


	char text[MAX_LINE_WIDTH] = "";

	/* clear text for the first time */
	write_file(fileName, text, "w");

	while (symboltable != NULL) {

		if (symboltable->characterization == entry) {
			
			/* initilize text*/
			strcpy(text, "");
			
			/* convert symbol to text */
			strcat(text, symboltable->symbol);
			strcat(text, " ");
			
			/* convert address to string*/
			strcat(text, num2string(symboltable->address));
			
			/* write text file */
			write_file(fileName, text, "a");

		}
		symboltable = symboltable->next;
	}

	 
}


void write_ext_file(char fileName[],struct symbolTable *symboltable, struct memoryTable *memorytable) {

	char text[MAX_LINE_WIDTH] = "";

	/* clear text for the first time */
	strcpy(text, "");
	write_file(fileName, text, "w");


	while (symboltable != NULL) {
		/* from symbol table find the external symbol*/
		if (symboltable->isInternal == False) {
			
			search_symbol_in_memory_table(fileName, symboltable->symbol, memorytable);
		}
		symboltable = symboltable->next;
	}




}

void search_symbol_in_memory_table(char fileName[], char symbol[], struct memoryTable *memorytable) {
	char text[MAX_LINE_WIDTH] = "";


	while (memorytable != NULL) {
		/* look up for the symbol in the memory table */
		if (strcmp(memorytable->name, symbol) == 0) {

			strcpy(text, "");
			/* convert symbol to text */
			strcat(text, memorytable->name);
			strcat(text, " ");

			/* convert address to string*/
			strcat(text, num2string(memorytable->address));

			/* write text file */
			write_file(fileName, text, "a");


		}
		memorytable = memorytable->next;
	}



}

