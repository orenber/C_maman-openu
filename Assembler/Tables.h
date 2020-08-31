#pragma once


#ifndef TABLES
#define TABLES
#include "assembler.h"

/* Tables*/

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc);

BOOL cheak_legal_address(char func[], AdressType  sourceOperand, AdressType destinationOperand);
#endif
