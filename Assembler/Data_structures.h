#pragma once


#ifndef CONSTANTS
#define CONSTANTS

#define NAME 32
#define MAX_LINE_WIDTH 81
#define BITARRAY 24
#define INITIAL_ADDRESS  100

#define REGISTER_NUM 8
/* macro*/
#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))
#define INDEX(x)   ((BITARRAY-1)-x)

const char *register_leagal[];
const char *instructionType[];
const char *flag_legal[];
const char *guidanceType[];
const char  seperator[5];

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
	unsigned int x[3];
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


struct operationFunc {

	char name[5];
	unsigned int  funct;
	unsigned int  opcode;
	unsigned int  functBinaryArr[5];
	unsigned int  opcodeBinaryArr[6];
	unsigned int  addressSource[2];
	unsigned int  registerSource[3];
	unsigned int  addressDestination[2];
	unsigned int  registerDestination[3];
	ARE  ARE;
};

struct symbolTable {
	char symbol[NAME];
	int address;
	TypeSymbol characterization;
	BOOL isInternal;
	struct symbolTable *next;
}*top;

struct memoryTable {
	int address;
	char name[NAME];
	int binaryMachineCode[24];
	struct memoryTable *next;
}*top_node;

struct dataTable {
	int address;
	char name[NAME];
	int binaryMachineCode[24];
	struct dataTable *next;

}*head;

struct addressData {
	int address;
	int binaryMachineCode[24];

};

struct symbolData {
	char symbol[NAME];
	int address;
	TypeSymbol characterization;
	BOOL isInternal;
};

struct  setupRegistretion {

	polymorfType firstOperand;
	polymorfType secondOperand;

};

struct STATE {
	int IC,
		ICF,
		DC,
		DCF;
	
};




#endif  