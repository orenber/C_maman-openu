#include "Component.h"


/* all legal function*/
const char *instructionType[] = {
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

const char *guidanceType[] = {

	".string",".data",".extern", ".entry"
};

 /* seperator for parsing text*/
const char seperator[] = {':',' ','\t','\r','\n'};
/* all legal register name*/
const char *register_leagal[] = {"r0", "r1", "r2", "r3","r4", "r5","r6", "r7" };




