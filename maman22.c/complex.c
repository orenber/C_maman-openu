#include "complex.h"


Complex read_comp(Complex comp, double real, double img) {
	comp.real = real;
	comp.img = img;
	return comp;
}

void print_comp(Complex comp) {

	printf("%1f + (%1f)i\n", comp.real, comp.img);
	return ;
}

Complex add_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real + comp2.real;
	result.img = comp1.img + comp2.img;
	return result;
}

Complex sub_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real - comp2.real;
	result.img = comp1.img - comp2.img;
	return result;
}

Complex mult_comp_real(Complex comp1, double real) {
	Complex result;

	result.real = real*comp1.real ;
	result.img = real*comp1.img;
	return result;
}

Complex mult_comp_img(Complex comp1, double img) {
	Complex result;

	result.real = comp1.img*img*-1 ;
	result.img =  comp1.real*img;
	return result;
}

Complex mult_comp_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real*comp2.real-comp1.img*comp2.img;
	result.img = comp1.real*comp2.img +comp2.real* comp1.img;
	return result;
}

double abs_comp(Complex comp1) {
	
	double absValue;
	
	absValue = sqrt(pow(comp1.real, 2) - pow(comp1.img,2));
	
	return absValue;
}


Complex getComplex(char complexName) {

	Complex comp;

	switch (complexName) {

	case 'A':
		comp = A;
		break;

	case 'B':
		comp = B;
		break;

	case 'C':
		comp = C;
		break;

	case 'D':
		comp = D;
		break;

	case 'E':
		comp = E;
		break;

	case 'F':
		comp = F;
		break;
	}
	return comp;

}



const char *command_leagal[LEN_COMMAND] = {
	"read_comp","print_comp","add_comp","sub_comp",
	"mult_comp_real" ,  "mult_comp_img" ,  "mult_comp_comp",
	"abs_comp", "stop"
};

const char *Complex_leagal[LEN_Complex] = {"A","B","C","D","E","F"};

const char seperator[] = ", \t\r\n";


