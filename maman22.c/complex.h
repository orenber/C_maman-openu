#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	double real;
	double img;
}Complex;

Complex A, B, C, D, E, F;

/*struct {
	char name;
	Complex *comp;
}compexDictionary[] = {
	{'A',&A},{'B',&B },{ 'C',&C },{'D',&D },{ 'E',&E },{ 'F',&F }
};*/

Complex* read_comp(Complex comp, double real, double img);

void print_comp(Complex comp);

Complex add_comp(Complex comp1, Complex comp2);

Complex sub_comp(Complex comp1, Complex comp2);

Complex mult_comp_real(Complex comp1, double real);

Complex mult_comp_img(Complex comp1, double img);

Complex mult_comp_comp(Complex comp1, Complex comp2);

double abs_comp(Complex comp1);

void stop(void);

void setCommand(char command[], char seperator[]);

Complex getComplex(char complexName);




