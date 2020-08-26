#pragma once
#include "Interface.h"

/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

FILE* open_files(int argc, char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);

void create_files_output(char file_to_read[], struct memoryTable *memory_table, struct symbolTable *symbol_table);

void write_ob_file(char fileName[], struct addressTable* addresstable);

void write_ent_file(char fileName[], struct symbolTable* symboltable);



