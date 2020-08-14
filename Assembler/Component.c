#include "interface.h"


char mov[3], sub[3], not[3],
jmp[3], red[3], cmp[3], lea[3] ,
inc[3], bne[3], pnr[3], add[3],
clr[3], dec[3], jsr[3], rts[3], stop[4];


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
	"MAIN","LOOP","END"
   ,"STR","LIST","K"
};

const char *varType[] = {

	".string",".data"
};

 /* seperator for parsing text*/
const char seperator[] = {':',' ','\t','\r','\n'};
/* all legal register name*/
const char *Register_leagal[LEN_Register] = {"r0", "r1", "r2", "r3","r4", "r5","r6", "r7" };




