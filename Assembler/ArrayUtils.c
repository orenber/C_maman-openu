#include "interface.h"


void printArray(int arr[],int length)
{

	int i;

	printf("Array elements are: ");
	for (i = 0; i < length; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

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

void arrayAssign(int *arrtoChange[], int *subArray[], int initial_index, int final_index) {
	int i, j = 0;

	for (i = initial_index, j = 0; final_index >= i; ++i, j++) {
		arrtoChange[i] = subArray[j];

	};

	 

}

int * decimal2binaryArray(int decimalNumber, int digits) {


	int number
		, result;
	int* arr = (int*)calloc(digits, sizeof(int));

	number = decimalNumber;
	for (int n = digits - 1; n >= 0; --n) {

		arr[n] = number % 2;
		number = number / 2;

	}

	return arr;

}

/* <summary> remove_substring - remove sub string from main string.
text - main string..</summary> */
void remove_substring(char *text, char *sub_string) {
	char *match;                       /* sub sting match*/
	int len = (int)strlen(sub_string); /* length of sub string*/

	if (len != 0) {
		while ((match = strstr(text, sub_string))) {
			*match = '\0';
			strcat(text, match + len);
		}
	}


}

int array_string_length(char *names[]) {

	int namesLen = -1;
	while (names[++namesLen] != NULL) {}
	return namesLen;
}

void remove_substring_parts(char *main_string, char sub_string_parts[]) {

	int i = 0;
	int len = strlen(sub_string_parts);
	char latter[] = { ' ','\0' };
	for (i; i < len; ++i) {
		latter[0] = sub_string_parts[i];
		remove_substring(main_string, latter);
	}

}

/* <summary> char_apperance -
chack how many time the token (char) appers in the text.
token - char..</summary> */
int char_apperance(char text[], char token) {

	int apperance = 0,              /* char apperance*/
		i,
		length = (int)strlen(text); /* text length */

	for (i = 0; length > i; ++i) {
		if (text[i] == token) {
			++apperance;
		}
	}

	return apperance;
}