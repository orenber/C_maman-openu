#include "Errors.h"

/* Global method which receive errorCode and lineIndex if exists and print error according to error type*/
void printError(ERROR_TYPE errorCode) {
	
	valid.pass_successful = False;
	switch (errorCode) {
	case MISSING_FILENAME:
		printf("\nPlease specify file name.\n");
		break;
	case NO_SUCH_FILE:
		fprintf(stderr, "\nError opening file: %s \n", valid.file_name);
		break;
	case LINE_TOO_LONG:
		printf("\nError at file: %s, line %d, exceeded max permitted size, 80 chars\n", valid.file_name,valid.line_num);
		break;
	case CANNOT_PARSE_LINE:
		printf("\nError at file: %s, line %d, couldn't find any valid directive or command\n", valid.file_name, valid.line_num);
		break;
	case INVALID_SYMBOL:
		printf("\nError at file: %s, line %d, Invalid symbol. symbol should contain only letters or digits and shouldn't be more then 31 chars\n", valid.file_name, valid.line_num);
		break;
	case WRONG_NUMBER_OF_OPERATORS:
		printf("\nError at file: %s, line %d, Invalid number of operands\n", valid.file_name, valid.line_num);
		break;
	case SYMBOL_ALREADY_EXISTS:
		printf("\nError at file: %s, line %d, label already exists, you can't redifine label\n", valid.file_name, valid.line_num);
		break;
	case WRONG_ADDRESSING_MODE:
		printf("\nError at file: %s, line %d, Wrong addressing mode\n", valid.file_name, valid.line_num);
		break;
	case SYMBOL_DOESNT_EXISTS:
		printf("\nError at file: %s, line %d, You're trying reference to symbol which does't exist\n", valid.file_name, valid.line_num);
		break;
	case DISPLACEMENT_EXTERNAL_LABELS_ERROR:
		printf("\nError at file: %s, line %d, You're cannot using external label in DISPOSAL addressing mode\n", valid.file_name, valid.line_num); /*DISPOSAL - miun mirhak*/
		break;

	case MISSING_QUATS:
		printf("\nError at file: %s,line %d, string must be defined between quotation marks\n", valid.file_name, valid.line_num);
		break;

	case COMMAS_FIX_WRONG:
		printf("\nError at file: %s,line %d, commas fix wrong! \n", valid.file_name, valid.line_num);
		break;


	default:
		printf("\nError at file: %s, fail to parse the file! ", valid.file_name);
		break;
	}
}