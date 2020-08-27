#include "Errors.h";



/* Global method which receive errorCode and lineIndex if exists and print error according to error type*/
void printError(const char* fileName, ERROR_TYPE errorCode, int lineIndex) {


	switch (errorCode) {
	case MISSING_FILENAME:
		printf("\nPlease specify file name.\n");
		break;
	case NO_SUCH_FILE:
		fprintf(stderr, "\nError opening file: %s, %s \n", fileName);
		break;
	case LINE_TOO_LONG:
		printf("\nError at file: %s, line %d, exceeded max permitted size, 80 chars\n", fileName, lineIndex);
		break;
	case DATA_NOT_NUMBER | NUMBER_OUT_OF_BOUNDS_12BITS:
		printf("\nError at file: %s, line %d, all data values should be numbers in a range from %d to %d\n", fileName, lineIndex);
		break;
	case CANNOT_PARSE_LINE:
		printf("\nError at file: %s, line %d, couldn't find any valid directive or command\n", fileName, lineIndex);
		break;
	case INVALID_LABEL:
		printf("\nError at file: %s, line %d, Invalid label. Label should contain only letters or digits and shouldn't be more then 30 chars\n", fileName, lineIndex);
		break;
	case WRONG_NUMBER_OF_OPERATORS:
		printf("\nError at file: %s, line %d, Invalid number of operands\n", fileName, lineIndex);
		break;
	case LABEL_ALREADY_EXISTS:
		printf("\nError at file: %s, line %d, Line already exists, you can't redifine label\n", fileName, lineIndex);
		break;
	case WRONG_ADDRESSING_MODE:
		printf("\nError at file: %s, line %d, Wrong addressing mode\n", fileName, lineIndex);
		break;
	case NUMBER_OUT_OF_BOUNDS_10BITS:
		printf("\nError at file: %s, line %d, all data values should be numbers in a range from %d to %d\n", fileName, lineIndex);
		break;
	case LABEL_DOESNT_EXISTS:
		printf("\nError at file: %s, line %d, You're trying reference to label which does't exist\n", fileName, lineIndex);
		break;
	case DISPLACEMENT_EXTERNAL_LABELS_ERROR:
		printf("\nError at file: %s, line %d, You're cannot using external label in DISPOSAL addressing mode\n", fileName, lineIndex); /*DISPOSAL - miun mirhak*/
		break;
	case MAX_RAM_SIZE_EXCEEDED:
		printf("\nError at file: %s, You exceded max RAM size of %d words\n", fileName);
		break;
	default:
		break;
	}
}