#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>


#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))

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