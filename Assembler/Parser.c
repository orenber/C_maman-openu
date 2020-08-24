#include "Parser.h"

BOOL is_legal_label(char label[]) {

	BOOL is_legal;
	int length = strlen(label);

	/* must start with latter  */
	 is_legal = !isdigit(label[0]);
	/* max length 31 chars */
	 is_legal = length <= 31;
	/* end with : only once*/
	 is_legal = label[length] == ':';
	/* the label cnot be difined more than once in the symbol table */
	 
    /* not allow abuilt in label as add ,sub etc*/
}


BOOL is_legal_number(char label[]) {

	/* must be real number */

}

