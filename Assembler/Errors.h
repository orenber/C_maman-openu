#pragma once
#ifndef ERROR;
#define ERROR
#include<stdio.h> 

typedef enum {                                       /*defining errors types*/
	MISSING_FILENAME = 0,                           /*running program without filename*/
	NO_SUCH_FILE,   /*assembler couldn't find file specified*/
	LINE_TOO_LONG,  /*size of parsed line exceded 80 chars*/
	WRONG_LABEL_POSITION,
	WRONG_DIRECTIVE_POSITION,
	WRONG_COMMAND_POSITION,
	DATA_NOT_NUMBER,
	NUMBER_OUT_OF_BOUNDS_12BITS,
	NUMBER_OUT_OF_BOUNDS_10BITS,
	CANNOT_PARSE_LINE,/*Assembler was unable to parse this line, general error*/
	INVALID_LABEL,
	WRONG_NUMBER_OF_OPERATORS,
	LABEL_ALREADY_EXISTS,
	WRONG_ADDRESSING_MODE,
	LABEL_DOESNT_EXISTS,
	DISPLACEMENT_EXTERNAL_LABELS_ERROR, /*trying to use DISPLACEMENT addressing type (mirhak) with external label*/
	MAX_RAM_SIZE_EXCEEDED,              /*max size of 1000 words has been exceeded*/
	INITIALIZING,                        /*for initializing purposes*/
	FINISHIZING                         /*we need to clear memory which has been allocated for fileName*/
} ERROR_TYPE;

/* Global method which receive errorCode and lineIndex if exists and print error according to error type*/
void printError(const char* currFileName, ERROR_TYPE errorCode, int lineIndex);

#endif