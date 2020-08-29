#pragma once

#include "assembler.h"
extern struct STATE state;


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

void operand_manager(char nargin_str[], int expected_nargin, struct operationFunc *opcodeFunc);

struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc);

