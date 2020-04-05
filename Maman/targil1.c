// ***********************************************************************
// Assembly         : 
// Author           : orenber
// Created          : 03-25-2020
//
// Last Modified By : orenber
// Last Modified On : 04-03-2020
// ***********************************************************************
// <copyright file="targil1.c" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <stdio.h>
#include <string.h>

/// <summary>
/// Enum __unnamed_enum_0039_1
/// </summary>
typedef enum
{
	/// <summary>
	/// The false
	/// </summary>
	FALSE = 0, TRUE = 1

}BOOL;

char* f_sequence(char string[]);
char* direction_dictionary(char flag[], BOOL real);

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>int.</returns>
int main()
{
	char *direction = "";
	char text[20];
	printf("Please insert text :\n");
	gets(text);
	direction = f_sequence(text);
	printf("the text series is %s", direction);
	getchar();

	return 0;
}

/// <summary>
/// fs the sequence.
/// </summary>
/// <param name="string">The string.</param>
/// <returns>char *.</returns>
char* f_sequence(char string[]) {
	char *direction = "up",
		*previos_direction = "un_order",
		*string_direction = "",
		*str1 = "", *str2 = "";

	BOOL real = TRUE;

	for (int i = 1; i < strlen(string); ++i) {
		    str1 = string[i - 1],
			str2 = string[i];


		if (str1>str2) {
			direction = "down";
			if (strcmp(previos_direction, "up") == 0) {
				direction = "un_order";
				break;
			}
		}
		else if (str1 < str2) {
			direction = "up";
			if (strcmp(previos_direction, "down") == 0) {
				direction = "un_order";
				break;
			}
		}
		else if (str1 == str2) {
			real = FALSE;
			if (strcmp(previos_direction, "down") == 0) {
				direction = "down";
			}
			else if (strcmp(previos_direction, "up") == 0) {
				direction = "up";
			}
			else {

				direction = "center";
			}
		}

		previos_direction = direction;

	}

	string_direction = direction_dictionary(direction, real);
	return string_direction;
}

/// <summary>
/// Directions the dictionary.
/// </summary>
/// <param name="flag">The flag.</param>
/// <param name="real">The real.</param>
/// <returns>char *.</returns>
char* direction_dictionary(char flag[], BOOL real) {
	char direction[20] = "";
	strcat(direction, flag);
	if (strcmp(flag, "un_order") == 0) {

		return direction;
	}

	else if (strcmp(flag, "center") == 0) {
		
		return "up";
	}

	if (real) {
		strcat(direction, " Real");
	}

	return direction;
}

