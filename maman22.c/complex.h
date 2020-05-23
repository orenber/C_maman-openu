#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	double real;
	double img;
}complex;

complex A, B, C, D, E, F;

complex read_comp(complex comp, double real, double img);

void print_comp(complex comp);

complex add_comp(complex comp1, complex comp2);

complex sub_comp(complex comp1, complex comp2);

complex mult_comp_real(complex comp1, double real);

complex mult_comp_img(complex comp1, double img);

double abs_comp(complex comp1);

void stop(void);

void setCommand(char command[]);


