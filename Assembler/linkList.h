#pragma once

#include "assembler.h"


/* link list -----------------------------------*/

struct symbolTable* symbolTable_create();

struct addressTable* addressTable_create();

struct dataTable* dataTable_create();


struct addressData get_code_data(struct addressTable* link_list, int address[]);

struct symbolData get_symbol_data(struct symbolTable * link_list, char symbol[]);

 

void push_operationFunc(struct addressTable* link_list, int *address);

void update_operationFunc(struct addressTable * link_list, int address, int binaryArray[]);

void push_update_operationFunc(struct addressTable* link_list, int *address, int binaryArray[]);

void push_symbol_table(struct symbolTable * link_list, char symbol[], int address, TypeSymbol type);

void update_symbol_table(struct symbolTable * link_list, char symbol[], int address, TypeSymbol type);

void push_update_data_table(struct dataTable * link_list, int *address, char name[], int binaryArray[]);

int size_list(struct symbolTable * link_list);

int serach_symbol_address(struct symbolTable * link_list, char symbol[]);
