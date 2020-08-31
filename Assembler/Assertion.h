#pragma once

 
#ifndef ASSERTION
#define ASSERTION
#include "Libraries.h" 
#include "Data_structures.h"
#include "ArrayUtils.h"

/* Assertion -----------------------------------*/
/* <summary> assert_nargin - check the number of argument input
text - string from user that will be parse to number of argument input.
expected_nargin - expected number of argument input ..</summary> */
BOOL assert_nargin(char text[], int expected_nargin);

/* <summary> assert_register_type - parse the register and check if it is legal register name
Register_type - register name..</summary> */
BOOL assert_register_type(char Register_type[]);

/* <summary> assert_number - parse the number text and check if it is legal number
numberStr - number string..</summary> */
BOOL assert_number(char numberStr[]);


/* <summary> assert_command - check if the command function call is legal
real_command - string from user,
legal command - all the legel command available,
length - amount number of the legal command,
error_messege - error messege in case the assert command return False.
.</summary> */
BOOL assert_command(char real_command[], const char *legal_command[], int  length, char error_messege[]);


/* <summary> assert_comma - parse the comma and check if it is legal comma apperance
text - string
comma_sum - number of cummas that need to be in the text..</summary> */
BOOL assert_comma(char text[], int comma_sum);


BOOL assertArrayIsEqual(int arr1[], int arr2[], int length);

BOOL assertIsEqual(int num1, int num2);

BOOL assertIsMember(int num1, int arr[], int length);

BOOL assertIsEmpty(char sentence[]);


#endif

