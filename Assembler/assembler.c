#include "interface.h"


int main()
{  

	int *result;
	int digits = 4;
 
	char binaryString[4] = "";
 
	result = decimal2binaryArray(3, digits);
 
	for (int i = 0; i <digits; ++i) {
		printf("%d",result[i]);
	}
 
	
	 
	
	getchar();

	return 0;
}



