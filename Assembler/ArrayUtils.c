#include "ArrayUtils.h"
 

void printArray(int arr[],int length)
{

	int i;

	for (i = 0; i < length; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void printArrayReverse(int arr[], int length)
{

	int i = length - 1;

	for (; i >= 0; i--)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void zeros(int *arr, int numberZeros) {
	int i;
	for (i = 0; numberZeros > i; ++i ) {
		arr[i] = 0;
	}
} 

void array2string(int arrayNumber[], char* stringArray) {

	/*detect the size of the array*/
	int index = 0, length = LENGTH(arrayNumber);
	int n;

	strcpy(stringArray, "");

	/* loop over to create string */
	for (n = 0; n <= length; ++n) {
		index += sprintf(&stringArray[index], "%d", arrayNumber[n]);
	}
	/* */
	return;

} 

int * string2array(char stringArray[],int *length) {

	const char seperetor[] = { ',' };
	char *str = "" ,strArray[MAX_LINE_WIDTH] = "";
	int i = 0, inputNum = 0;
	int *arrayNumber;

	inputNum = char_apperance(stringArray, seperetor[0]);
	length[0] = inputNum + 1;
	arrayNumber = (int*)calloc(length, sizeof(int));

	strcpy(strArray, stringArray);
	str = strtok(strArray, seperetor);
	
	while (str != NULL) {
		sscanf(str, "%d", &arrayNumber[i]);
		str = strtok(NULL, seperetor);
		i++;

	}

	return arrayNumber;

}

void arrayAssign( int *arrtoChange, int subArray[], int initial_index, int final_index) {
	int i, j = 0;

	for (i = initial_index, j = 0; final_index >= i; ++i, j++) {
		arrtoChange[i] = subArray[j];

	};

}

int * decimal2binaryArray(signed int decimalNumber,unsigned int digits) {


	int number;
	int n;
	int* arr = (int*)calloc(digits, sizeof(int));

	number = decimalNumber;
	if (number >= 0) {
		for (  n = digits - 1; n >= 0; --n) {

			arr[n] = number % 2;
			number = number / 2;

		}
	}
	else if (number < 0) {
		for ( n = digits - 1; n >= 0; --n) {
			/*Binary signed 1's complement:*/
			arr[n] = (number % 2) == 0? 1: 0;

			number = number / 2;
		
		}
		for ( n = digits - 1; n >= 0; --n) {
			/*Binary signed 2's complement:*/
			if (arr[n] == 0) {
				arr[n] = 1;
				break;
			}
			else if (arr[n] == 1) {
				arr[n] = 0;
			}

		}

	}

	return arr;

}

int binaryArray2decimal(int binaryArray[],  int digits){

	int decimal , result = 0;
	int i = digits - 1,j =0;

	for ( ; i >=0, j<digits ; --i,++j) {

		decimal = binaryArray[i] * (int)pow(2, j);
		result = result + decimal;

	}

	return result;
}
 /*
char * binaryArray2Hexadecimal(int binaryArray[], unsigned int digits) {

	int decimal, result = 0;
	int i = digits - 1, j = 0,n ;
	char hexadecimal[] = "000000";
	n= strlen(hexadecimal);

	printArray(binaryArray, digits);
	for ( ; i >= 0; --i, ++j)
	{

		decimal = binaryArray[i] * (int)pow(2, j);
		result = result + decimal;
		
		if (( (j+1) % 4 == 0) || (i == 0))
		{
			
			n--;
			switch (result)
			{

			case 10:
				hexadecimal[n] = 'a';
				break;
			case 11:
				hexadecimal[n] = 'b';
				break;
			case 12:
				hexadecimal[n] = 'c';
				break;
			case 13:
				hexadecimal[n] = 'd';
				break;
			case 14:
				hexadecimal[n] = 'e';
				break;
			case 15:
				hexadecimal[n] = 'f';
				break;

			default:
				hexadecimal[n] = result + '0';
				
				break;

			}
 
			result = 0;
			j = -1;
		}
	}
 
	return hexadecimal;
}
*/


char *decimal2Hexadecimal(long int decimalNumber)
{
	static char hexDecNum[100];
	int i;
	for (i = 0; i < sizeof(decimalNumber) * 2; i++)
	{
		int digit = decimalNumber & 0xf;

		if (digit >= 10)
			digit += 'A' - 10; 
		else
			digit += '0';       

		hexDecNum[i] = digit;
		decimalNumber >>= 4;
	}

	hexDecNum[i] = 0;
	return hexDecNum;
}

/*char * num2string(int number) {

	char * padding = "0000000";
	char strnum[6];
	char strC[10];
	int indx ;

	indx = strlen(padding) - numSize(number);
	sprintf(strnum ,"%d",number);
	strncpy(strC, padding, indx);
	strC[indx] = '\0';
	strcat(strC, strnum);
	 
	return strC;
}*/

int numSize(int number) {

	int numsize = -1, result;
	do {
		
		result = number / (int)pow(10, ++numsize);


	} while (result != 0);

	 
	return numsize;

}

int inputs_check(char input_str[], char token) {
	int nargin = 0;
	BOOL isempty = True;
	isempty = assertIsEmpty(input_str);
	if (!isempty){
		nargin = char_apperance(input_str, token) + 1;
	}
	return nargin;
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

char* strep(char* s, const char* oldW, const char* newW)
{
	char* result;
	int i, cnt = 0;
	int newWlen = strlen(newW);
	int oldWlen = strlen(oldW);

	/* Counting the number of times old word  occur in the string*/ 
	
	for (i = 0; s[i] != '\0'; i++) {
		if (strstr(&s[i], oldW) == &s[i]) {
			cnt++;

			/* Jumping to index after the old word.*/ 
			i += oldWlen - 1;
		}
	}

	/* Making new string of enough length*/ 
	result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);

	i = 0;
	while (*s) {
		/* compare the substring with the result */ 
		if (strstr(s, oldW) == s) {
			strcpy(&result[i], newW);
			i += newWlen;
			s += oldWlen;
		}
		else
			result[i++] = *s++;
	}

	result[i] = '\0';
	return result;
}

int array_string_length(char *names[]) {

	int namesLen = -1;
	while (names[++namesLen] != NULL) {}
	return namesLen;
}

void remove_substring_parts(char *main_string, const char sub_string_parts[]) {

	int i = 0;
	int len = strlen(sub_string_parts);
	char latter[] = { ' ','\0' };
	for ( ; i < len; ++i) {
		latter[0] = sub_string_parts[i];
		remove_substring(main_string, latter);
	}

}

/* <summary> char_apperance -
chack how many time the token (char) appers in the text.
token - char..</summary> */
int char_apperance(char text[],const char token) {

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

void str_inside(char* oldW, const char inside) {

	int i = 0;
	BOOL del = True;

	while (oldW[i] != '\0') {

		if (oldW[i] == inside) {

			del = (del == False);
		}

		if (del){
			memmove(oldW, oldW + 1, strlen(oldW));;
		}
		i++;
	}


}


BOOL checkString(const char s[])
{
	unsigned char c;

	while ((c = *s) && (isalpha(c) || isdigit(c))) ++s;

	return *s == '\0';
}

