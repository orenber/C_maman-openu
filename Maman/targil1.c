// ***********************************************************************
// Assembly         : 
// Author           : Oren Berkovitch
// Created          : 03-25-2020
//
// Last Modified By : Oren Berkovitch
// Last Modified On : 04-03-2020
// ***********************************************************************
// <copyright file="targil1.c" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>
/* this program get string from the user and check 
 if the ascii latter that contain the string is in:
1.  Ascending order
2.  Monotonic ascending order
3.  Descending order
4.  Monotonic descending order
5.  Un order
*/
//</summary>
// ***********************************************************************
#include <stdio.h>
#include <string.h>

 
typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef enum
{

	UP=1,DOWN=-1,CENTER=0
}DIRECTION;

void f_sequence(char text[],char* str);
void direction_dictionary(DIRECTION flag, BOOL real, char* str);

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>int.</returns>
int main()
{
    char str_direction[30]="" ;/* string direction*/
	char text[100]; /* text input */

	printf("Please insert text :\n");
	fgets(text,(int)strlen(text), stdin);
	/* remove the \n trail char*/
	text[strlen(text) - 1] = '\0';

	f_sequence(text, str_direction);
	printf("the string is in: %s ", str_direction);

	
	getchar();

	return 0;
}

/// <summary>
/// fs sequence.
/* this function check the the direction of the string
 if the ascii latter that contain the string is in:
1.  Ascending order
2.  Monotonic ascending order
3.  Descending order
4.  Monotonic descending order
5.  Un order
 
 it Checks the direction of each letter pair
 relative to the previous letter pair 
 for the whole string 
*/
/// </summary>
/// <param name="text">The text.</param>

void f_sequence(char text[], char *string_direction) {

	DIRECTION direction,/* direction of pair char */
		previous_direction= CENTER; /* direction of previous pair char*/
	BOOL is_monotonic = TRUE;/*is the string is monotonic seris? */

	int text_length = (int)strlen(text); /* text length */


	for (int i = 1; i < text_length; ++i) {
		  

		if (text[i - 1]>text[i]) {
			direction = DOWN;
			if (previous_direction==UP) {
				strcpy(string_direction,"un_order");
				/* in the case the string is un order
				their is no need for more search - get out*/
				break;
			}
		}
		else if (text[i - 1] < text[i]) {
			direction = UP;
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
				direction = DOWN;
			}
			else if (previous_direction==UP) {
				direction = UP;
			}
			else {

				direction = CENTER;
			}
		}

		previous_direction = direction;

	}
	 
		direction_dictionary(direction, is_monotonic, string_direction);
 
		return;
}

/// <summary>
/* Directions  dictionary.
	this function get the Direction of the last pair letters direction
	and monotonic parameter and return the whole string direction */
/// </summary>
/// <param name="DIRECTION">The dir.</param>
/// <param name="monotonic">The monotonic.</param>
void direction_dictionary(DIRECTION dir, BOOL monotonic,char *string_direction) {
  
	if (strcmp(string_direction, "un_order") == 0)
	{
		return;
	}

	if (dir == DOWN) {
		if (monotonic == TRUE) {
			strcat(string_direction, "monotonic descending order");
		}
		else {
			strcat(string_direction, "descending order");
		}
	}
	else if (dir == UP) {
		if (monotonic == TRUE) {
			strcat(string_direction, "monotonic ascending order");
		}
		else {
			strcat(string_direction, "ascending order");
		}
	}
	else if (dir == CENTER) {
		strcat(string_direction, "ascending order");
	}
	
}

