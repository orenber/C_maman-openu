/* ***********************************************************************
Assembly         :
Author           : Oren Berkovitch
Created          : 31-05-2020
Last Modified By : Oren Berkovitch
Last Modified On : 31-05-2020
***********************************************************************
<summary>
the program is complex number calculator 
you can add ,subtruct ,multiplie complex numbers an many more oppration
the program parse the text input to function and inputs argument.
enjoy!
</summary>
**********************************************************************
*/


#include "complex.h"

/* <summary>
main function - user friendly interface.
</summary>
<returns>int.</returns>
*/


Complex A, B, C, D, E, F;

struct {
char name;
Complex *comp;
}complexDictionary[] = {
{ 'A',&A },{ 'B',&B },{ 'C',&C },{ 'D',&D },{ 'E',&E },{ 'F',&F },{ '#',NULL }
};


int main(void){

	char user_command[MEM],adjust_command[MEM],input_command[MEM];
	char *function_name, *output = "";
 
	printf("-------------Welcome !!! to Complex Calculator --------------\n");

	while (output != NULL)
	{
		printf(">>");
		output = fgets(user_command, MEM, stdin);
		
		strcpy(adjust_command, user_command);
		strcpy(input_command, user_command);

		function_name = strtok(adjust_command, seperator);
		if (function_name == NULL) {
			continue;
		}
		printf("%s",user_command);
		remove_substring(input_command, function_name);

		if (assert_command(function_name, command_leagal, 9,"Undefined command name\n")){
		setCommand(function_name, input_command);
		}

		if (stop(function_name)) {
			/*assert number of inputs */
			if (assert_nargin(input_command, 0) ) {
				break;
			}
		}
	}

    return 0;
}


/* <summary> setCommand - get command string and input string (nargin_str) 
from the user and send to the proprieate function (factory)
.</summary> */
void setCommand(char command[], char nargin_str[]) {

	if (strcmp(command, "read_comp") == 0) {
		
		read_comp_from_user(nargin_str);
	}
	else if (strcmp(command, "print_comp") == 0) {
		
		print_comp_from_user(nargin_str);
	}

	else if (strcmp(command, "add_comp") == 0) {
		
		add_comp_from_user(nargin_str);
	}

	else if (strcmp(command, "sub_comp") == 0) {

		sub_comp_from_user(nargin_str);

	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		
		mult_comp_real_from_user(nargin_str);
	}
	else if (strcmp(command, "mult_comp_img") == 0) {

		mult_comp_img_from_user(nargin_str);
	}
	else if (strcmp(command, "mult_comp_comp") == 0) {

		mult_comp_comp_from_user(nargin_str);
	}
	else if (strcmp(command, "abs_comp") == 0) {
		
		abs_comp_from_user(nargin_str);

	}
	


	return;
}

/* <summary> read_comp_from_user - get input string (nargin_str)
from the user and parse the input for call read_comp function
.</summary> */
void read_comp_from_user(char nargin_str[]) {

	char *complexStr,             /* complex name*/
		 *realStr,                /* real number string*/
		 *imgStr;                 /* imagenery number string*/
	double real ,                 /* real number*/
		   img ;                  /* imagenery number */
	Complex  *compAsigment;       /* complex asigment */
	char command_input[MEM] ="";  /* copy of input string */
	int nargin = 3;               /* number of input argument*/

	strcpy(command_input, nargin_str);
   
	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin-1) == False) { return;}

	/* complex input */
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	 
	
	/* real number input*/
	realStr = strtok(NULL, seperator);
	if (assert_number(realStr) == False) {return;}
	sscanf(realStr, "%lf", &real);

	/* img number input*/
	imgStr = strtok(NULL, seperator);
	if (assert_number(imgStr) == False) {return;}
	sscanf(imgStr, "%lf", &img);

	compAsigment = read_comp(getComplexVar(complexStr[0]), real, img);
	print_comp(*compAsigment);

	return;
}

/* <summary> print_comp_from_user - get input string (nargin_str)
from the user and parse the input for call print_comp function
.</summary> */
void print_comp_from_user(char nargin_str[]) {
	
	char *complexStr;              /* complex var Name*/
	Complex  *comp;                /* complex var*/
	char command_input[MEM] = "";  /* copy of input string */
	int nargin = 1;                /* number of input argument*/
	
	strcpy(command_input, nargin_str);
	
	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	/*get complex input */
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplexVar(complexStr[0]);

	print_comp(*comp);
}

/* <summary> add_comp_from_user - get input string (nargin_str)
from the user and parse the input for call add_comp function
.</summary> */
void add_comp_from_user(char nargin_str[]) {

	char *complexStr,             /* complex name*/
		command_input[MEM] = "";  /* copy of input string */
	Complex compResult,           /* complex Result*/ 
		*comp1,                   /* complex var 1 */
		*comp2;                   /* complex var 2 */
	int nargin = 2;               /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of argument in*/
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin-1) == False) { return; }

	/*assert complex type */
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplexVar(complexStr[0]);

	/*assert complex type */
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplexVar(complexStr[0]);

	compResult = add_comp(*comp1, *comp2);
	print_comp(compResult);
}

/* <summary> sub_comp_from_user - get input string (nargin_str)
from the user and parse the input for call sub_comp function
.</summary> */
void sub_comp_from_user(char nargin_str[]) {

	char   *complexStr;           /* complex name*/
	Complex compResult,           /* complex Result*/ 
		    *comp1,               /* complex var 1 */
		    *comp2;               /* complex var 2 */
	char command_input[MEM] = ""; /* copy of input string */
	int nargin = 2;               /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	complexStr = strtok(nargin_str, seperator);
	
	/*assert Complex_type */
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplexVar(complexStr[0]);

	complexStr = strtok(NULL, seperator);
	/*assert Complex_type */
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplexVar(complexStr[0]);

	compResult = sub_comp(*comp1, *comp2);
	print_comp(compResult);

}

/* <summary> mult_comp_real_from_user - get input string (nargin_str)
from the user and parse the input for call add_comp function.</summary> */
void mult_comp_real_from_user(char nargin_str[]) {
	
	char *complexStr              /* complex name*/
		,*realStr;                /* real number string*/
	double real ;                 /* real number*/
	Complex compResult,           /* complex Result*/
		    *comp;                /* complex var  */
	char command_input[MEM] = ""; /* copy of input string */
	int nargin = 2;               /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }
	
	/* get complex input*/
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplexVar(complexStr[0]);

	/* get real number input*/
	realStr = strtok(NULL, seperator);
	if (assert_number(realStr) == False) { return; }
	sscanf(realStr, "%lf", &real);

	compResult = mult_comp_real(*comp, real);
	print_comp(compResult);


}

/* <summary> mult_comp_img_from_user - get input string (nargin_str)
from the user and parse the input for call mult_comp_img function
.</summary> */
void mult_comp_img_from_user(char nargin_str[]) {
	
	char *complexStr,             /* complex name*/
		 *imgStr;                 /* imagenery number string*/
	double  img ;                 /* imagenery number */
	Complex compResult,           /* complex Result*/
		    *comp;                /* complex var*/
	char command_input[MEM] = ""; /* copy of input string */
	int nargin = 2;               /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	/* get complex input*/
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplexVar(complexStr[0]);

	/* get img number input*/
	imgStr = strtok(NULL, seperator);
	if (assert_number(imgStr) == False) {return;}
	sscanf(imgStr, "%lf", &img);

	compResult = mult_comp_img(*comp, img);
	print_comp(compResult);

}

/* <summary> mult_comp_comp_from_user - get input string (nargin_str)
from the user and parse the input for call mult_comp_comp function..</summary> */
void mult_comp_comp_from_user(char nargin_str[]) {

	char *complexStr;            /* complex name*/
	Complex compResult,          /* complex Result*/ 
		*comp1,                  /* complex var 1 */
		*comp2 ;                 /* complex var 2 */
	char command_input[MEM] = "";/* copy of input string */
	int nargin = 2;              /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	/*complex input 1*/
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplexVar(complexStr[0]);

	/*complex input 2*/
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplexVar(complexStr[0]);

	/*call function*/
	compResult = mult_comp_comp(*comp1, *comp2);

	print_comp(compResult);

}

/* <summary> abs_comp_from_user - get input string (nargin_str)
from the user and parse the input for call abs_comp function..</summary> */
void abs_comp_from_user(char nargin_str[]) {

	char *complexStr;             /* complex name*/
	double real;                  /* real number*/
	Complex  *comp;               /* complex var*/
	char command_input[MEM] = ""; /* copy of input string */
	int nargin = 1;               /* number of input argument*/

	strcpy(command_input, nargin_str);

	/*assert number of inputs */
	if (assert_nargin(command_input, nargin) == False) {return;}
	/* assert legal comma*/
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	/* complex input */
	complexStr = strtok(nargin_str, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplexVar(complexStr[0]);

	real = abs_comp(*comp);
	printf("%.2f\n", real);

}

/* <summary> assert_command - check if the command function call is legal
real_command - string from user,
legal command - all the legel command available,
length - amount number of the legal command,
error_messege - error messege in case the assert command return False.
.</summary> */
Bool assert_command(char real_command[],const char *legal_command[],int  length,char error_messege[]) {

	Bool is_validate_assertion = False; /* check if command validate*/
	int i;

	for (i=0; length>i; i++) {
		if (strcmp(legal_command[i], real_command) == 0){
			is_validate_assertion = True;
			break;
		}
	}

	if (is_validate_assertion == False) {
		printf("%s",error_messege);
	}

	return is_validate_assertion;
}

/* <summary> assert_nargin - check the number of argument input 
text - string from user that will be parse to number of argument input.
expected_nargin - expected number of argument input ..</summary> */
Bool assert_nargin(char text[], int expected_nargin) {
	
	Bool valid_inputs = False;
	char messege[MEM]="",*sep="";
	int nargin = 0;
	
	sep = strtok(text, seperator);
	
    while (sep != NULL)
	{
		/* count the number of inputs */
		++nargin;
		sep = strtok(NULL,seperator);

	}
	
	if (nargin == expected_nargin) {
		valid_inputs = True;
	}
	else if (nargin > expected_nargin) {
		valid_inputs = False;
		strcpy(messege,"Extraneous text after end of command\n");
	}
	else if (nargin < expected_nargin){
		valid_inputs = False;
		strcpy(messege,"Missing parameter\n");
	}
	 

	if (valid_inputs == False) {
		printf("%s",messege);
	}

	return valid_inputs;
}

/* <summary> assert_Complex_type - parse the complex and check if it is legal complex name
Complex_type - complex name..</summary> */
Bool assert_Complex_type(char Complex_type[]) {
	Bool is_validate_assertion = True;
	is_validate_assertion = assert_command(Complex_type, Complex_leagal, LEN_Complex, "Undefined complex variable\n");
	return is_validate_assertion;
}

/* <summary> assert_number - parse the number text and check if it is legal number
numberStr - number string..</summary> */
Bool assert_number(char numberStr[]) {

	Bool is_number ;
	int length  = 0,
        i ,point = 0;

	length = (int)strlen(numberStr);
	for (i = 0; length > i; i++) {
		if (isdigit(numberStr[i]) ){
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

/* <summary> assert_comma - parse the comma and check if it is legal comma apperance
text - string 
comma_sum - number of cummas that need to be in the text..</summary> */
Bool assert_comma(char text[],int comma_sum) {
	
	Bool llegal_comma = False;
	char error_messege[MEM] = "", clean_string[MEM]="";
	int length = 0;
	char *illgal_comma= ",,";
	
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
	else if (strstr(clean_string, illgal_comma) != NULL){
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
		printf("%s",error_messege);
	}

	return llegal_comma;
}

/* <summary> char_apperance -
chack how many time the token (char) appers in the text.
token - char..</summary> */
int char_apperance(char text[], char token) {

	int apperance = 0,              /* char apperance*/
		i,    
	    length = (int)strlen(text); /* text length */

	for (i = 0; length > i;++i) {
		if (text[i] == token) {
			++apperance;
		}
	}

	return apperance;
}

/* <summary> remove_substring - remove sub string from main string.
text - main string..</summary> */
void remove_substring(char *text, char *sub_string) {
	char *match;                       /* sub sting match*/
	int len = (int)strlen(sub_string); /* length of sub string*/
	while ((match = strstr(text, sub_string))) {
		*match = '\0';
		strcat(text, match + len);
	}
}



/* get complex name and return complex pointer to the complex varible */
Complex* getComplexVar(char complexName) {

	int i;
	for (i = 0; LEN_Complex > i; i++) {
		if (complexDictionary[i].name == complexName) {
			return complexDictionary[i].comp;
		}
	}

	return complexDictionary[LEN_Complex].comp;
}
