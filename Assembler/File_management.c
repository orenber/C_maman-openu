#include "interface.h"


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
