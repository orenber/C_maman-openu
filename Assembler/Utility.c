#include "interface.h"

void array2string(int arrayNumber[], char* stringArray) {

	/*detect the size of the array*/
	int index = 0, length = LENGTH(arrayNumber);

	strcpy(stringArray, "");

	/* loop over to create string */
	for (int n = 0; n <= length; ++n) {
		index += sprintf(&stringArray[index], "%d", arrayNumber[n]);
	}
	/* */
	return;

};

int * decimal2binaryArray(int decimalNumber, int digits) {


	int number, divider = 2
		, result;
	int* arr = (int*)calloc(digits, sizeof(int));

	number = decimalNumber;
	for (int n = digits - 1; n >= 0; --n) {

		result = number / divider;
		arr[n] = number % divider;

		number = result;
	}

	return arr;

}

/* <summary> assert_number - parse the number text and check if it is legal number
numberStr - number string..</summary> */
BOOL assert_number(char numberStr[]) {

	BOOL is_number;
	int length = 0,
		i, point = 0;

	length = (int)strlen(numberStr);
	for (i = 0; length > i; i++) {
		if (isdigit(numberStr[i])) {
			is_number = True;
		}
		else if (numberStr[i] == '.') {
			++point;
			/* decimal point should appear only once!*/
			if (point == 1) {
				is_number = True;
			}
			else {
				is_number = False;
				break;
			}
		}
		else if ((numberStr[i] == '+') || (numberStr[i] == '-')) {
			is_number = True;
		}
		else {

			is_number = False;
			break;
		}
	}
	if (is_number == False) {
		printf("Invalid prarameter - not a number\n");
	}
	return is_number;
}

/* <summary> assert_command - check if the command function call is legal
real_command - string from user,
legal command - all the legel command available,
length - amount number of the legal command,
error_messege - error messege in case the assert command return False.
.</summary> */
BOOL assert_command(char real_command[], const char *legal_command[], int  length, char error_messege[]) {

	BOOL is_validate_assertion = False; /* check if command validate*/
	int i;
	
	for (i = 0; length>i; i++) {
		if (strcmp(legal_command[i], real_command) == 0) {
			is_validate_assertion = True;
			break;
		}
	}

	if (is_validate_assertion == False) {
		printf("%s", error_messege);
	}

	return is_validate_assertion;
}

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