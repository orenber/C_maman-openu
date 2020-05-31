Mycomp:	mycomp.o complex.o
	gcc -g -ansi -Wall -pedantic mycomp.o complex.o -o Mycomp -lm
mycomp.o:  mycomp.c complex.h
	gcc -c -ansi -Wall -pedantic mycomp.c -o mycomp.o -lm
complex.o:  complex.c complex.h
	gcc -c -ansi -Wall -pedantic complex.c -o complex.o -lm
