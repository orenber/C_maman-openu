#pragma once
#include "Interface.h"

/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

void open_files(int argc, char *argv, int filesNum, FILE *filePointer);

BOOL write_file(char fileName[], char word[], char write_type[]);

void create_files_output(char file_to_read[], struct memoryTable *memory_table, struct dataTable *data_table, struct symbolTable *symbol_table);

void write_ob_file(char fileName[], struct addressTable* addresstable, struct dataTable* dataTable);

void write_ent_file(char fileName[], struct symbolTable* symboltable);



