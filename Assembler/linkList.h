#pragma once

#include "assembler.h"


/* link list -----------------------------------*/

struct symbolTable* symbolTable_create();

struct addressTable* addressTable_create();

struct dataTable* dataTable_create();


struct addressData get_code_data(struct addressTable* link_list, int address[]);

struct symbolData get_symbol_data(struct symbolTable * link_list, char symbol[]);



void update_addressTable(struct addressTable * link_list, int address, int binaryArray[]);
 
void update_symbol_table(struct symbolTable * link_list, char symbol[], TypeSymbol type, BOOL isInternal);


void push_addressTable(struct addressTable** link_list, int *address);

void push_symbol_table(struct symbolTable ** link_list, int address, char symbol[] , TypeSymbol type, BOOL isInternal);

void push_update_data_table(struct dataTable ** link_list, int *address, char name[], int binaryArray[]);


void push_update_addressTable(struct addressTable** link_list, int *address, int binaryArray[]);


int size_list_symbol_table(struct symbolTable * link_list);

int size_list_data_table(struct dataTable * link_list);

int size_list_address_table(struct addressTable * link_list);

int serach_symbol_address(struct symbolTable * link_list, char symbol[]);


void print_symbol_table(struct symbolTable * link_list);

void print_address_table(struct addressTable* link_list);

void print_data_table(struct dataTable* link_list);

struct addressData get_code_data(struct addressTable* link_list, int address[]);

