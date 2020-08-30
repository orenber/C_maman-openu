#pragma once

#ifndef ERROR
#define ERROR

#include <stdio.h> 
#include "Data_structures.h"
extern struct ERROR_HANDLER valid;

struct ERROR_HANDLER {
	char file_name[NAME];
	int pass_num, line_num;
	BOOL pass_successful;

};
typedef enum {                                       /*defining errors types*/
	MISSING_FILENAME = 0,                           /*running program without filename*/
	NO_SUCH_FILE = 1,   /*assembler couldn't find file specified*/
	LINE_TOO_LONG = 2,  /*size of parsed line exceded 80 chars*/
	WRONG_LABEL_POSITION = 3,
	WRONG_DIRECTIVE_POSITION = 4,
	WRONG_COMMAND_POSITION = 5,
	DATA_NOT_NUMBER = 6,
	NUMBER_OUT_OF_BOUNDS_12BITS = 7,
	NUMBER_OUT_OF_BOUNDS_10BITS = 8,
	CANNOT_PARSE_LINE = 9,/*Assembler was unable to parse this line, general error*/
	INVALID_SYMBOL = 10,
	WRONG_NUMBER_OF_OPERATORS = 11,
	SYMBOL_ALREADY_EXISTS = 12,
	WRONG_ADDRESSING_MODE = 13,
	SYMBOL_DOESNT_EXISTS = 14,
	DISPLACEMENT_EXTERNAL_LABELS_ERROR = 15,  
	MAX_RAM_SIZE_EXCEEDED = 16,  
	COMMAS_FIX_WRONG =17,
	MISSING_QUATS = 20,
	GENERAL=404
} ERROR_TYPE;

/* Global method which receive errorCode and lineIndex if exists and print error according to error type*/
void printError(ERROR_TYPE errorCode);

#endif