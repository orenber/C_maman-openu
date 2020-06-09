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
<input>
int argc -  number of input
char* argv[] - file names string array
</input>
</summary>
<returns>int.</returns>
*/
int main(int argc, char* argv[])
{
	char number_word[MEM] = "",          /* word number*/
		 number_word_list[MEM] = "";     /* number word */
	char number_digits[MEM] = "  ";      /* digit number string*/
	char *output="";                     /* output from the user */
	char *number_list = "  ";            /* number digit left after cleaning the sepeator*/
	char file_to_read[MEM] = "",         /* file name that i read from*/
		 file_to_write[MEM] = "";        /* file name that i write to*/
	BOOL is_file_read_exist  = False,    /* is the file that i read from exist?*/
		 is_file_write_exist = False;    /* is the file that i write to exist?*/
	const char seperator[] = ", \t\r\n"; /* seperator for parsing text*/


	printf("-------------Welcome !!! number to word converter --------------\n"
		   " press q and Enter to quite\n");
	
	/* check file name inputs */
	if ((argc >= 1)&&(argv[1]!=NULL)){
		strcpy(file_to_read ,argv[1]);
		is_file_read_exist = read_file(file_to_read, number_digits);
	}
	if (argc == 2) {
		strcpy(file_to_write, argv[2]);
		is_file_write_exist = write_file(file_to_write, "");
	}
	
	while (output != NULL)
	{
		printf(">>");
		/* initlize number_word_list to empty string */
		strcpy(number_word_list, "");

		if (is_file_read_exist == False) {
			/* get the input from the keybord*/
			output = fgets(number_digits, MEM, stdin);
			number_list = strtok(number_digits, seperator);
		}

		if (strcmp(number_digits, "q") == 0) {
			/* press q to quite*/
			break;
		}
		while (number_list!=NULL)
		{
			/* convert number digit to number word*/
			dictionary_number(number_list, number_word);
			/* concatinate string */
			strcat(number_word, "\n");
			strcat(number_word_list, number_word);
		    /* extract the next number*/				
			number_list = strtok(NULL, seperator);
		}

		if ((is_file_write_exist == False)&&(strcmp(number_word_list,"")==1)){
			/* print to the screen*/
			printf("%s", number_word_list);
		}
	}

	if (is_file_write_exist) {
	
		 write_file(file_to_write, number_word_list);
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

	int index ,
		length;      /* length of the string */
	BOOL last_digit; /* last digit int the string number*/
	strcpy(number_string ,"");
	length = (int)strlen(number);

	for (index = 0 ; length > index; index++) {

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
<output>
BOOL - output - return if file exist
</output>
</summary>*/
BOOL read_file(char fileName[] ,char number_list[]) {

	FILE* filePointer;
	int bufferLength = BUFFERSIZE;
	char buffer[BUFFERSIZE];
	BOOL is_file_exist = True;  /* is the file that i read from exist?*/
	strcpy(number_list, "");    /* reset number list */

	filePointer = fopen(fileName, "r");
	
	/* check if the file exist*/
	if (filePointer == NULL) {
		exit(EXIT_FAILURE);
		is_file_exist = False;
	}

	/* read line by line */
	while (fgets(buffer, bufferLength, filePointer)) {
		printf("%s\n", buffer);
		strcat(number_list, buffer);
	}

	fclose(filePointer);
	return is_file_exist;
}
/* <summary>
read_file - write file line by line to string array
<input>
char fileName[] - file name
char word[] - file text to write
</input>
<output>
BOOL - output - return if file exist
</output>
</summary>*/
BOOL write_file(char fileName[],  char word[]) {

	FILE *filePointer;
	BOOL is_file_exist = True;  /* is the file that i write to, exist?*/
	/* use appropriate location if you are using MacOS or Linux */
	filePointer = fopen(fileName, "w");

	if (filePointer == NULL)
	{
		is_file_exist = False;
		printf("Error!");
		exit(1);
	}

	fprintf(filePointer, "%s\n", word);
	fclose(filePointer);

	return is_file_exist;

}