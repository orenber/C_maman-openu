#include "interface.h"
void command_manager(char command[]);

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
			 func_manger(command_section);
		 }
	 }
	 printf("%s",command_section);
}

void flag_manger(char flag[]) {

	printf("\nthis is aflag: %s\n", flag);

}


void func_manger(char func[]) {

	printf("\nthis is function: %s\n", func);

}











