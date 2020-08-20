#include "interface.h"


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




