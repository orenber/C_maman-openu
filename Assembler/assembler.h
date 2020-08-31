#pragma once
#ifndef ASS
#define ASS

 
#include "Libraries.h" 


#include "ArrayUtils.h"
#include "Data_structures.h"
#include "Assertion.h"
#include "Constant.h"
#include "linkList.h"
#include "File_management.h"
#include "operation.h"
#include "Tables.h"
#include "Errors.h"
#include "Parser.h"
#include "UnitTest.h"


/* assembler ----------------------------------*/

void analize_files(FILE *filePointer, char filename[]);

void first_pass(FILE* filePointer);

void commands_first_pass(char command_original[]);

void second_pass(FILE* filePointer);

void commands_second_pass(char command_original[]);



void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc);

void guidance_sentence(char varType[], char var[]);

void flag_manger(char label[], TypeSymbol type);


void string_sentence(char var[]);

void data_sentence(char var[]);

void extern_sentence(char var[]);

void entry_sentence(char var[]);


void free_memory();


unsigned int * createBinaryArray(struct operationFunc *opcodeFunc);

void update_or_insert_machine_code(struct setupRegistretion register_setup, struct operationFunc *opcodeFunc);

void create_space_binary_machine_code(struct setupRegistretion setup, char instrction_name[]);

void update_binary_machine_code(AdressType type, polymorfType st, ARE are);

void set_space_binary_machine_code(AdressType type, char name[]);

void set_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc);



void resetValues(struct setupRegistretion *inputRegistretion, struct operationFunc *opcodeFunc);

struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc);



Register* getRegisterVar(char registerName[]);

AdressType getAddresingType(char inputString[]);

#endif