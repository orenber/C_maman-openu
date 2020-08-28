#pragma once
#ifndef FILEHANDLER;
#define FILEHANDLER

#include<stdlib.h>
#include<stdio.h> 
#include "Data_structures.h"
#include "linkList.h"


/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

FILE* open_files(int argc, char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);

void create_files_output(char file_to_read[], struct memoryTable *memory_table, struct dataTable *data_table, struct symbolTable *symbol_table);

void write_ent_file(char fileName[], struct symbolTable *symboltable);


void write_ob_file(char fileName[], struct addressTable* addresstable, struct dataTable* dataTable);

void write_ext_file(char fileName[], struct symbolTable *symboltable, struct memoryTable *memorytable);

void search_symbol_in_memory_table(char fileName[], char symbol[], struct memoryTable *memorytable);
#endif