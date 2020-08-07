#include "interface.h"




int main(int argc, char* argv[])
{  

	char file_to_read[MEM] = "";         /* file name that i read from*/
	char line_read[BUFFERSIZE] = "";     /* digit number string*/
	char *output = "";                   /* output from the user */
    BOOL is_file_read_exist = False,     /* is the file that i read from exist?*/
		 is_file_write_exist = False;    /* is the file that i write to exist?*/
	FILE* filePointer;

	
	int  nargin = argc;                  /* number of input in */
	int i;

	/* check file name inputs */
	if ((nargin >= 2) && (argv[1] != NULL)) {
		strcpy(file_to_read, argv[1]);
		/* check if the file read exist*/
		is_file_read_exist = file_exists(file_to_read);
		if (is_file_read_exist == True) {
			filePointer = fopen(file_to_read, "r");
		}
		else if (is_file_read_exist == False) {
			/* if the file not exist the programe shoude stop*/
			exit(1);
		}
	}

	do{
		printf("%s", line_read);
		/* get the input from the file - read line by line*/
		output = fgets(line_read, BUFFERSIZE, filePointer);
		command_manager(output);
	} while (output != NULL);


	getchar();

	return 0;
}

void command_manager(char command[]) {
	
	 char *command_section = " ";
	 BOOL isFlag, isFunction;
	 struct operationFunc opcodeFunc;
     /* parse the command into 3 category */
	 command_section = strtok(command, seperator);
	 /* ist aflag? */
	 isFlag = assert_command(command_section,&flag_legal,8,"");
	 if (isFlag)
	 {
		 flag_manger(command_section);
	 }
	 else
	 {
		 isFunction = assert_command(command_section, &function_legal,16, "");
		 if (isFunction) {
			 func_manger(command_section,&opcodeFunc);
		 }
	 }
	 printf("%s",command_section);
}

void flag_manger(char flag[]) {

	printf("\nthis is aflag: %s\n", flag);

}

void table_funct_opcode(char func[], struct operationFunc *opcodeFunc) {

	printf("\nthis is function: %s\n", func);
	strcpy(opcodeFunc->name, func);

	if (strcmp(func, "mov") == 0) {
		opcodeFunc->opcode = 0;
		opcodeFunc->funct = NULL;
		
	}
	else if (strcmp(func, "cmp") == 0) {
		opcodeFunc->opcode = 1;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "add") == 0) {
		
		opcodeFunc->opcode = 2;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "sub") == 0) {
		
		opcodeFunc->opcode = 2;
		opcodeFunc->funct = 2;
		 
	}
	else if (strcmp(func, "lea") == 0) {
		
		opcodeFunc->opcode = 4;
		opcodeFunc->funct = NULL;
		
	}
	else if (strcmp(func, "clr") == 0) {
		
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "not") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 2;		
	}
	else if (strcmp(func, "inc") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 3;
	}
	else if (strcmp(func, "dec") == 0) {
		opcodeFunc->opcode = 5;
		opcodeFunc->funct = 4;
	}
	else if (strcmp(func, "jmp") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 1;
	}
	else if (strcmp(func, "bne") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 2;
	}
	else if (strcmp(func, "jsr") == 0) {
		opcodeFunc->opcode = 9;
		opcodeFunc->funct = 3;
	}
	else if (strcmp(func, "red") == 0) {
		opcodeFunc->opcode = 12;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "prn") == 0) {
		opcodeFunc->opcode = 13;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "rts") == 0) {
		opcodeFunc->opcode = 14;
		opcodeFunc->funct = NULL;
	}
	else if (strcmp(func, "stop") == 0) {
		opcodeFunc->opcode = 15;
		opcodeFunc->funct = NULL;
	}
		 

}












