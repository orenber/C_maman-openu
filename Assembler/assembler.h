#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

 
#define NAME 10
#define MEM 31
#define BUFFERSIZE 81
#define bitrray 24
#define INITIAL_ADDRESS  100
 
#define LEN_Register 8
/* macro*/
#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define INDEX(x)   ((bitrray-1)-x)

const char *register_leagal[];
const char *instructionType[];
const char *flag_legal[];
const char *guidanceType[];
const char seperator[];

/* new type */
typedef enum {
	False = 0, True = 1
}BOOL;

typedef enum {
	Immediate = 0, 
	Direct = 1, 
	Relative = 2, 
	Register_Direct = 3
}AdressType;


typedef struct ARE {
	BOOL x[3];
} ARE;

typedef enum {
	r0 = 0, r1 = 1, r2 = 2,
	r3 = 3, r4 = 4, r5 = 5,
	r6 = 6, r7 = 7
}Register;


typedef struct
{
	AdressType Type;
	int value;
	Register Register;
	char label[NAME];

} polymorfType;

typedef enum {
	code = 0, data = 1, external = 2, entry = 3
}TypeSymbol;

 
 /* tamplate */

struct operationFunc {

	char name[5];
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

struct symbolTable {
	char symbol[10];
	int address;
	TypeSymbol characterization;
	BOOL isInternal;
	struct symbolTable *next;
}*top;

struct memoryTable{
	int address;
	char name[MEM];
	int binaryMachineCode[24];
	struct memoryTable *next;
}*top_node;


struct dataTable {
	int address;
	char name[10];
	int binaryMachineCode[24];
	struct dataTable *next;

}*head;


struct addressData {
	int address;
	int binaryMachineCode[24];
 
};


struct symbolData {
	char symbol[10];
	int address;
	TypeSymbol characterization;
	BOOL isInternal;
};

struct  setupRegistretion {

	polymorfType firstOperand;
	polymorfType secondOperand;
	
};


/* assembler ----------------------------------*/

void update_or_insert_machine_code(struct setupRegistretion register_setup, struct operationFunc *opcodeFunc);

void analize_files(FILE* filePointer);

void first_pass(char command_original[]);

void commands_first_pass(char command_original[]);

void second_pass(char file_to_read[]);

void commands_second_pass(char command_original[]);

void resetValues(struct setupRegistretion *inputRegistretion, struct operationFunc *opcodeFunc);

struct setupRegistretion get_address_register_setup(char nargin_str[], struct operationFunc *opcodeFunc);

void create_space_binary_machine_code(struct setupRegistretion setup, struct operationFunc *opcodeFunc);

void update_binary_machine_code(AdressType type, polymorfType st, ARE are);

void set_space_binary_machine_code(AdressType type,char name[]);


void flag_manger(char flag[], int value);

void command_manager(char command[]);

void set_operation_command(char func[], char input_str[], struct operationFunc *opcodeFunc);

int * createBinaryArray(struct operationFunc *opcodeFunc);

void guidance_sentence(char varType[], char var[]);

void string_sentence(char var[]);

void data_sentence(char var[]);

void extern_sentence(char var[]);

void entry_sentence(char var[]);

void instructional_sentence(char fun[], char input_str[], struct operationFunc *opcodeFunc);

Register* getRegisterVar(char registerName[]);

AdressType getAddresingType(char inputString[]);
