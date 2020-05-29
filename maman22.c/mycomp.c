#include "complex.h"

int main(void){

	char user_command[MEM],adjust_command[MEM],input_command[MEM];

	int output = 1;
	char *function_name, *input_string;

	while (output != EOF)
	{
		output = fgets(user_command, MEM, stdin);
		strcpy(adjust_command, user_command);
		strcpy(input_command, user_command);

		function_name = strtok(adjust_command, seperator);
		input_string = strtok(input_command, function_name);

		if (stop(function_name) == True) {
			break;
		};

		if (assert_command(function_name, command_leagal, LEN_COMMAND,"Undefined command name\n") == True){
		setCommand(function_name, input_string);
		}
		
	}

    return 0;
};



void setCommand(char command[], char input_string[]) {

	if (strcmp(command, "read_comp") == 0) {
		
		read_comp_from_user(input_string);
	}
	else if (strcmp(command, "print_comp") == 0) {
		
		print_comp_from_user(input_string);
	}

	else if (strcmp(command, "add_comp") == 0) {
		
		add_comp_from_user(input_string);
	}

	else if (strcmp(command, "sub_comp") == 0) {

		sub_comp_from_user(seperator);

	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		
		mult_comp_real_from_user(input_string);
	}
	else if (strcmp(command, "mult_comp_img") == 0) {

		mult_comp_img_from_user(input_string);
	}
	else if (strcmp(command, "mult_comp_comp") == 0) {

		mult_comp_comp_from_user(input_string);
	}
	else if (strcmp(command, "abs_comp") == 0) {
		
		abs_comp_from_user(input_string);

	}


	return;
}

void read_comp_from_user(char input_string[]) {

	char *complexStr, *realStr, *imgStr;
	double real = 1, img = 1;
	Complex compResult, comp1, compAsigment;
	char command_input[MEM] ="";
	strcpy(command_input, input_string);
   
	/*assert number of inputs */
	if (assert_input(command_input, 3) == False) {return;}

	/* complex input 1*/
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplex(complexStr[0]);

	/* real number input*/
	realStr = strtok(NULL, seperator);
	if (assert_number(realStr) == False) {return;}
	sscanf(realStr, "%lf", &real);

	/* img number input*/
	imgStr = strtok(NULL, seperator);
	if (assert_number(imgStr) == False) {return;}
	sscanf(imgStr, "%lf", &img);

	compAsigment = read_comp(comp1, real, img);
	print_comp(compAsigment);

}

void print_comp_from_user(char input_string[]) {
	
	char *complexStr;
	Complex  comp;
	char command_input[MEM] = "";
	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 1) == False) {return;}
	
	/*get complex input */
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplex(complexStr[0]);

	print_comp(comp);
}

void add_comp_from_user(char input_string[]) {

	char *complexStr, *realStr, *imgStr;
	Complex compResult, comp1, comp2;
	char command_input[MEM] = "";
	strcpy(command_input, input_string);
	
	/*assert number of inputs */
	if (assert_input(command_input, 2) == False) {return;}

	/*assert complex type */
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplex(complexStr[0]);

	/*assert complex type */
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplex(complexStr[0]);

	compResult = add_comp(comp1, comp2);
	print_comp(compResult);
}

void sub_comp_from_user(char input_string[]) {

	char *complexStr, *realStr, *imgStr;
	double real = 1, img = 1;
	Complex compResult, comp1, comp2;
	char command_input[MEM] = "";

	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 2) == False) {return;}

	complexStr = strtok(input_string, seperator);
	
	/*assert Complex_type */
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplex(complexStr[0]);

	complexStr = strtok(NULL, seperator);
	/*assert Complex_type */
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplex(complexStr[0]);

	compResult = sub_comp(comp1, comp2);
	print_comp(compResult);

}

void mult_comp_real_from_user(char input_string[]) {
	
	char *complexStr, *realStr;
	double real = 1;
	Complex compResult, comp;
	char command_input[MEM] = "";

	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 2) == False) {return;}

	/* get complex input*/
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplex(complexStr[0]);

	/* get number input*/
	realStr = strtok(NULL, seperator);
	if (assert_number(realStr) == False) { return; }
	sscanf(realStr, "%lf", &real);

	compResult = mult_comp_real(comp, real);
	print_comp(compResult);


}

void mult_comp_img_from_user(char input_string[]) {
	
	char *complexStr, *realStr, *imgStr;
	double  img = 1;
	Complex compResult, comp;
	char command_input[MEM] = "";

	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 2) == False) {return;}

	/* get complex input*/
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplex(complexStr[0]);

	/* get img number input*/
	imgStr = strtok(NULL, seperator);
	if (assert_number(imgStr) == False) {return;}
	sscanf(imgStr, "%lf", &img);


	compResult = mult_comp_img(comp, img);
	print_comp(compResult);

}

void mult_comp_comp_from_user(char input_string[]) {

	char *complexStr;
	Complex compResult, comp1, comp2 ;
	char command_input[MEM] = "";

	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 2) == False) {return;}

	/*complex input 1*/
	complexStr = strtok(input_string, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp1 = getComplex(complexStr[0]);

	/*complex input 2*/
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp2 = getComplex(complexStr[0]);

	/*call function*/
	compResult = mult_comp_comp(comp1, comp2);

	print_comp(compResult);

}

void abs_comp_from_user(char input_string[]) {

	char *complexStr;
	double real = 1;
	Complex  comp;
	char command_input[MEM] = "";

	strcpy(command_input, input_string);

	/*assert number of inputs */
	if (assert_input(command_input, 1) == False) {return;}

	/* complex input */
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {return;}
	comp = getComplex(complexStr[0]);

	real = abs_comp(comp);
	printf("%1f", real);

}



Bool stop(char command[]) {
	 
	Bool state;
	state = (strcmp(command, "stop") == 0) ? True : False;

	return state;
};

Bool assert_command(char real_command[],char *expected_command[],int length,char messege[]) {

	
	Bool is_validate_assertion = False;
	int i = 0;


	for (i; length>i; i++) {
		if (strcmp(expected_command[i], real_command) == 0){
			is_validate_assertion = True;
			break;
		}
	}

	if (is_validate_assertion == False) {
		printf(messege);
	}

	return is_validate_assertion;
}

Bool assert_input(char sentence[], int expected_input) {
	Bool valid_inputs = False;
	char messege[40]="",*sep="";
	int nargin = 0, i;
	

	/* count the number of inputs */
	
	sep = strtok(sentence, seperator);
	
    while (sep != NULL)
	{
		++nargin;
		sep = strtok(NULL,seperator);

	}
	
	if (nargin == expected_input) {
		valid_inputs = True;
	}
	else if (nargin > expected_input) {
		valid_inputs = False;
		strcpy(messege,"Extraneous text after end of command\n");
	}
	else if (nargin < expected_input){
		valid_inputs = False;
		strcpy(messege,"Missing parameter\n");
	}
	 
	

	if (valid_inputs == False) {
		printf(messege);
	}

	return valid_inputs;
}

Bool assert_Complex_type(char Complex_type[]) {
	Bool is_validate_assertion = True;
	is_validate_assertion = assert_command(Complex_type, Complex_leagal, LEN_Complex, "Undefined complex variable\n");
	return is_validate_assertion;
}

Bool assert_number(char numberStr[]) {
	Bool is_number ;
	int length  = 0,
        i ,point = 0;

	length = strlen(numberStr);
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

Bool assert_comma(char sentence[]) {

	Bool llegal_comma = True;
	char *error_messege = "";
	int i, comma = 0,inputs = 0;
	int length = strlen(sentence);

	for (i = 0; length > i; ++i) {
		if (sentence[i] == ' ') {
			continue;
		}
		else if (sentence[i] == ',') {
			comma++;
	
			if ((comma ==1)&&(inputs==0)){

				error_messege = "Illegal_comma";
				llegal_comma = False;
				inputs == 0;
				break;
			}
			else if ((comma > 1) && (inputs == 0)) {
				error_messege = "Multiple consecutive commas";
				llegal_comma = False;
				break;
			}
		}
		else {
			inputs=1;
			comma = 0;
		}
	}
	printf(error_messege);
	return llegal_comma;
}







