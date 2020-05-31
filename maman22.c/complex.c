
#include "complex.h"



 /*<summary> read compex name and write the complex var , return complex pointer*/
Complex* read_comp(Complex *complexvar, double real, double img) {
	 
		 complexvar->real = real;
		 complexvar->img = img;
		 return complexvar;
}

/* <summary> print complex number*/
void print_comp(Complex comp) {

	printf("%.2f + (%.2f)i\n", comp.real, comp.img);
	return ;
}

/* <summary> add two complex number and return complex number result*/
Complex add_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real + comp2.real;
	result.img = comp1.img + comp2.img;
	return result;
}

/* <summary> substruct one complex number from another and return complex number result*/
Complex sub_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real - comp2.real;
	result.img = comp1.img - comp2.img;
	return result;
}

/* <summary> multiple complex number with real number and return complex number result*/
Complex mult_comp_real(Complex comp1, double real) {
	Complex result;

	result.real = real*comp1.real ;
	result.img = real*comp1.img;
	return result;
}

/* <summary> multiple complex number with imagenary number and return complex number result*/
Complex mult_comp_img(Complex comp1, double img) {
	Complex result;

	result.real = comp1.img*img*-1 ;
	result.img =  comp1.real*img;
	return result;
}

/* <summary> multiple one complex number with another complex number and return complex result*/
Complex mult_comp_comp(Complex comp1, Complex comp2) {
	Complex result;

	result.real = comp1.real*comp2.real-comp1.img*comp2.img;
	result.img = comp1.real*comp2.img +comp2.real* comp1.img;
	return result;
}

/* <summary> return complex number abselute number */
double abs_comp(Complex comp) {
	
	double absValue;
	
	absValue = sqrt(pow(comp.real, 2) + pow(comp.img,2));
	
	return absValue;
}

/* stop thg main function - create flag state True/False*/
Bool stop(char command[]) {

	Bool state;
	state = (strcmp(command, "stop") == 0) ? True : False;

	return state;
};


/* all legal command*/
const char *command_leagal[LEN_COMMAND] = {
	"read_comp","print_comp","add_comp","sub_comp",
	"mult_comp_real" ,  "mult_comp_img" ,  "mult_comp_comp",
	"abs_comp", "stop"
};

/* all legal complex name*/
const char *Complex_leagal[LEN_Complex] = {"A","B","C","D","E","F" };

/* seperator for parsing text*/
const char seperator[] = ", \t\r\n";


