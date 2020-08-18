#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MEM 30
#define BUFFERSIZE 81
#define bitrray 24
#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define CAPACITY 10000  // Stack maximum capacity
#define LEN_Register 8

const char *register_leagal[];
const char *instructionType[];
const char *flag_legal[];
const char *guidanceType[];
const char seperator[];


typedef enum {
	False = 0, True = 1
}BOOL;

typedef struct ARE {
	BOOL x[3];
} ARE;

struct operationFunc {

	char name[4];
	int  funct;
	int  opcode;
	int  functBinaryArr[5];
	int  opcodeBinaryArr[6];
	int  addressSource[2];
	int  registerSource[3];
	int  addressDestination[2];
	int  registerDestination[3];
	ARE  ARE;
};

struct flagTable {
	char symbol[4];
	int address;
	struct flagTable *next;
}*top;

struct addressTable{
	int address;
	int binaryMachineCode[24];
	struct addressTable *next;
}*top_node;





typedef enum {
	r0 = 0, r1 = 1, r2 = 2,
	r3 = 3, r4 = 4, r5 = 5,
	r6 = 6, r7 = 7
}Register;


typedef struct {
	BOOL call_operation;
	int firstInput;
	Register secondInput;

}twoInputRegistretion;


/* ArrayUtils ---------------------------------------*/

int * string2array(char stringArray[]);

void printArray(int arr[],int size);

void printArrayReverse(int arr[], int length);

int* decimal2binaryArray(int decimalNumber, int digits);

void array2string(int arrayNumber[], char *stringArray);

int  array_string_length(char *names[]);

void zeros(int *arr, int numberZeros);

void remove_substring(char *text, char *sub_string);

void remove_substring_parts(char *main_string, char *sub_string_parts);

void arrayAssign(int *arrtoChange[], int *subArray[], int initial_index, int final_index);

int char_apperance(char text[], char token);

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

BOOL assertIsEmpty(char sentence[]);
/* assembler ----------------------------------*/

void flag_manger(char flag[], int value);

void command_manager(char command[]);

void set_operation_command(char func[], char input_str[], struct operationFunc *opcodeFunc);

int * createBinaryArray(struct operationFunc *opcodeFunc);

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc);

void guidance_sentence(char varType[], char var[]);

void string_sentence(char var[]);

void data_sentence(char var[]);

void extern_sentence(char var[]);

void entry_sentence(char var[]);


void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc);

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

Register* getRegisterVar(char registerName[]);

struct twoInputRegistretion* set_address_register(char nargin_str[], struct operationFunc *opcodeFunc);

int cheakAddresingType(char inputString[]);

 /* link list -----------------------------------*/

struct flagTable* flagTable_create();

int size_list(struct flagTable * link_list);

void update_flag_table(struct flagTable * link_list, char flag[], int address);

void update_operationFunc(struct addressTable * link_list, int address, int binaryArray[]);

void push_operationFunc(struct addressTable* link_list, int binaryArray[]);

/* operation */

void add(int A, Register *operand);



/* unit test -------------------------------------*/
void print_test_result(BOOL test);

void test_printArrayReverse();

void test_printArray();

void run_test();

