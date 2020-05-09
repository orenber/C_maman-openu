/* ***********************************************************************
Assembly         :
Author           : Oren Berkovitch

Created          : 06-05-2020

Last Modified By : Oren Berkovitch
Last Modified On : 06-05-2020
***********************************************************************
<summary> 
this programe have two part :

1.the user assign value to boolean matrix in size NxN
the user will be asked who is the main parent,
than the user will match for each child leaf his parent.

2. the user ask for parent and child input and call to the path function that will search
if there is path between the child to the parent,
in the case there is path the output return TRUE,
or there isn't the output return FALSE.

</summary>
**********************************************************************
*/

#include "data.h"

/* <summary>
main function - user friendly interface.
</summary>
<returns>int.</returns>
*/
int main(){
    
	adjmat matrix; /* boolean adjacency matrix */
	int input=0, /* input from the user scanf */ 
        parent, /* leaf in the tree that connect to child leaf*/
		child; /* leaf in the tree*/
	BOOL result = FALSE;
	/*assign matrix equal to false (zeros) */
    matrix_equal(matrix,FALSE);
	
	/* build matrix by the user*/
	build_matrix(matrix);

	printf("\n\n_____________________________\nSearch the path. " 
		"check if there is path between the child to the parent \n"
		"\nPrint -1 Enter -1 Enter for Exit");
	
	while (input != EOF){

		printf("\n\nPlease insert child :");
		input = scanf("%d", &child);
		printf("Selected child : %d", child);

		printf("\n\nPlease insert parent :");
		scanf("%d", &parent);
		printf("Selected parent : %d\n", parent);

		if ((parent == -1) && (child==-1)){
			break;
		}
		    
		result = path(matrix, parent, child);
		printf(result ? "\ntrue,"
			"\nTher is a path between the child %d to the parent %d" :
			"\nfalse, \nTher is no path between the child %d to the parent %d",child,parent);
		
	}

	return 0;
}

/* <summary>
build matrix - the function is user interface to build Adjacency matrix.
the user will be ask for every child the appropriate parent
and assign boolean value (True) to the matrix.
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN.
</input>
*/
void build_matrix(adjmat mat) {
	
	int col, /*coulum matrix index*/
		row, /*row matrix index*/
		main_parent; /* tree main parent*/
		
	printf("\nWelcome !!!\n\nThis is your adjacency matrix, please "
		     "feel free to fill the indexes\n" 
		     "for every child match the appropriate parent\n\n");
		
	print_matrix(mat);

	printf("\nPlease choose one main parent from the range [0-%1d] :", N - 1);
	scanf("%d", &main_parent); 
	printf("\n");

	for (col = 0; col < N; col++) {
        if (col == main_parent){
			/* skip on the main parent since he doesn't have parent */
			continue;
		}
		else {
			printf("\nfor the given child: %1d \n"
				"Please choose one parent from the range [0-%1d] : ",col , N-1);
		    scanf("%d",&row);
			printf("\n");
			/*assign value*/
			mat[row][col] = TRUE;
		}
		 print_matrix(mat);
	};
	
	return;

}

/* <summary>
print_matrix -print Adjacency matrix in size NxN.
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN..
</input>
*/
void print_matrix(adjmat mat) {

	/* calculate size of array */
	int row = N,/* row index*/
		col= N;/* col index*/
	
	printf("\t");
	for (col = 0; col < N;col++){
		/* print index colume */
		printf("%4d", col);
	}

	printf("\n\t ");
	
	for (col = 0; col < N; col++){
		/*print separetor line*/
		printf("____");
	}
	printf("\n");
	for (row = 0; row < N; row++){
		printf("%7d [",row);
		for (col = 0; col < N; col++){
			/*  print matrix values*/
			printf(" %2d", mat[row][col]);
			if (col < N-1){
				printf(",");
			}
			else if (col == N - 1) {
				printf(" ");
			}
		}
		printf("]\n");
	}
	return;
}

/*<summary>
matrix equal - assign the same value (BOOL) for each element in the Adjacency matrix .
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN.
	BOOL number - boolen value to assige the matrix TRUE(1) or FALSE(0).
</input>
*/
void matrix_equal(adjmat mat, BOOL number) {

	int col = N, /*coulum index matrix */
		row = N; /*row index matrix */

	for (col = 0; col < N; col++){
		for (row = 0; row < N;row++){
			mat[col][row] = number;
		}
	}
	return ;
}

/* <summary>
path - check if there is path between the child leaf to the parent leaf,
in the case there is path the function output return TRUE,
otherwise output is FALSE.
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN.
	int parent - leaf in the tree that connect to child leaf.
	int child - leaf in the tree. 
</input>
<output>
	BOOL isParentFound - is there is path between the child and the parent?.
</output>
*/
BOOL path(adjmat mat,int parent,int child) {
	int row = 0, /* row index*/
		col = child; /*coulum index*/
	BOOL isParentFound = FALSE; /* is there is path between the child and the parent?*/


	printf("\n%d->", child);
	if((parent == child)&&(parent<N)&&(parent >= 0)){
		printf("%d", parent);
		isParentFound = TRUE;
	
	}
	else {

		while (row != N) {
			for (row = 0; row < N; row++) {
				/* seek parent */
				if (mat[row][col] == TRUE) {
					if (row == parent) {
						printf("%d", parent);
						/* found parent!!*/
						isParentFound = TRUE;
						return isParentFound;
					}
					else {
						printf("%d->", row);
						col = row;
						break;
					}
				}

			};
		};
	}
	 

	return isParentFound;
}