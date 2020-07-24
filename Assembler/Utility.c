#include "interface.h"



void array2string(int arrayNumber[], char* stringArray) {

	/*detect the size of the array*/
	int index = 0, length = LENGTH(arrayNumber);

	strcpy(stringArray, "");

	/* loop over to create string */
	for (int n = 0; n <= length; ++n) {
		index += sprintf(&stringArray[index], "%d", arrayNumber[n]);
	}
	/* */
	return;

};


int * decimal2binaryArray(int decimalNumber, int digits) {


	int number, divider = 2
		, result;
	int* arr = (int*)calloc(digits, sizeof(int));

	number = decimalNumber;
	for (int n = digits - 1; n >= 0; --n) {

		result = number / divider;
		arr[n] = number % divider;

		number = result;
	}

	return arr;

}