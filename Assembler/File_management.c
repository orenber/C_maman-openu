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

void write_ob_file(char fileName[], struct addressTable* addresstable) {

	int address = 100;
	struct addressData data;
	char *hexadecimal="",
		*straddress ="";
	char text[15] = "";
	
	/* get number of command*/

	/* convert  num to string */

	/* get number of data */

	/* convert  data num to string */

	/* write text row*/
	/*-------------------------*/

	for (address = 100; address < 133; ++address) {
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
