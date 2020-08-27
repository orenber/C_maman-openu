#pragma once

#ifndef UNITSTEST
#define UNITSTEST

#include "ArrayUtils.h"
#include "Data_structures.h"


/* unit test -------------------------------------*/

void test_printArray();

void test_printArrayReverse();

void test_decimal2binaryArray();

void test_decimal2binaryArray_negative();

void test_binaryArray2decimal();

void test_arrayAssign();

void test_assertIsEmpty();

void test_binaryArray2Hexadecimal();

void test_num2string();

void print_test_result(BOOL test);


void run_test();

#endif 