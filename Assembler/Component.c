#include "interface.h"

typedef enum {
	r0 = 0, r1 = 1, r2 = 2,
	r3 = 3, r4 = 4, r5 = 5,
	r6 = 6 ,r7 = 7
}Register;

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

