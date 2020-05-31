
#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define LEN_COMMAND 9
#define LEN_Complex 6
#define MEM 101

const char *command_leagal[LEN_COMMAND];
const char *Complex_leagal[LEN_Complex];
const char seperator[6];

typedef struct {
	double real;
	double img;
}Complex;




typedef enum {
	False = 0, True = 1
}Bool;



Complex* read_comp(Complex *complexvar, double real, double img);

void print_comp(Complex comp);

Complex add_comp(Complex comp1, Complex comp2);

Complex sub_comp(Complex comp1, Complex comp2);

Complex mult_comp_real(Complex comp1, double real);

Complex mult_comp_img(Complex comp1, double img);

Complex mult_comp_comp(Complex comp1, Complex comp2);

double abs_comp(Complex comp1);

Complex* getComplexVar(char complexName);


Bool stop(char command[]);

void setCommand(char command[], char input_string[]);

void read_comp_from_user(char input_string[]);

void print_comp_from_user(char input_string[]);

void add_comp_from_user(char input_string[]);

void sub_comp_from_user(char input_string[]);

void mult_comp_real_from_user(char input_string[]);

void mult_comp_img_from_user(char input_string[]);

void mult_comp_comp_from_user(char input_string[]);

void abs_comp_from_user(char input_string[]);

void abs_comp_from_user(char input_string[]);

Bool stop(char command[]);




Bool assert_command(char real_command[], const char *expected_command[], int  length, char messege[]);

Bool assert_nargin(char seperator[], int expected_input);

Bool assert_Complex_type(char Complex_type[]);

Bool assert_number(char numberStr[]);

Bool assert_comma(char sentence[], int comma_sum);

int char_apperance(char word[], char token);

void remove_substring(char *s,  char *toremove);
