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

		setCommand(sptr, seperator);
		
	}
	getchar();
    return 0;
};



void setCommand(char command[], char seperator[]) {
	char *complexStr , *realStr, *imgStr;
	double real = 1, img = 1;
	Complex compResult,comp1,comp2 ,*compAsigment;

	if (strcmp(command, "read_comp") == 0) {
		
		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		realStr = strtok(NULL, seperator);
		sscanf(realStr, "%lf", &real);

		imgStr = strtok(NULL, seperator);
		sscanf(imgStr, "%lf", &img);

		compAsigment = read_comp(comp1, real, img);
		print_comp(*compAsigment);
	}
	else if (strcmp(command, "print_comp") == 0) {
		
		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

	    print_comp(comp1);
	 
	
	}

	else if (strcmp(command, "add_comp") == 0) {
		
		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		complexStr = strtok(NULL, seperator);
		comp2 = getComplex(complexStr[0]);

		compResult = add_comp(comp1, comp2);

		print_comp(compResult);
	}

	else if (strcmp(command, "sub_comp") == 0) {

		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		complexStr = strtok(NULL, seperator);
		comp2 = getComplex(complexStr[0]);

		compResult = sub_comp(comp1, comp2);

		print_comp(compResult);

	}
	else if (strcmp(command, "mult_comp_real") == 0) {
		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		realStr = strtok(NULL, seperator);
		sscanf(realStr, "%lf", &real);;

		compResult = mult_comp_real(comp1, real);

		print_comp(compResult);
	}
	else if (strcmp(command, "mult_comp_img") == 0) {
		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		imgStr = strtok(NULL, seperator);
		sscanf(imgStr, "%lf", &img);

		compResult = mult_comp_img(comp1, img);

		print_comp(compResult);
	}
	else if (strcmp(command, "mult_comp_comp") == 1) {

		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);

		complexStr = strtok(NULL, seperator);
		comp2 = getComplex(complexStr[0]);

		compResult = mult_comp_comp(comp1, comp2);

		print_comp(compResult);
	}
	else if (strcmp(command, "abs_comp") == 1) {

		complexStr = strtok(NULL, seperator);
		comp1 = getComplex(complexStr[0]);


		real = abs_comp(comp1);

		printf("%1f",real);
	}
	else if (strcmp(command, "stop") == 1) {

	}

	return;
}




void stop(void) {

	return;
};
