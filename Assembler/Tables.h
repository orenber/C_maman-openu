#pragma once
#include "assembler.h"

/* Tables*/

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc);

void push_update_data_table(struct dataTable * link_list, int *address, char name[], int binaryArray[]);
