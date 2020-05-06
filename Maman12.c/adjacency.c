/* ***********************************************************************
Assembly         :
Author           : Oren Berkovitch
ID:              : 043189281
Created          : 06-05-2020

Last Modified By : Oren Berkovitch
Last Modified On : 06-05-2020
***********************************************************************
<summary> 
this programe have two part :
1.the user assingn  value to bolean matrix in size N 
the user will ask who is the main parent and will match for etch child his parent
2. the user ask for parent and child input and call to the path function thet will search 
if ther is path between the child to the parent, 
in the case ther is path or ther is't the function return TRUE or FALSE,
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
    
	adjmat matrix; 
	int input=0,
        parent, child;
	char str_parent[2],
		 str_child[2];

    matrix_equal(&matrix,FALSE);
	build_matrix(matrix);
	printf("\n\n________________________\nSearch the path..\n"
		"print -1 -1 for Exit");
	while (input != EOF)
	{
		printf("\n\nPlease insert parent :");
		scanf("%d", &parent);
		/*convert int to string*/
		sprintf(str_parent, "%d", parent);
		printf("\nSelected parent : %s", str_parent);

		printf("\nPlease insert child :");
		input = scanf("%d", &child);
		/*convert int to string*/
		sprintf(str_child, "%d", child);
		printf("\nSelected child : %s", str_child);

		if ((parent == -1) && (child==-1))
		{
			break;
		}
		    
		BOOL result = path(matrix, parent, child);
		printf(result ? "true,"
			"ther is a path between the parent to the child" :
			"false, ther is no path ");
		
	}
	getchar();
	return 0;
}

/* <summary>
build_matrix - the function is user intarface to build matrix.
the user ask for every coulum(child) the proprite parent (row)
and asigne True in the matrix(row,col)  
</summary> 
*/
void build_matrix(adjmat mat) {
	
	int col, /*colum matrix index*/
		row, /*row matrix index*/
		main_parent; /* tree main parent*/
		
	printf("\nWelcome !!!\n\nPlease choose one main parent from the range [0-%1d] :", N-1);
	scanf("%d", &main_parent); 
	printf("\n");

	print_matrix(mat);

	for (col = 0; col < N; col++) {
        if (col == main_parent)
		{
			/* skeep on the main parent sinch he dosent have parent */
			continue;
		}
		else {
			printf("\nfor the given child: %1d \n"
				"Please choose one parent from the range [0-%1d] : ",col , N-1);
		    scanf("%d",&row);
			printf("\n");
			/*asige value*/
			mat[row][col] = TRUE;
			
		}
		 print_matrix(mat);
	};
	
	return;

}

/* <summary>
print_matrix -print matrix in any size 
</summary>
*/
void print_matrix(adjmat mat) {

	/* calculate size of array */
	int row = N,/* row index*/
		col= N;/* col index*/
	
	printf("\t");
	for (col = 0; col < N;col++)
	{	/* print index colume */
		printf("%4d", col);

	}
	printf("\n\t ");
	
	for (col = 0; col < N; col++)
	{
		/*print separetor line*/
		printf("____");
	}
	printf("\n");
	for (row = 0; row < N; row++)
	{
		printf("%7d [",row);
		for (col = 0; col < N; col++)
		{
			/*  print matrix values*/
			printf(" %2d", mat[row][col]);
			if (col < N-1)
			{
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

/* <summary>
matrix_equal - assign the same value (BOOL)  for etch element in the matrix
</summary>
*/
void matrix_equal(BOOL *mat, BOOL number) {
	/* calculate size of array */
	int index = N * N; /* index matrix */
	for (; index >= 0; index--) 
	{
		mat[index] = number;
	} 

	return ;
}

/* <summary>
path - check if ther is path between the child to the parent, 
in the case ther is path or ther is't the function return TRUE or FALSE,
</summary>
*/
BOOL path(adjmat mat,int parent,int child) {
	
	BOOL isParentFound = FALSE; /* is ther is path betwen the child and the parent?*/
	int row = 0, /* row index*/
		col = child; /*colum index*/

	printf("%d\n", child);
	if((parent == child)&&(parent<N)){
		isParentFound = TRUE;
		return isParentFound;
	}

	for (col; col < N; ) 
	{
		for (row = 0; row <= N; ++row) 
		{	
		 // seek parent 
			if (mat[row][col] == TRUE) 
			{   	
				printf("%d\n", row);

				if (row == parent) {
					// found parent!!
					isParentFound = TRUE;
					return isParentFound;
				}
				else
				{
					col = row;
					break;
				}
 			}
			else if (row == N)
			{
				// done searcing parent not found
				return isParentFound;
			};
		};
	};

	return isParentFound;
}