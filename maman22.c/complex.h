#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int real;
	int img;
}complex;

complex read_comp(complex comp, int real, int img);

void print_comp(complex comp);

complex add_comp(complex comp1, complex comp2);

complex sub_comp(complex comp1, complex comp2);

complex mult_comp_real(complex comp1, int real);

complex mult_comp_img(complex comp1, int img);

unsigned int abs_comp(complex comp1);