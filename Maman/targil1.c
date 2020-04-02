#include <stdio.h>
#include <string.h>

typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

char* f_sequence(char string[]);
char* direction_dictionary(char flag[], BOOL real);

int main()
{
	char *direction = "";
	char text[20];
	printf("Please insert text :\n");
	scanf("%s", text);
	direction = f_sequence(text);
	printf("the text series is %s", direction);
	getchar();

	return 0;
}

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

