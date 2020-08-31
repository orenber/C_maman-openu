#include "Assertion.h"


/* <summary> assert_nargin - check the number of argument input
text - string from user that will be parse to number of argument input.
expected_nargin - expected number of argument input ..</summary> */
BOOL assert_nargin(char text[], int expected_nargin) {

	BOOL valid_inputs = False;
	char  *sep = "";
	int nargin = 0;
	char seperator[] = { ',','\n','\t',':',' ','\r','\0'};
	char command_input[MAX_LINE_WIDTH] = "";  /* copy of input string */
	
	strcpy(command_input, text);
	sep = strtok(command_input, seperator);

	while (sep != NULL)
	{
		/* count the number of inputs */
		++nargin;
		sep = strtok(NULL, seperator);

	}

	if (nargin == expected_nargin) {
		valid_inputs = True;
	}
	else if (nargin > expected_nargin) {
		valid_inputs = False;
		printf("\nToo many operands, requires %d operands (got %d)\n", expected_nargin, nargin);
	}
	else if (nargin < expected_nargin) {
		valid_inputs = False;
		printf("\nMissing operands, requires %d operands (got %d)\n", expected_nargin, nargin);
	}


	return valid_inputs;
}


/* <summary> assert_register_type - parse the register and check if it is legal register name
Register_type - register name..</summary> */
BOOL assert_register_type(char Register_type[]) {
	BOOL is_validate_assertion = True;
	is_validate_assertion = assert_command(Register_type, register_leagal, REGISTER_NUM, "Undefined register variable\n");
	return is_validate_assertion;
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



/* <summary> assert_comma - parse the comma and check if it is legal comma apperance
text - string
comma_sum - number of cummas that need to be in the text..</summary> */
BOOL assert_comma(char text[], int comma_sum) {

	BOOL llegal_comma = False;
	char error_messege[MAX_LINE_WIDTH] = "", clean_string[MAX_LINE_WIDTH] = "";
	int length = 0;
	char *illgal_comma = ",,";

	strcpy(clean_string, text);
	remove_substring(clean_string, " ");
	remove_substring(clean_string, "\n");
	length = (int)strlen(clean_string);

	if (clean_string[0] == ',') {

		/* not allow to be in the first index*/
		
		strcpy(error_messege, "Illegal comma\n");
		llegal_comma = False;
	}
	else if (clean_string[length - 1] == ',') {
		/* not allow to be int the last index*/
		strcpy(error_messege, "Extraneous text after end of command\n");
		llegal_comma = False;
	}
	else if (strstr(clean_string, illgal_comma) != NULL) {
		/* not allow consecutive comma*/
		strcpy(error_messege, "Multiple consecutive commas\n");
		llegal_comma = False;
	}
	else if (char_apperance(text, ',') < comma_sum) {
		/* must be in exact number */
		strcpy(error_messege, "Missing comma\n");
		llegal_comma = False;
	}
	else {
		llegal_comma = True;
	}


	if (llegal_comma == False) {
		printf("%s", error_messege);
	}

	return llegal_comma;
}


BOOL assertArrayIsEqual(int arr1[], int arr2[], int length) {

	int i;
	BOOL valid = True;
	for (i = 0; i < length; ++i) {
		if (arr1[i] != arr2[i]) {
			printf("\narray index: %d value: %d fail\n",i,arr2[i]);
			valid = False;
		}
		else {
			printf("%d", arr1[i]);
		}

	}
	return valid;
}

BOOL assertIsEqual(int num1, int num2) {

	return   (num1 == num2)?True:False;
	  
}

BOOL assertIsMember(int num1, int arr[],int length) {

	BOOL ismember = False;
	int i = 0;
	for ( ; i < length; ++i) {

		ismember = assertIsEqual(num1, arr[i]);
		if (ismember) {
			break;
		}
	}
	return ismember;

}

BOOL assertIsEmpty(char sentence[]) {

	/* seperator for parsing text*/
    const char seperator[] = {' ','\t','\r','\n','\0'};
	char text[MAX_LINE_WIDTH] = " ";
	int length ;
	BOOL IsEmpty = False;

	strcpy(text, sentence);
	remove_substring_parts(text,  seperator);
	length = strlen(text);

	(length == 0) ? IsEmpty = True : False;

	return IsEmpty;
}