/***********************************************************************
 Assembly         : 
 Author           : Oren Berkovitch
 Created          : 03-25-2020

 Last Modified By : Oren Berkovitch
 Last Modified On : 04-03-2020
 ***********************************************************************
 <copyright file="sequence.c" company="">
     Copyright (c) . All rights reserved.
 </copyright>
 <summary>
 this program get string from the user and check 
 if the ascii latter that contain the string is in:
1.  Ascending order
2.  Monotonic ascending order
3.  Descending order
4.  Monotonic descending order
5.  Un order

</summary>
 ***********************************************************************
*/

#include <stdio.h>
#include <string.h>
#define MEM 101 /* max array storage*/
 
typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef enum
{
    UP=1, DOWN=-1, CENTER=0

}DIRECTION;

void f_sequence(char text[],char* str);
void direction_dictionary(DIRECTION flag, BOOL real, char* str);

/* <summary>
 main function - user friendly interface.
 </summary>
 <returns>int.</returns>
 */
int main()
{
	char str_direction[MEM] = "",/* string direction*/
		text[MEM]; /* text input */
		int input =0; 

    printf("Welcome !!! \nPress q and Enter to quit\n");
	while (input!=EOF) {

		
		printf("\n\nPlease insert text :");
		input = scanf("%s",text);
		if (strcmp(text, "q") == 0) {
			break;
		}

		f_sequence(text, str_direction);
		printf("\nThe string '%s' is in: %s ",text, str_direction);

		getchar();
	}
	return 0;
}

/* <summary>
 fs sequence.
 this function check the the direction of the string
 if the ascii latter that contain the string is in:
1.  Ascending order
2.  Monotonic ascending order
3.  Descending order
4.  Monotonic descending order
5.  Un order
 
 it Checks the direction of each letter pair
 relative to the previous letter pair 
 for the whole string 

 </summary>
 <param name="text">The text input.</param>
 <param name="*string_direction">string_direction.</param>
*/
void f_sequence(char text[], char *string_direction) {
	
	int text_length = (int)strlen(text); /* text length */
	int i;

	strcpy(string_direction, ""); /*initialize string*/
	DIRECTION current_direction,/* direction of pair char */
		previous_direction= CENTER; /* direction of previous pair char*/
	BOOL is_monotonic = TRUE;/*is the string is monotonic Series? */
	
	
	for ( i = 1; i < text_length; ++i) {
		  

		if (text[i - 1]>text[i]) {
			current_direction = DOWN;
			if (previous_direction==UP) {
				strcpy(string_direction,"un_order");
				/* in the case the string is un order
				their is no need for more search - get out*/
				break;
			}
		}
		else if (text[i - 1] < text[i]) {
			current_direction = UP;
			if (previous_direction==DOWN) {
				strcpy(string_direction,"un_order");
				/* in the case the string is un order
				their is no need for more search - get out*/
				break;
			}
		}
		else if (text[i - 1] == text[i]) {
			is_monotonic = FALSE;
			if (previous_direction==DOWN) {
				current_direction = DOWN;
			}
			else if (previous_direction==UP) {
				current_direction = UP;
			}
			else {

				current_direction = CENTER;
			}
		}

		previous_direction = current_direction;

	}
	 
		direction_dictionary(current_direction, is_monotonic, string_direction);
 
		return;
}

/* <summary>
 Directions  dictionary.
	this function get the Direction of the last pair letters direction
	and monotonic parameter and return the whole string direction 
 </summary>
    <param name="dir">The direction of the last pair chars.</param>
    <param name="is_monotonic">is the string is monotonic.</param>
	<param name="*string_direction">string direction.</param>

*/
void direction_dictionary(DIRECTION dir, BOOL is_monotonic,char *string_direction) {
  
	if (strcmp(string_direction, "un_order") == 0)
	{
		return;
	}

	if (dir == DOWN) {
		if (is_monotonic == TRUE) {
			strcpy(string_direction, "monotonic descending order");
		}
		else {
			strcpy(string_direction, "descending order");
		}
	}
	else if (dir == UP) {
		if (is_monotonic == TRUE) {
			strcpy(string_direction, "monotonic ascending order");
		}
		else {
			strcpy(string_direction, "ascending order");
		}
	}
	else if (dir == CENTER) {
		strcpy(string_direction, "ascending order");
	}

	return;
}

