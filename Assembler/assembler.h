#pragma once
#ifndef ASS
#define ASS

 
#include "Liberis.h"
#include "Interface.h"


/* assembler ----------------------------------*/

void update_or_insert_machine_code(struct setupRegistretion register_setup, struct operationFunc *opcodeFunc);

void analize_files(FILE* filePointer);

void first_pass(char command_original[]);

void commands_first_pass(char command_original[]);

void second_pass(char file_to_read[]);

void commands_second_pass(char command_original[]);

void resetValues(struct setupRegistretion *inputRegistretion, struct operationFunc *opcodeFunc);

struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc);

void create_space_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc);

void update_binary_machine_code(AdressType type, polymorfType st, ARE are);

void set_space_binary_machine_code(AdressType type,char name[]);


void flag_manger(char flag[], int value);

void command_manager(char command[]);

void set_operation_command(char func[], char input_str[], struct operationFunc *opcodeFunc);

int * createBinaryArray(struct operationFunc *opcodeFunc);

void guidance_sentence(char varType[], char var[]);

void string_sentence(char var[]);

void data_sentence(char var[]);

void extern_sentence(char var[]);

void entry_sentence(char var[]);

void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc);

Register* getRegisterVar(char registerName[]);

AdressType getAddresingType(char inputString[]);

#endif