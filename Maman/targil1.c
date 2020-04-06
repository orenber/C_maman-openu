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

char* f_sequence(char string[]);
char* direction_dictionary(DIRECTION flag, BOOL real);

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>int.</returns>
int main()
{
	char *string_direction ="";
	char text[30];
	printf("Please insert text :\n");
	fgets(text,(int)strlen(text), stdin);
	/* remove the \n trail char*/
	text[strlen(text) - 1] = '\0';

	string_direction = f_sequence(text);
	
	printf("the text series is :%s", string_direction);
	
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
*/
/// </summary>
/// <param name="text">The text.</param>
/// <returns>char *.</returns>
char* f_sequence(char text[]) {
	DIRECTION direction,
		previous_direction= CENTER;
	BOOL Monotonic = TRUE;
	char *string_direction = "",
		*str1 = "", *str2 = "";
	int text_length = (int)strlen(text);


	for (int i = 1; i < text_length; ++i) {
		    str1 = text[i - 1],
			str2 = text[i];

		if (str1>str2) {
			direction = DOWN;
			if (previous_direction==UP) {
				string_direction = "un_order";
				break;
			}
		}
		else if (str1 < str2) {
			direction = UP;
			if (previous_direction==DOWN) {
				string_direction = "un_order";
				break;
			}
		}
		else if (str1 == str2) {
			Monotonic = FALSE;
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
	if (strcmp(string_direction, "un_order") != 0) {
		string_direction = direction_dictionary(direction, Monotonic);
	}
	return string_direction;
}

/// <summary>
/* Directions  dictionary.
	this function get the Direction of the last pair letters direction
	and real parameter and return the whole string direction */
/// </summary>
/// <param name="DIRECTION">The dir.</param>
/// <param name="monotonic">The monotonic.</param>
/// <returns>char * string direction.</returns>
char* direction_dictionary(DIRECTION dir, BOOL monotonic) {
	char string_direction[30] = "";
	if (dir == DOWN) {
		if (monotonic == TRUE) {
			strcat(string_direction, "Monotonic descending order");
		}
		else {
			strcat(string_direction, "Descending order");
		}
	}
	else if (dir == UP) {
		if (monotonic == TRUE) {
			strcat(string_direction, "Monotonic ascending order");
		}
		else {
			strcat(string_direction, "Ascending order");
		}
	}
	else if (dir == CENTER) {
		strcat(string_direction, "Ascending order");
	}

	return string_direction;
}

