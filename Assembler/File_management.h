#pragma once
#include "Interface.h"
/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);

void write_ob_file(char fileName[], struct addressTable* addresstable);

void write_ent_file(char fileName[], struct symbolTable* symboltable);



