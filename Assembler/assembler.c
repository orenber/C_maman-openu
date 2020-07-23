#include <stdio.h>
#include <stdlib.h>

int* decimal2binaryArray(int decimalNumber, int digits);

int main()
{


	int *result;
	result = decimal2binaryArray(10,3);
	for (int i = 0; i <4; i++) {
		printf("%d",result[i]);
	}
	getchar();

	return 0;
}


int * decimal2binaryArray(int decimalNumber,int digits) {

 
	int number, divider = 2
		, result;
	int* arr = (int*)calloc(digits , sizeof(int));

	number = decimalNumber;
	for (int n = digits; n >= 0; n--) {

		result = number / divider;
		arr[n] = number % divider;
		  
		number = result;
	}

	return arr;

}

