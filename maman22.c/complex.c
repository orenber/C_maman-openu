#include "complex.h"


complex read_comp(complex comp, double real, double img) {
	comp.real = real;
	comp.img = img;
	return comp;
}

void print_comp(complex comp) {

	printf("%1f+(%1f)i", comp.real, comp.img);
	return ;
}

complex add_comp(complex comp1, complex comp2) {
	complex result;

	result.real = comp1.real + comp2.real;
	result.img = comp1.img + comp2.img;
	return result;
}

complex sub_comp(complex comp1, complex comp2) {
	complex result;

	result.real = comp1.real - comp2.real;
	result.img = comp1.img - comp2.img;
	return result;
}

complex mult_comp_real(complex comp1, double real) {
	complex result;

	result.real = real*comp1.real ;
	result.img = real*comp1.img;
	return result;
}

complex mult_comp_img(complex comp1, double img) {
	complex result;

	result.real = comp1.img*img*-1 ;
	result.img =  comp1.real*img;
	return result;
}

complex mult_comp_comp(complex comp1, complex comp2) {
	complex result;

	result.real = comp1.real*comp2.real-comp1.img*comp2.img;
	result.img = comp1.real*comp2.img +comp2.real* comp1.img;
	return result;
}

double abs_comp(complex comp1) {
	
	double absValue;
	
	absValue = sqrt(pow(comp1.real, 2) - pow(comp1.img,2));
	
	return absValue;
}




