#pragma once
#include "assembler.h"
/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);
