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
	char number_word[BUFFERSIZE] = "";          /* word number*/
	char number_digits[BUFFERSIZE]="" ;     /* digit number string*/
	char *output="";                     /* output from the user */
	char *number_list = "  ";            /* number digit left after cleaning the sepeator*/	
        char file_to_read[MEM] = "",         /* file name that i read from*/
		 file_to_write[MEM] = "";        /* file name that i write to*/
	BOOL is_file_read_exist = False,     /* is the file that i read from exist?*/
		 is_file_write_exist = False;    /* is the file that i write to exist?*/
	FILE* filePointer;
	
	const char seperator[] = ", \t\r\n"; /* seperator for parsing text*/
	int  nargin = argc;                  /* number of input in */


	if (nargin > 3) {
		/* in the case ther is more than 2 agument
		in the command line - trow error*/
		fprintf(stderr, "Error using Numbers -"
			"Too many input comand line arguments: \n");
		fprintf(stderr,"%s\t%s\t%s\t", argv[1], argv[2], argv[3]);
		exit(1);
	}

	/* check file name inputs */
	if ((nargin >= 2)&&(argv[1]!=NULL)){
		strcpy(file_to_read ,argv[1]);
		/* check if the file read exist*/
		is_file_read_exist = file_exists(file_to_read);
		if (is_file_read_exist==True){
		filePointer = fopen(file_to_read, "r");
		}
		else if (is_file_read_exist == False) {
			/* if the file not exist the programe shoude stop*/
			exit(1);
		}
	}
	if (nargin == 3) {
		strcpy(file_to_write, argv[2]);
		/* check if the file write exist */
		is_file_write_exist = file_exists(file_to_write);
		if (is_file_write_exist == True) {
			/* clean page*/
			write_file(file_to_write,"", "w");
		}
		else if (is_file_write_exist == False) {
			/* if the file not exist the programe shoude stop*/
			exit(1);
		}
	}



	if (is_file_write_exist==False){
 	
	printf("-------------Welcome !!! number to word converter --------------\n"
		   " press q and Enter to quite\n");
	}
	 
 
	while (output != NULL)
	{
		
		if (is_file_read_exist == False) {
			printf(">>");
			/* get the input from the keybord*/
			output = fgets(number_digits, BUFFERSIZE, stdin);
		}
		else if (is_file_read_exist == True) {
			/* get the input from the file - read line by line*/
			output = fgets(number_digits, BUFFERSIZE, filePointer);
		}
	
		number_list = strtok(number_digits, seperator);

		/* condition for get out the loop*/
		if ((strcmp(number_digits, "q") == 0) ||(output == NULL)){
			/* press q to quite*/
			break;
		}	

		while (number_list!=NULL)
		{
			/* convert number digit to number word*/
			dictionary_number(number_list, number_word);

			if (is_file_write_exist == False) {
				/* print to the screen*/
				fprintf(stdout,"%s", strcat(number_word,"\n"));
			}
			else if (is_file_write_exist == True) {
				/*print to the file*/
				write_file(file_to_write, number_word,"a");
			}
		
			number_list = strtok(NULL, seperator);
		}


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
read_file - write file line by line to string array
<input>
char fileName[] - file name
char word[] - file text to write
</input>
<output>
BOOL - output - return if file exist
</output>
</summary>*/
BOOL write_file(char fileName[],  char word[],char write_type[]) {

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
		
		fprintf(stderr,"%s",fileName);
		fprintf(stderr,"-file not exist - Error!\n");
	
	}
	return state;
}


