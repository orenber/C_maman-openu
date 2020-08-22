#pragma once

#include "assembler.h"
/* operation */


void mov_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void cmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void add_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void sub_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void lea_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void clr_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void not_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void inc_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void dec_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void jmp_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void bne_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void jsr_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void red_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void prn_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void rts_from_user(char nargin_str[], struct operationFunc *opcodeFunc);

void stop_from_user(char nargin_str[], struct operationFunc *opcodeFunc);




void mov(int A, Register *operand);

BOOL cmp(int A, Register operand);

void add(int A, Register *operand);

void sub(int A, Register *operand);

void lea(char *word, Register *operand);

void clr(Register *operand);

void not(Register *operand);

void inc(Register *operand);

void dec(Register *operand);

void jmp();

void bne();

void jsr();

void red();

void prn(int value);

void rts();

void stop();
