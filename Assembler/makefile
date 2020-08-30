# -lm added to link math.h 

assembler: assembler.o ArrayUtils.o Assertion.o Constant.o  Errors.o File_management.o operation.o Parser.o Tables.o linkList.o Data_structures.o 
	gcc -g -ansi -Wall -pedantic ArrayUtils.o Assertion.o Constant.o Errors.o File_management.o operation.o Parser.o Tables.o linkList.o Data_structures.o assembler.c -o assembler -lm 

assembler.o: assembler.c assembler.h ArrayUtils.h Data_structures.h Assertion.h Constant.h linkList.h File_management.h operation.h Tables.h Errors.h Parser.h Libraries.h
	gcc -c -ansi -Wall -pedantic assembler.c -o assembler.o -lm

ArrayUtils.o: ArrayUtils.c ArrayUtils.h Data_structures.h Assertion.h Libraries.h -lm 
	gcc -c -ansi -Wall -pedantic ArrayUtils.c -o ArrayUtils.o -lm

Assertion.o: Assertion.c Assertion.h Data_structures.h 
	gcc -c -ansi -Wall -pedantic Assertion.c -o Assertion.o -lm

Constant.o: Constant.c  Constant.h 
	gcc -c -ansi -Wall -pedantic Constant.c -o Constant.o 

Errors.o: Errors.c Errors.h Data_structures.h 
	gcc -c -ansi -Wall -pedantic Errors.c -o Errors.o

File_management.o: File_management.c  File_management.h Data_structures.h linkList.h  
	gcc -c -ansi -Wall -pedantic File_management.c -o File_management.o -lm 

operation.o: operation.c operation.h assembler.h 
	gcc -c -ansi -Wall -pedantic operation.c -o operation.o

Parser.o: Parser.c Parser.h Data_structures.h Assertion.h Errors.h Libraries.h
	gcc -c -ansi -Wall -pedantic Parser.c -o Parser.o

Tables.o: Tables.c Tables.h assembler.h 
	gcc -c -ansi -Wall -pedantic Tables.c -o Tables.o

linkList.o: linkList.c linkList.h Data_structures.h
	gcc -c -ansi -Wall -pedantic linkList.c -o linkList.o

Data_structures.o: Data_structures.c  Data_structures.h
	gcc -c -ansi -Wall -pedantic Data_structures.c -o Data_structures.o


