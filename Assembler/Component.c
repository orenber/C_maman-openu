#include "interface.h"


char mov[3], sub[3], not[3],
jmp[3], red[3], cmp[3], lea[3] ,
inc[3], bne[3], pnr[3], add[3],
clr[3], dec[3], jsr[3], rts[3], stop[4];

struct {
	char name[4];
	int funct;
	int opcode;
}operationDictionary[] = {
	{ "mov",&mov },{ "cmp",&cmp },{ "add",&add },
    { "sub",&sub },{ "lea",&lea },{ "clr",&clr },
    { "not",&not },{ "inc",&inc },{ "dec",&dec },
    { "jmp",&jmp },{ "bne",&bne },{ "jsr",&jsr },
    { "red",&red },{ "prn",&pnr },{ "rts",&rts },
    { "stop",&stop },{ '#',NULL }
};


/* all legal function*/
const char *function_legal[] = {
  "mov","cmp","add",
  "sub","lea","clr",
  "not","inc","dec",
  "jmp","bne","jsr",
  "red","prn","rts","stop"
};

/* all legal flags*/
const char *flag_legal[] = {
	"LIST","MAIN","LOOP",
	"END","STR","LIST",
	".entry",".extern"
};
const char seperator[] = ", \t\r\n"; /* seperator for parsing text*/





