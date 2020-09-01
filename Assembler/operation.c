
#include "operation.h"

void set_operation_command(char func[], char input_str[], struct operationFunc *opcodeFunc) {

	if (strcmp(func, "mov") == 0) {

		mov_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "cmp") == 0) {

		cmp_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "add") == 0) {

		add_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "sub") == 0) {

		sub_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "lea") == 0) {

		lea_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "clr") == 0) {

		clr_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "not") == 0) {

		not_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "inc") == 0) {

		inc_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "dec") == 0) {

		dec_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "jmp") == 0) {

		jmp_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "bne") == 0) {

		bne_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "jsr") == 0) {

		jsr_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "red") == 0) {

		red_from_user(input_str, opcodeFunc);

	}
	else if (strcmp(func, "prn") == 0) {

		prn_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "rts") == 0) {

		rts_from_user(input_str, opcodeFunc);
	}
	else if (strcmp(func, "stop") == 0) {

		stop_from_user(input_str, opcodeFunc);
	}

}

void mov_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 2;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void cmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 2;
	operand_manager(nargin_str, nargin, opcodeFunc);

}

void add_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 2;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void sub_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	
	int nargin = 2;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void lea_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 2;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void clr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void not_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void inc_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void dec_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void jmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void bne_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1; 
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void jsr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
	 
}

void red_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void prn_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {
	 
	int nargin = 1;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void rts_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 0;
	operand_manager(nargin_str, nargin, opcodeFunc);
}

void stop_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	int nargin = 0;
	operand_manager(nargin_str , nargin, opcodeFunc);
	  
}

void operand_manager(char nargin_str[],int expected_nargin, struct operationFunc *opcodeFunc) {
	
	struct setupRegistretion register_setup;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, expected_nargin) == False) {
		printf("Error in %s\n", opcodeFunc->name);
		printError(WRONG_NUMBER_OF_OPERATORS);
		return;
	}
	/* assert legal comma */
	if (!assert_comma(nargin_str, expected_nargin-1)) {
		printf("Error in %s", opcodeFunc->name);
		printError(COMMAS_FIX_WRONG);
		return;
	}
	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(opcodeFunc->name, register_setup.firstOperand.Type, register_setup.secondOperand.Type);
	if (!is_leagal_address) {
		printf("Error in %s", opcodeFunc->name);
		printError(WRONG_ADDRESSING_MODE);
		return;
	}
	update_or_insert_machine_code(register_setup, opcodeFunc);

}


struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc) {

	char *inputs = "";
	char command_input[MAX_LINE_WIDTH] = "";  /* copy of input string */
								   /* number of input argument*/
	unsigned int *binaryArr;
	int input_num = 0;
	Register *regi;

	struct setupRegistretion inputRegistretion;
	strcpy(command_input, nargin_str);

	/* set defult values*/
	resetValues( opcodeFunc);

	/* check for number of inputs */
	input_num = inputs_check(nargin_str, ',');
	inputs = strtok(command_input, ",");

	if (input_num == 2) {
		/* first input*/

		inputRegistretion.firstOperand.Type = getAddresingType(inputs);

		binaryArr = decimal2binaryArray( inputRegistretion.firstOperand.Type, 2);
		arrayAssign( opcodeFunc->addressSource, binaryArr, 0, 1);
		switch (inputRegistretion.firstOperand.Type) {

		case Immediate:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x,  binaryArr, 0, 2);
			
			/*label*/
			strcpy(inputRegistretion.firstOperand.label, inputs);

			/* value*/
			remove_substring(inputs, "#");
			inputRegistretion.firstOperand.value = atoi(inputs);
			/*printf("%d", inputRegistretion.firstOperand.value);*/
			break;

		case Direct:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x, binaryArr, 0, 2);
			/*label*/
			strcpy(inputRegistretion.firstOperand.label, inputs);

			break;

		case Relative:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x, binaryArr, 0, 2);
			break;

		case Register_Direct:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x, binaryArr, 0, 2);

			regi = getRegisterVar(inputs);
			/*Register*/
			inputRegistretion.firstOperand.Register = regi[0];
			/*value*/
			inputRegistretion.firstOperand.value = (int)regi[0];
			/*label*/
			strcpy(inputRegistretion.firstOperand.label, inputs);
			binaryArr = decimal2binaryArray(inputRegistretion.firstOperand.value, 3);
			arrayAssign( opcodeFunc->registerSource, binaryArr, 0, 2);
			break;
		}


		/* second input*/
		inputs = strtok(NULL, ",");
	}

	if (inputs != NULL) {

		inputRegistretion.secondOperand.Type = getAddresingType(inputs);

		binaryArr = decimal2binaryArray(inputRegistretion.secondOperand.Type, 2);
		arrayAssign( opcodeFunc->addressDestination,  binaryArr, 0, 1);
		switch (inputRegistretion.secondOperand.Type) {

		case Immediate:

			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x, binaryArr, 0, 2);
			/* label */
			strcpy(inputRegistretion.secondOperand.label, inputs);
			/* value*/
			remove_substring(inputs, "#");
			inputRegistretion.secondOperand.value = atoi(inputs);

			break;

		case Direct:

			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x, binaryArr, 0, 2);

			/* copy label*/
			strcpy(inputRegistretion.secondOperand.label, inputs);

			break;

		case Relative:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign( opcodeFunc->ARE.x,  binaryArr, 0, 2);
			strcpy(inputRegistretion.secondOperand.label, inputs);
			break;

		case Register_Direct:
			/*ARE*/
			binaryArr = decimal2binaryArray(4, 3);
			arrayAssign(  opcodeFunc->ARE.x,  binaryArr, 0, 2);
			/*label*/
			strcpy(inputRegistretion.secondOperand.label, inputs);
			/*Register*/
			regi = getRegisterVar(inputs);
			inputRegistretion.secondOperand.Register = regi[0];
			/*value*/
			inputRegistretion.secondOperand.value = (int)regi[0];
			/* binary code */
			binaryArr = decimal2binaryArray( inputRegistretion.secondOperand.Register, 3);
			arrayAssign( opcodeFunc->registerDestination,  binaryArr, 0, 2);
		}
 
	}
	else {
		/* ther is no operands*/
		/*ARE*/
		binaryArr = decimal2binaryArray(4, 3);
		arrayAssign( opcodeFunc->ARE.x,  binaryArr, 0, 2);
	}
	return inputRegistretion;

}


 

 