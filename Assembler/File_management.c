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
	  commands = size_list_address_table(addresstable);
	  instruction = INITIAL_ADDRESS + commands;

	/* get number of data */
	  data_size = size_list_data_table(dataTable);
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


void write_ent_file(char fileName[], struct symbolTable* symboltable) {

	int address = 100;
	struct addressData data;
	char *straddress = "";
	char text[15] = "";

	for (address = 100; address < 133; ++address) {
		/* initilize text*/
		strcpy(text, "");
		/* get address*/

	}
}
