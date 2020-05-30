#include "complex.h"

struct {
	char name;
	Complex *comp;
}compexDictionary[] = {
	{ 'A',&A },{ 'B',&B },{ 'C',&C },{ 'D',&D },{ 'E',&E },{ 'F',&F },{'#',NULL}
};

Complex* read_comp(char complexName, double real, double img) {
	 
	int i;
	for (i = 0; LEN_Complex > i; i++) {
		if (compexDictionary[i].name == complexName) {
			compexDictionary[i].comp->real = real;
			compexDictionary[i].comp->img = img;
			return compexDictionary[i].comp;
			
		}
	}

	return compexDictionary[LEN_Complex].comp;
	 
}

void print_comp(Complex comp) {

	printf("%.2f + (%.2f)i\n", comp.real, comp.img);
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

double abs_comp(Complex comp) {
	
	double absValue;
	
	absValue = sqrt(pow(comp.real, 2) + pow(comp.img,2));
	
	return absValue;
}


Complex* getComplexVar(char complexName) {
	
	int i;
	for (i = 0; LEN_Complex > i; i++) {
		if (compexDictionary[i].name == complexName) {
			return compexDictionary[i].comp;
		 }
	}
		
	return compexDictionary[LEN_Complex].comp;
}



const char *command_leagal[LEN_COMMAND] = {
	"read_comp","print_comp","add_comp","sub_comp",
	"mult_comp_real" ,  "mult_comp_img" ,  "mult_comp_comp",
	"abs_comp", "stop"
};

const char *Complex_leagal[LEN_Complex] = { "A","B","C","D","E","F" };

const char seperator[] = ", \t\r\n";


