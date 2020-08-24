#include "operation.h"

void mov(int A, Register *operand) {

	*operand = A;
}


BOOL cmp(int A, Register operand) {

	BOOL Z;

	if ((A - operand) == 0) {
		Z = True;
	}
	else
	{
		Z = False;
	}
	return Z;
}


void add(int A, Register *operand) {

	operand = operand + A;

}

void sub(int A, Register *operand) {

	operand = operand - A;
}


void lea(char *word, Register *operand) {
	operand = &word;
}

/* one operand*/

void clr(Register *operand) {
	operand = 0;
}

void not(Register *operand) {
	operand = 0;
}

void inc(Register *operand) {
	(*operand)++;
}

void dec(Register *operand) {
	(*operand)--;
}

void jmp() {


}

void bne() {

}


void jsr() {

}

void red() {

}

void prn(int value) {

	printf("%d", value);
}

/* no operands*/

void rts() {

}

void stop() {

}





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

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 2;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void cmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 2;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void sub_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 2;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void lea_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 2;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void clr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);


	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void not_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
 
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void inc_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
 
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);


	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void dec_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
  
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);


	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void jmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
 
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void bne_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
 
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void jsr_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
    
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void red_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void prn_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 1;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
 
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void rts_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 0;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
	
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}


void stop_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 0;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);
    
	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);

}

void add_from_user(char nargin_str[], struct operationFunc *opcodeFunc) {

	struct setupRegistretion register_setup;
	int *binaryArr;
	int nargin = 2;
	BOOL is_leagal_address;

	/* assert number of inputs */
	if (assert_nargin(nargin_str, nargin) == False) { return; }
	/* assert legal comma */
	if (assert_comma(nargin_str, nargin - 1) == False) { return; }

	register_setup = get_address_register_setup(nargin_str, opcodeFunc);

	/* call function that check the operand leagllety */
	is_leagal_address = cheak_legal_address(&opcodeFunc->name, register_setup.firstType, register_setup.secondType);

	update_or_insert_machine_code(register_setup, opcodeFunc);
}


