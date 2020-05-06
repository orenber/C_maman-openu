#include "data.h"

int main(){
    
	adjmat matrix;
	int input=0;
	char parent[] = " ", child[] = " ";

	matrix_equal(&matrix,FALSE);
	build_matrix(&matrix);
	
	while (input != EOF)
	{
		printf("\n\nPlease insert Parent :");
		scanf("%s", parent);
		printf("\n\nPlease insert Child :");
		input = scanf("%s", child);

		if ((strcmp(parent, "-1") == 0) && (strcmp(child, "-1") == 0))
		{
			break;
		}

			BOOL c = path(matrix, atoi(parent), atoi(child));

			printf(c ? "true" : "false");
		
	}
	getchar();
	return 0;
}

void build_matrix(adjmat mat) {
	
	int col,
		row,
		main_parent;

		
	char text_number[] = { " " },
		text2[] = { " " };
	
	printf("choose one main parent from the range: 0-%1d ", N-1);
	 
	  scanf("%s", text_number);
	  main_parent = atoi(text_number);
	  print_matrix(mat);

	for (col = 0; col < N; col++) {
        if (col == main_parent)
		{
			continue;
		}
		else {
			printf("\nfor the given child: %1d \n"
				"choose one parent from the list\n ", col);
		    scanf("%s", text2);
			/* convert char to int*/
			row  = atoi(text2);
			mat[row][col] = TRUE;
			
		}
		 print_matrix(mat);
	};
	
	return;

}

void print_matrix(adjmat mat) {

	/* calculate size of array */
	int row = N, col= N;
	
	/* print index colume */
	printf("\t");
	for (col = 0; col < N;col++)
	{
		printf("   %1d", col);

	}
	printf("\n\t ");
	/*print separetor line*/
	for (col = 0; col < N; col++)
	{
		printf("____");

	}
	printf("\n");
	for (row = 0; row < N; row++)
	{
		printf("\t[");
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
		/*print row index*/
		printf("] %1d\n",row);
	}

	return;

}

void matrix_equal(BOOL *mat, BOOL number) {
	/* calculate size of array */
	int numel = N * N;
	for (; numel >= 0; numel--) 
	{
		mat[numel] = number;
	}

	return ;
}

BOOL path(adjmat mat,int parent,int child) {
	
	BOOL isParentFound = FALSE;
	int row = 0,col = child;

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









