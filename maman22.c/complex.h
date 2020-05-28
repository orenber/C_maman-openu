#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>




const char *command_leagal[9];
const char *Complex_leagal[6];

typedef struct {
	double real;
	double img;
}Complex;

Complex A, B, C, D, E, F;


typedef enum {
	False = 0, True = 1
}Bool;


/*struct {
	char name;
	Complex *comp;
}compexDictionary[] = {
	{'A',&A},{'B',&B },{ 'C',&C },{'D',&D },{ 'E',&E },{ 'F',&F }
};*/

Complex read_comp(Complex comp, double real, double img);

void print_comp(Complex comp);

Complex add_comp(Complex comp1, Complex comp2);

Complex sub_comp(Complex comp1, Complex comp2);

Complex mult_comp_real(Complex comp1, double real);

Complex mult_comp_img(Complex comp1, double img);

Complex mult_comp_comp(Complex comp1, Complex comp2);

double abs_comp(Complex comp1);



Bool stop(char command[]);

void setCommand(char command[], char seperator[]);

void read_comp_from_user(char seperator[]);

void print_comp_from_user(char seperator[]);

void add_comp_from_user(char seperator[]);

void sub_comp_from_user(char seperator[]);

void mult_comp_real_from_user(char seperator[]);

void mult_comp_img_from_user(char seperator[]);

void mult_comp_comp_from_user(char seperator[]);

void abs_comp_from_user(char seperator[]);

void abs_comp_from_user(char seperator[]);



Complex getComplex(char complexName);

Bool assert_command(char real_command[], char *expected_command[], char messege[]);

Bool assert_input(int get_input, int expected_input);

Bool assert_Complex_type(char Complex_type[]);

Bool assert_number(char numberStr[]);

Bool assert_comma(char comma);





