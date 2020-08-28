#include "Parser.h"

BOOL is_legal_label(char label[]) {

	BOOL is_legal;
	int length = strlen(label);

	/* must start with latter  */
	 is_legal = isalpha(label[0]);
	 if (!is_legal) {
		 printf("%s","the first latter must start with alpha char");
		 return is_legal;
	 }
	/* max length 31 chars */
	 is_legal = length - 1 <= NAME; /* extra one for ':' chars*/
	 if (!is_legal) {
		 printf("max length must be less than %d chars", NAME);
		 return is_legal;
	 }
	/* end with : only once*/
	 is_legal = label[length-1] == ':';
	 if (!is_legal) {
		 printf("%s", "latter must end whit ':' ");
		 return is_legal;
	 }
	 /* latter ":" apperc only once*/
	 is_legal = char_apperance(label, ':') == 1 ;
	 if (!is_legal) {
		 printf("%s", "latter ':' must appers only once ");
		 return is_legal;
	 }
    /* not allow abuilt in label as add ,sub etc*/
	 is_legal = !assert_command(label, &instructionType, 16, "");
	 if (!is_legal) {
		 printf("%s", "not allow build in instruction command");
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
		printf("%s", "the first latter must start with alpha char");
		return is_legal;
	}
	/* max length 31 chars */
	is_legal = length <= 31;
	if (!is_legal) {
		printf("%s", "max length must be less than 31 chars");
		return is_legal;
	}

	/* not allow abuilt in label as add ,sub etc*/
	is_legal = !assert_command(label, &instructionType, 16, " not allow build in instruction command");
	if (!is_legal) {
		return is_legal;
	}

	return is_legal;
}




BOOL is_legal_number(char label[]) {

	/* must be real number */

}

