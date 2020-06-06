/* ***********************************************************************
Assembly         :
Author           : Oren Berkovitch
Created          : 4-06-2020
Last Modified By : Oren Berkovitch
Last Modified On : 4-06-2020
***********************************************************************
<summary>
the program parse string number to word number like:
0 - zero
99  - ninte nine
etc.
the input  can come from file or from kebord
</summary>
**********************************************************************
*/

#include "data_info.h"

/* <summary>
main function - user friendly interface.
</summary>
<returns>int.</returns>
*/
int main()
{
	char number_word[MEM] = ""; /* word number*/
	char number[MEM] = "";       /* digit number string*/
	char *output="";          /* output from the user */
	char *number_list ="";
	BOOL file_exist = True;
	printf("-------------Welcome !!! number to word converter --------------\n"
		   " press q  and Enter for quite");
	file_exist = read_file("number.txt", number);
	number_list = strtok(number, "\n");
	while ((output != NULL)&&(number_list != NULL))
	{
		printf("\n>>");

		
		if (file_exist == False) {
			output = fgets(number, MEM, stdin);
		}
		

		if (strcmp(number, "q") == 0) {
			/* press q for quite*/
			break;
		}
		dictionary_number(number_list, number_word);

		printf("%s", number_word);
		
		number_list = strtok(NULL, "\n");
	}
		
		return 0;
}

/* <summary>
dictionary_number - convert string number digits to words number.
<input> 
char number[] - number string like: 85 , 45 etc.
char number_string[] - the word number- exp :six , seventeen etc.
</input>
</summary>*/
void dictionary_number(char number[],char number_string[]) {

	int index = 0,
		length; /* length of the string */
	BOOL last_digit; /* last digit int the string number*/
	strcpy(number_string ,"");
	length = (int)strlen(number);

	for (index; length > index; index++) {

		last_digit = ((index == 1) || (length == 1)) ? True : False;
		switch (number[index])
		{
		case '1':
			
			if (last_digit) {
				strcat(number_string, "one");			
			}
			else if (number[0] == '1') {
				dictionary_twenties(number[1], number_string);
				index++;
			}
			break;
		case '2':
			if (last_digit) {
				strcat(number_string, "two");
			}
			else if (index == 0) {
				strcat(number_string, "twenty");
				strcat(number_string, " ");
			}
			break;
		case '3':
			if (last_digit) {
				strcat(number_string, "three");
			}
			else if (index == 0) {
				strcat(number_string, "thirty");
				strcat(number_string, " ");
			}
			break;
		case '4':
			if (last_digit) {
				strcat(number_string, "four");
			}
			else if (index == 0) {
				strcat(number_string, "forty");
				strcat(number_string, " ");

			}
			break;
		case '5':
			if (last_digit) {
				strcat(number_string, "five");
			}
			else if (index == 0) {
				strcat(number_string, "fifty");
				strcat(number_string, " ");

			}
			break;
		case '6':
			if (last_digit) {
				strcat(number_string, "six");
			}
			else if (index == 0) {
				strcat(number_string, "sixty");
				strcat(number_string, " ");
			}
			break;

		case '7':
			if (last_digit) {
				strcat(number_string, "seven");
			}
			else if (index == 0) {
				strcat(number_string, "seventy");
				strcat(number_string, " ");
			}
			break;
		case '8':
			if (last_digit) {
				strcat(number_string, "eight");
			}
			else if (index == 0) {
				strcat(number_string, "eighty");
				strcat(number_string, " ");
			}
			break;
		case '9':
			if (last_digit) {
				strcat(number_string, "nine");
			}
			else if (index == 0) {
				strcat(number_string, "ninety");
				strcat(number_string, " ");
			}
			break;
		case '0':
			if (length == 1) {
				strcat(number_string, "zero");
			}
			break;


		default:
			break;
		}
	}
}

/* <summary>
dictionary_twenties - convert string number digits to words number 10 - 19
(special case).
<input>
char number - number string like: 1 , 3 etc.
char number_string[] - the word number- exp :sixteen , seventeen etc.
</input>
</summary>*/
void dictionary_twenties(char number, char number_string[]) {
	
	switch (number)
	{
	case '0':
		strcat(number_string, "ten");
		break;
	case '1':
		strcat(number_string, "eleven");
		break;
	case '2':
		strcat(number_string, "twelve");
		break;
	case '3':
		strcat(number_string, "thirteen");
		break;
	case '4':
		strcat(number_string, "fourteen");
		break;
	case '5':
		strcat(number_string, "fifteen");
		break;
	case '6':
		strcat(number_string, "sixteen");
		break;
	case '7':
		strcat(number_string, "seventeen");
		break;
	case '8':
		strcat(number_string, "eighteen");
		break;
	case '9':
		strcat(number_string, "nineteen");
		break;

	default:
		break;

	}
	return;


}

/* <summary>
read_file - read file line by line to string array
<input>
char fileName[] - file name
char number_list[] - file text read
</input>
</summary>*/
BOOL read_file(char fileName[] ,char number_list[]) {

	FILE* filePointer;
	int bufferLength = 255;
	char buffer[255];
	BOOL file_exist = True;
	strcpy(number_list, "");


	filePointer = fopen(fileName, "r");
	
	/* check if the file exist*/
	if (filePointer == NULL) {
		exit(EXIT_FAILURE);
		file_exist = False;
	}


	/* read line by line */
	while (fgets(buffer, bufferLength, filePointer)) {
		printf("%s\n", buffer);
		strcat(number_list, buffer);
	}

	fclose(filePointer);
	return file_exist;
}

void write_file(char fileName[],  char word[]) {

	int num;
	FILE *fptr;

	// use appropriate location if you are using MacOS or Linux
	fptr = fopen(fileName, "w");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}

	fprintf(fptr, "%s\n", word);
	fclose(fptr);

	return;

}