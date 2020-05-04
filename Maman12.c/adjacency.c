#include <stdio.h>
#include <string.h>


#define N 11
typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef int adjmat[N][N];

BOOL path(int mat[N][N], int parent, int child);
void matrix_equal(adjmat *mat,BOOL num);
void print_matrix(adjmat mat);
void build_matrix(adjmat *mat);

int main(){
    
	adjmat matrix,mat;
	matrix_equal(&matrix,FALSE);
	print_matrix(matrix);
	build_matrix(&matrix);
	print_matrix(matrix);

	BOOL c = path(mat, 5, 7);

	printf(c ? "true" : "false");
	getchar();

}

void build_matrix(int *mat[N][N]) {
	
	int col,
		row,
		main_parent;
		
	char text_number[1] = " ",text2[1] = " ";

	printf("choose one main parent from the range: 0-%1d ", N-1);
	 
	  scanf("%d", text_number);
	  main_parent = (int)text_number[0];
 

	for (col = 0; col < N; ++col) {
        if (col == main_parent)
		{
			continue;
		}
		else {
			printf("for the given child: %1d \n"
				"choose one parent from the list ", col);
		    scanf("%d", text2);
			row  = (int)text2[0];
			mat[row][col] = TRUE;
		}
		 print_matrix(mat);
	}
	return;


}

void print_matrix(adjmat mat) {
	/* calculate size of array */
	int row = N, col= N;
	printf("\n\n");

	for (row = 0; row < N; ++row)
	{
		printf("\t[");
		for (col = 0; col < N; ++col)
		{
			/*  asige zeros*/
			printf(" %2d", mat[row][col]);
			if (col < N-1)
			{
				printf(",");
			}
			else if (col == N - 1) {
				printf(" ");
			}

		}
		printf("] %1d\n",row);
	}

	return;

}

void matrix_equll(int *mat, BOOL number) {
	/* calculate size of array */
	int numel = N * N;
	for (; numel >= 0; --numel) 
	{
		mat[numel] = number;
	}

	return ;
}

void range(int start, int fainal,int step )
{

	return;
}

void diff_array() {
	
	return;
}

BOOL ismember(int arr[],int num) {

	return 0;
}

BOOL path(adjmat mat,int parent,int child) {
	
	BOOL isParentFound = FALSE;
	int row = 0;
	int col = child;

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
			if (mat[row][col] == 1) 
			{   
				
				printf("%d\n", row);

				if (row == parent) {
					// found papa!!
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
				// done searcing papa not found
				return isParentFound;
			};
		};

	};

	return isParentFound;


}









