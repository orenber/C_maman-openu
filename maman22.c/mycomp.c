#include "complex.h"

int main(void){

	char command[30];
	int output = 1;

	while (output != EOF)
	{
		output = scanf("%s", command);

		if (output == 1) {
			setCommand(command);
		}
	}
	getchar();
    return 0;
};



void setCommand(char command[]) {


	if (strcmp(command, "read_comp") == 1) {
	
	}

	else if (strcmp(command, "add_comp") == 1) {

	}

	else if (strcmp(command, "sub_comp") == 1) {

	}
	else if (strcmp(command, "mult_comp_real") == 1) {

	}
	else if (strcmp(command, "mult_comp_img") == 1) {

	}
	else if (strcmp(command, "mult_comp_comp") == 1) {

	}
	else if (strcmp(command, "abs_comp") == 1) {

	}
	else if (strcmp(command, "stop") == 1) {

	}

	return;
}

void stop(void) {

	return;
};
