
#ifndef ARR
#define ARR

#include "Liberis.h"
#include "Data_structures.h"

/* ArrayUtils ---------------------------------------*/

char* strep(const char* s, const char* oldW, const char* newW);

char * num2string(int number);

char * binaryArray2Hexadecimal(int binaryArray[], unsigned int digits);

int * string2array(char stringArray[]);

void printArray(int arr[], int size);

void printArrayReverse(int arr[], int length);

int* decimal2binaryArray(int decimalNumber, int digits);

int binaryArray2decimal(int binaryArray[], unsigned int digits);

void array2string(int arrayNumber[], char *stringArray);

int  array_string_length(char *names[]);

void zeros(int *arr, int numberZeros);

void remove_substring(char *text, char *sub_string);

void remove_substring_parts(char *main_string, char *sub_string_parts);

void str_inside(const char* oldW, const char inside);

BOOL checkString(const char s[]);
 

void arrayAssign(int *arrtoChange, int subArray[], int initial_index, int final_index);

int char_apperance(char text[], char token);

#endif // !1