
#include <stdio.h>
#include <string.h>

#define MEM 30

void dictionary_number(char number[], char number_string[]);

void twenties_dictionary(char number, char number_string[]);


int main()
{
	char number_string[MEM] = "";
	char number[2] = "88";
	dictionary_number(number, number_string);
	printf("%s", number_string);
	getchar();
	return 0;
}


void dictionary_number(char number[],char number_string[]) {

	int index = 0,
		length = (int)strlen(number);

	if (length < 2) {
		strcat(" ", number);
		index = 1;
	}

	for (index; length > index; index++) {

		switch (number[index])
		{
		case '1':
			index++;
			if (number[0] == ' ') {
				strcat(number_string, "one");			
			}
			else if (number[0] == '1') {
				twenties_dictionary(number[1], number_string);	
			}
			break;
		case '2':
			if (index == 1) {
				strcat(number_string, "two");
			}
			else if (index == 0) {
				strcat(number_string, "twenty");
				strcat(number_string, " ");
			}
			break;
		case '3':
			if (index == 1) {
				strcat(number_string, "three");
			}
			else if (index == 0) {
				strcat(number_string, "thirty");
				strcat(number_string, " ");
			}
			break;
		case '4':
			if (index == 1) {
				strcat(number_string, "four");
			}
			else if (index == 0) {
				strcat(number_string, "forty");
				strcat(number_string, " ");

			}
			break;
		case '5':
			if (index == 1) {
				strcat(number_string, "five");
			}
			else if (index == 0) {
				strcat(number_string, "fifty");
				strcat(number_string, " ");

			}
			break;
		case '6':
			if (index == 1) {
				strcat(number_string, "six");
			}
			else if (index == 0) {
				strcat(number_string, "sixty");
				strcat(number_string, " ");
			}
			break;

		case '7':
			if (index == 1) {
				strcat(number_string, "seven");
			}
			else if (index == 0) {
				strcat(number_string, "seventy");
				strcat(number_string, " ");
			}
			break;
		case '8':
			if (index == 1) {
				strcat(number_string, "eight");
			}
			else if (index == 0) {
				strcat(number_string, "eighty");
				strcat(number_string, " ");
			}
			break;
		case '9':
			if (index == 1) {
				strcat(number_string, "nine");
			}
			else if (index == 0) {
				strcat(number_string, "ninety");
				strcat(number_string, " ");
			}
			break;
		case '0':
			if (index == 1) {
				strcat(number_string, "zero");
			}
			break;


		default:
			break;
		}
	}
}

void twenties_dictionary(char number, char number_string[]) {
	
	switch (number)
	{
	case '0':
		strcat(number_string, "ten");
		break;
	case '1':
		strcat(number_string, "eleven");
		break;
	case '2':
		strcat(number_string, "twelve");
		break;
	case '3':
		strcat(number_string, "thirteen");
		break;
	case '4':
		strcat(number_string, "fourteen");
		break;
	case '5':
		strcat(number_string, "fifteen");
		break;
	case '6':
		strcat(number_string, "sixteen");
		break;
	case '7':
		strcat(number_string, "seventeen");
		break;
	case '8':
		strcat(number_string, "eighteen");
		break;
	case '9':
		strcat(number_string, "nineteen");
		break;

	default:
		break;

	}
	return;


}