#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define MEM 30
#define BUFFERSIZE 101
#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define CAPACITY 10000  // Stack maximum capacity

const char *function_legal[];
const char *flag_legal[];
const char seperator[];

struct operationFunc {
	char name[4];
	int funct;
	int opcode;
};

struct flagTable {
	char simebol[4];
	int value;
	struct flagTable *next;
}*top;

struct addressTable{
	char address[6];
	char sourceCode[30];
	int binaryMachineCode[27];
	struct addressTable *next;
}*top;


typedef enum {
	False = 0, True = 1
}BOOL;

typedef enum {
	r0 = 0, r1 = 1, r2 = 2,
	r3 = 3, r4 = 4, r5 = 5,
	r6 = 6, r7 = 7
}Register;

int* decimal2binaryArray(int decimalNumber, int digits);

void array2string(int arrayNumber[], char *stringArray);

BOOL file_exists(char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);

BOOL assert_number(char numberStr[]);

BOOL assert_command(char real_command[], const char *legal_command[], int  length, char error_messege[]);

void flag_manger(char flag[]);

void command_manager(char command[]);

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc);

void push(char sorceCode[], struct operationFunc *opcodeFunc);

