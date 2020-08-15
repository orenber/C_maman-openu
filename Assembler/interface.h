#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define MEM 30
#define BUFFERSIZE 101
#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define CAPACITY 10000  // Stack maximum capacity
#define LEN_Register 8

const char *Register_legal[LEN_Register];
const char *function_legal[];
const char *flag_legal[];
const char *varType[];
const char seperator[];


struct operationFunc {
	char name[4];
	int funct;
	int opcode;
	int functBinaryArr[5];
	int opcodeBinaryArr[6];
};

struct flagTable {
	char symbol[4];
	int address;
	struct flagTable *next;
}*top;

struct addressTable{
	int address;
	char sourceCode[30];
	int binaryMachineCode[27];
	struct addressTable *next;
}*top_node;



typedef enum {
	False = 0, True = 1
}BOOL;

typedef enum {
	r0 = 0, r1 = 1, r2 = 2,
	r3 = 3, r4 = 4, r5 = 5,
	r6 = 6, r7 = 7
}Register;



/* ArrayUtils ---------------------------------------*/

void printArray(int arr[],int size);

int* decimal2binaryArray(int decimalNumber, int digits);

void array2string(int arrayNumber[], char *stringArray);

int  array_string_length(char *names[]);

void remove_substring(char *text, char *sub_string);

void arrayAssign(int *arrtoChange[], int *subArray[], int initial_index, int final_index);


/* File management ---------------------------------*/

BOOL file_exists(char fileName[]);

BOOL write_file(char fileName[], char word[], char write_type[]);


/* Assertion -----------------------------------*/

BOOL assert_comma(char text[], int comma_sum);

BOOL assert_register_type(char Register_type[]);

BOOL assert_nargin(char text[], int expected_nargin);

BOOL assert_number(char numberStr[]);

BOOL assertArrayIsEqual(int arr1[], int arr2[], int length);

BOOL assert_command(char real_command[], const char *legal_command[], int  length, char error_messege[]);


/* assembler ----------------------------------*/

void flag_manger(char flag[]);

void command_manager(char command[]);

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc);

void varType_manger(char varType[], char var[]);

void function_manger(char fun[], char input_str[]);

void mov_from_user(char nargin_str[]);

void cmp_from_user(char nargin_str[]);

void add_from_user(char nargin_str[]);

void sub_from_user(char nargin_str[]);

void lea_from_user(char nargin_str[]);

void clr_from_user(char nargin_str[]);

void not_from_user(char nargin_str[]);

void inc_from_user(char nargin_str[]);

void dec_from_user(char nargin_str[]);

void jmp_from_user(char nargin_str[]);

void bne_from_user(char nargin_str[]);

void jsr_from_user(char nargin_str[]);

void red_from_user(char nargin_str[]);

void prn_from_user(char nargin_str[]);

void rts_from_user(char nargin_str[]);

void stop_from_user(char nargin_str[]);

Register* getRegisterVar(char registerName);

void set_operation_command(char func[], char input_str[]);

int cheakAddresingType(char inputString[]);

 /* link list -----------------------------------*/

struct flagTable* flagTable_create();

int size_list(struct flagTable * link_list);

void update_flag_table(struct flagTable * link_list, char flag[], int address);

void push_operationFunc(char sorceCode[], struct operationFunc *opcodeFunc);


/* unit test -------------------------------------*/

void test_printArray();

void run_test();
