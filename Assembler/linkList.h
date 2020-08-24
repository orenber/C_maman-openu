#pragma once

#include "assembler.h"


/* link list -----------------------------------*/

/* create */

struct symbolTable* create_symbol_table();

struct memoryTable* create_memory_table();

struct dataTable* create_data_table();


/* push */
void push_memory_table(struct memoryTable** link_list, int *memory);

void push_symbol_table(struct symbolTable ** link_list, int memory, char symbol[] , TypeSymbol type, BOOL isInternal);

/* push and update*/

void push_and_update_data_table(struct dataTable ** link_list, int *memory, char name[], int binaryArray[]);

void push_and_update_memory_table(struct memoryTable** link_list, int *memory, int binaryArray[]);

/* update */

void update_memory_table(struct memoryTable * link_list, int memory, int binaryArray[]);

void update_symbol_table(struct symbolTable * link_list, char symbol[], TypeSymbol type, BOOL isInternal);

/* size */

int size_symbol_table(struct symbolTable * link_list);

int size_data_table(struct dataTable * link_list);

int size_memory_table(struct memoryTable * link_list);

/* serach */
/* get date from list*/
struct addressData get_code_data(struct memoryTable* link_list, int memory[]);

struct symbolData get_symbol_data(struct symbolTable * link_list, char symbol[]);

int serach_symbol_address(struct symbolTable * link_list, char symbol[]);

BOOL serach_symbol_type(struct symbolTable  *link_list, char symbol[], TypeSymbol type);

/* print */

void print_symbol_table(struct symbolTable * link_list);

void print_memory_table(struct memoryTable* link_list);

void print_data_table(struct dataTable* link_list);


