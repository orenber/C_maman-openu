
#ifndef ARR
#define ARR


#include "Data_structures.h"
#include "Assertion.h"


/* ArrayUtils ---------------------------------------*/

/* print */
void printArray(int arr[], int size);

void printArrayReverse(int arr[], int length);

/* array manipulation*/

void zeros(unsigned int *arr, int numberZeros);


int * string2array(char stringArray[]);

/*char * num2string(int number);*/

void arrayAssign(unsigned int *arrtoChange, unsigned int subArray[], int initial_index, int final_index);


/* convertion*/

unsigned int * decimal2binaryArray(signed int decimalNumber, unsigned int digits);

int binaryArray2decimal(unsigned int binaryArray[],  int digits);



/* get size*/
int numSize(int number);

int  array_string_length(char *names[]);


/* string manipulation*/

char* strep(char* s, const char* oldW, const char* newW);

int inputs_check(char input_str[], char token);

void remove_substring(char *text, char *sub_string);

void remove_substring_parts(char *main_string, const char sub_string_parts[]);

int char_apperance(char text[], const char token);

void str_inside(char* oldW, const char inside);

BOOL checkString(const char s[]);
 

#endif 
