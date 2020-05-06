
#include <stdio.h>
#include <string.h>


#define N 1
typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef BOOL adjmat[N][N];

/* <summary>
matrix_equal - assign the same value (BOOL)  for etch element in the matrix
</summary>
*/
void matrix_equal(BOOL *mat, BOOL number);

/* <summary>
print_matrix -print matrix in any size
</summary>
*/
void print_matrix(adjmat mat);

/* <summary>
build_matrix - the function is user intarface to build matrix.
the user ask for every coulum(child) the proprite parent (row)
and asigne True in the matrix(row,col)
</summary>
*/
void build_matrix(adjmat mat);

/* <summary>
path - check if ther is path between the child to the parent,
in the case ther is path or ther is't the function return TRUE or FALSE,
</summary>
*/
BOOL path(adjmat mat, int parent, int child);