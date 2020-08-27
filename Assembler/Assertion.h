#pragma once
#include "Liberis.h"
#include "Data_structures.h"
#ifndef ASSERTION
#define ASSERTION


/* Assertion -----------------------------------*/

BOOL assert_comma(char text[], int comma_sum);

BOOL assert_register_type(char Register_type[]);

BOOL assert_nargin(char text[], int expected_nargin);

BOOL assert_number(char numberStr[]);

BOOL assertArrayIsEqual(int arr1[], int arr2[], int length);

BOOL assertIsEqual(int num1, int num2);

BOOL assert_command(char real_command[], const char *legal_command[], int  length, char error_messege[]);

BOOL assertIsEmpty(char sentence[]);


#endif