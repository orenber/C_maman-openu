#include "interface.h"




void test_printArray() {

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printArray(arr,10);

}

void test_printArrayReverse() {

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printArrayReverse(arr, 10);

}

void test_decimal2binaryArray() {

	int *arr;
	int arr_test[] = {0,0,1,0,1};
	BOOL test_pass;

	arr = decimal2binaryArray(5, 5);
	printArray(arr,5);
	test_pass = assertArrayIsEqual(arr_test, arr, 5);
	print_test_result(test_pass);
}

void test_decimal2binaryArray_negative() {

	int *arr;
	int arr_test[] = { 1,0,1,1,1 };
	BOOL test_pass;

	arr = decimal2binaryArray(-9, 5);
	printArray(arr, 5);
	test_pass = assertArrayIsEqual(arr_test, arr, 5);
	print_test_result(test_pass);
}

void test_arrayAssign() {

	int arr_assign[] = { 0,0,0,0,0,0,0,0,0,0,0 },
		arr_sub[] =  { 1,2,3,4 },
		arr_test[] = { 0,0,0,0,1,2,3,4,0,0,0};
	BOOL test_pass;

	arrayAssign(arr_assign, arr_sub, 4, 7);
	printArray(arr_assign,10);
	test_pass = assertArrayIsEqual(arr_test, arr_assign,10);
	print_test_result(test_pass);

}

void test_assertIsEmpty() {
	char text_test[] = "     \t \n \r  ";
	BOOL test_pass;

	test_pass = assertIsEmpty(text_test);
	print_test_result(test_pass);
}


void print_test_result(BOOL test) {

	(test == True) ? printf("\ntest pass") : printf("\ntest fail");

}



void run_test() {

	test_arrayAssign();
	test_decimal2binaryArray();
	test_printArray();
	test_printArrayReverse();
	test_assertIsEmpty();
	test_decimal2binaryArray_negative();
}