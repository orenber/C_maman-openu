#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define LENGTH(x)  (sizeof(x) / sizeof((x)[0]))

int* decimal2binaryArray(int decimalNumber, int digits);
void array2string(int arrayNumber[], char *stringArray);
