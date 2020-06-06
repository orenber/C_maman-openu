#pragma once

  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM 30

typedef enum
{
	False = 0, True = 1

}BOOL;

/* <summary>
dictionary_number - convert string number digits to words number.
<input>
char number[] - number string like: 85 , 45 etc.
char number_string[] - the word number- exp :six , seventeen etc.
</input>
</summary>*/
void dictionary_number(char number[], char number_string[]);

/* <summary>
dictionary_twenties - convert string number digits to words number 10 - 19
(special case).
<input>
char number - number string like: 1 , 3 etc.
char number_string[] - the word number- exp :sixteen , seventeen etc.
</input>
</summary>*/
void dictionary_twenties(char number, char number_string[]);
/* <summary>
read_file - read file line by line to string array
<input>
char fileName[] - file name 
char number_list[] - file text read
</input>
</summary>*/
BOOL read_file(char fileName[], char number_list[]);

void write_file(char fileName[], char word[]);



 