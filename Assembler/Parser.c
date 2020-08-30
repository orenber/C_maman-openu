#include "Parser.h"

BOOL is_legal_label(char label[]) {

	BOOL is_legal;
	const char towpoints = ':';
	int length = strlen(label);

	/* must start with latter  */
	 is_legal = isalpha(label[0]);
	 if (!is_legal) {
		 printf("\nError in label: %s\n", label);
		 printf("%s","the first latter must start with alpha char");
		 return is_legal;
	 }
	/* max length 31 chars */
	 is_legal = length - 1 <= NAME; /* extra one for ':' chars*/
	 if (!is_legal) {
		 printf("\nError in label: %s\n", label);
		 printf("max length must be less than %d chars", NAME);
		 return is_legal;
	 }
	/* end with : only once*/
	 is_legal = label[length-1] == towpoints;
	 if (!is_legal) {
		 printf("\nError in label: %s\n", label);
		 printf("latter must end whit %c",towpoints);
		 return is_legal;
	 }
	 /* latter ":" apperc only once*/
	 is_legal = char_apperance(label, towpoints) == 1 ;
	 if (!is_legal) {
		 printf("\nError in label: %s\n", label);
		 printf("%s", "latter ':' must appers only once ");
		 return is_legal;
	 }


    /* not allow abuilt in label as add ,sub etc*/
	 is_legal = !assert_command(label, instructionType, INSTRUCTION_NUM, "");
	 if (!is_legal) {
		 printf("\nError in label: %s\n", label);
		 printf("/n%s", "not allow build in instruction command");
		 return is_legal;
	 }
	 

	 return is_legal;
}

BOOL is_legal_symbol(char symbol[]) {

	BOOL is_legal;
	int length = strlen(symbol);

	/* must start with latter  */
	is_legal = isalpha(symbol[0]);
	if (!is_legal) {
		printf("\nError in symbol: %s\n", symbol);
		printf("the first latter must start with alpha char" );
		return is_legal;
	}
	/* max length 31 chars */
	is_legal = length - 1 <= NAME; /* extra one for ':' chars*/
	if (!is_legal) {
		printf("\nError in symbol: %s\n", symbol);
		printf(" max length must be less than %d chars", NAME);
		return is_legal;
	}
     
	is_legal = checkString(symbol);
	if (!is_legal) {
		printf("\nError in symbol: %s\n", symbol);
		printf("symbol must contain only alfabet and numbers");
		return is_legal;
	}
 
	/* not allow abuilt in label as add ,sub etc*/
	is_legal = !assert_command(symbol,  instructionType, INSTRUCTION_NUM, "");
	if (!is_legal) { 
		printf("\nError in symbol: %s\n", symbol);
		printf("/nnot allow build in instruction command");
		return is_legal;
	}


	return is_legal;


}

BOOL is_undefine_label(char label[]) {

	BOOL is_legal;
	int length = strlen(label);

	/* must start with latter  */
	is_legal = isalpha(label[0]);
	if (!is_legal) {
		printf("\nError in label: %s\n", label);
		printf("%s", "the first latter must start with alpha char");
		return is_legal;
	}
	/* max length 31 chars */
	is_legal = length <= 31;
	if (!is_legal) {
		printf("\nError in label: %s\n", label);
		printf("%s", "max length must be less than 31 chars");
		return is_legal;
	}

	/* not allow abuilt in label as add ,sub etc*/
	is_legal = !assert_command(label,  instructionType, INSTRUCTION_NUM, "");
	if (!is_legal) {

		printf("\nError in label: %s\n", label);
		printf("not allow abuilt in label as add ,sub etc");
		return is_legal;
	}

	return is_legal;
}


BOOL is_legel_string_data(char str[]) {
	BOOL legal = True;
	/* ther must be double qute in the data*/
	if (char_apperance(str, '"') < 2) {
		printf("Error in .string %s",str);
		printf("double qute must appers twice");
		return False;
	};

	return legal;
}

BOOL is_legal_number(char var[]) {

	BOOL is_legal = False;
	int commas_num = 0;
	/* must be real number */
	is_legal = var[0]!=',';

	/* double cooma in row are not allow */
		commas_num = char_apperance(var, ',');
	is_legal = assert_comma(var, commas_num);
	if (!is_legal) {
		printf("\nError in .data var: %s\n", var);
		return is_legal;
	}


	is_legal = assert_nargin(var, commas_num + 1);
	if (!is_legal) {
		printf("\nError in .data var: %s\n", var);
		printf("the first latter must start with digit char");
		return is_legal;
	}


	return is_legal;


}

