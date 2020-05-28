#include "complex.h"

int main(void){

	char command[30];
	char seperator[] = ", \t\r\n";
	int output = 1;
	char *sptr;

	while (output != EOF)
	{
		output = fgets(command, 30, stdin);
		sptr = strtok(command, seperator);
		if (stop(command) == True) {
			break;
		};

		if (assert_command(sptr, command_leagal,"Undefined command name\n") == True){
		setCommand(sptr, seperator);
		}
		
	}

    return 0;
};



void setCommand(char command[], char seperator[]) {

	if (strcmp(command, "read_comp") == 0) {
		
		read_comp_from_user(seperator);
	}
	else if (strcmp(command, "print_comp") == 0) {
		
		print_comp_from_user(seperator);
	}

	else if (strcmp(command, "add_comp") == 0) {
		
		add_comp_from_user(seperator);
	}

	else if (strcmp(command, "sub_comp") == 0) {

		sub_comp_from_user(seperator);

	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		
		mult_comp_real_from_user(seperator);
	}
	else if (strcmp(command, "mult_comp_img") == 0) {

		mult_comp_img_from_user(seperator);
	}
	else if (strcmp(command, "mult_comp_comp") == 0) {

		mult_comp_comp_from_user(seperator);
	}
	else if (strcmp(command, "abs_comp") == 0) {
		
		abs_comp_from_user(seperator);

	}


	return;
}

void read_comp_from_user(char seperator[]) {

	char *complexStr, *realStr, *imgStr;
	double real = 1, img = 1;
	Complex compResult, comp1, compAsigment;


	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp1 = getComplex(complexStr[0]);


	realStr = strtok(NULL, seperator);
	if (assert_number(realStr) == False) {
		return;
	}
	sscanf(realStr, "%lf", &real);

	imgStr = strtok(NULL, seperator);
	if (assert_number(imgStr) == False) {
		return;
	}
	sscanf(imgStr, "%lf", &img);

	compAsigment = read_comp(comp1, real, img);
	print_comp(compAsigment);

}

void print_comp_from_user(char seperator[]) {
	
	char *complexStr;
	Complex  comp;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp = getComplex(complexStr[0]);

	print_comp(comp);
}

void add_comp_from_user(char seperator[]) {

	char *complexStr, *realStr, *imgStr;
	Complex compResult, comp1, comp2;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp1 = getComplex(complexStr[0]);

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp2 = getComplex(complexStr[0]);

	compResult = add_comp(comp1, comp2);

	print_comp(compResult);
}

void sub_comp_from_user(char seperator[]) {

	char *complexStr, *realStr, *imgStr;
	double real = 1, img = 1;
	Complex compResult, comp1, comp2;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp1 = getComplex(complexStr[0]);

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp2 = getComplex(complexStr[0]);

	compResult = sub_comp(comp1, comp2);

	print_comp(compResult);

}

void mult_comp_real_from_user(char seperator[]) {
	
	char *complexStr, *realStr;
	double real = 1;
	Complex compResult, comp;
	
	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp = getComplex(complexStr[0]);

	realStr = strtok(NULL, seperator);
	sscanf(realStr, "%lf", &real);

	compResult = mult_comp_real(comp, real);

	print_comp(compResult);


}

void mult_comp_img_from_user(char seperator[]) {
	
	char *complexStr, *realStr, *imgStr;
	double  img = 1;
	Complex compResult, comp;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp = getComplex(complexStr[0]);

	imgStr = strtok(NULL, seperator);
	sscanf(imgStr, "%lf", &img);

	compResult = mult_comp_img(comp, img);

	print_comp(compResult);

}

void mult_comp_comp_from_user(char seperator[]) {

	char *complexStr;
	Complex compResult, comp1, comp2 ;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp1 = getComplex(complexStr[0]);

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp2 = getComplex(complexStr[0]);

	compResult = mult_comp_comp(comp1, comp2);

	print_comp(compResult);

}

void abs_comp_from_user(char seperator[]) {

	char *complexStr;
	double real = 1;
	Complex  comp;

	complexStr = strtok(NULL, seperator);
	if (assert_Complex_type(complexStr) == False) {
		return;
	}
	comp = getComplex(complexStr[0]);

	real = abs_comp(comp);

	printf("%1f", real);

}



Bool stop(char command[]) {
	 
	Bool state;
	state = (strcmp(command, "stop") == 0) ? True : False;

	return state;
};

Bool assert_command(char real_command[],char *expected_command[],char messege[]) {

	
	Bool is_validate_assertion = False;
	int i = 0;
	int length = sizeof expected_command / sizeof *expected_command[0];

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

Bool assert_input(int get_input, int expected_input) {
	Bool is_error_occurred;
	char messege[30]="";

	if (get_input > expected_input) {
		is_error_occurred = True;
		strcpy(messege,"Extraneous text after end of command\n");
	}
	else if(get_input > expected_input){
		is_error_occurred = True;
		strcpy(messege,"Missing parameter\n");
	}
	else {
		is_error_occurred = False;
	}
	

	if (is_error_occurred == True) {
		printf(messege);
	}

	return is_error_occurred;
}

Bool assert_Complex_type(char Complex_type[]) {
	Bool is_validate_assertion = True;
	is_validate_assertion = assert_command(Complex_type, Complex_leagal, "Undefined complex variable\n");
	return is_validate_assertion;
}

Bool assert_number(char numberStr[]) {
	Bool is_number = False;
	if (isdigit(numberStr)) {
		is_number = False;
	}
	else {
		printf("Invalid prarameter - not a number\n");
	}
	return is_number;
}

Bool assert_comma(char comma) {
	Bool is_error_occurred = True;
	return is_error_occurred;
}







