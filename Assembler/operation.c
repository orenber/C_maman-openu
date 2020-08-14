#include "interface.h"


void mov(int A, int *operand) {

	operand = A;
}


BOOL cmp(int A, int operand) {

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


void add(int A,int *operand) {

	operand = operand + A;

}

void sub(int A, int *operand) {

	operand = operand - A;
}


void lea(char *word,int *operand) {
	operand = &word;
}

/* one operand*/

void clr(int *operand) {
	operand = 0;
}


void inc(int *operand) {
	operand++;
}

void dec(int *operand) {
	operand--;
}

void jmp() {


}

void bne() {

}


void jsr() {

}

void red() {

}

void prn(char word[]) {
	
	printf("%s", word);
}

/* no operands*/

void rts() {

}

void stop() {

}




