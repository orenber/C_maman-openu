#include "complex.h"


complex read_comp(complex comp, int real, int img) {
	comp.real = real;
	comp.img = img;
	return comp;
}

void print_comp(complex comp) {

	print("%1d+i(%1d)", comp.real, comp.img);
	return;
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

complex mult_comp_real(complex comp1, int real) {
	complex result;

	result.real = real*comp1.real ;
	result.img = real*comp1.img;
	return result;
}

complex mult_comp_img(complex comp1, int img) {
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

unsigned int abs_comp(complex comp1) {
	
	unsigned int absValue;
	absValue = sqrt(comp1.real^2 -comp1.img^2,2);
	
	return absValue;
}




