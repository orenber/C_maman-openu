
#include <stdio.h>
#include <string.h>


#define N 5 /* dimention */
typedef enum /* boolen type*/
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef BOOL adjmat[N][N]; /* Adjacency boolean matrix type*/

/*<summary>
matrix equal - assign the same value (BOOL) for each element in the Adjacency matrix .
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN.
	BOOL number - boolean value to assige the matrix TRUE(1) or FALSE(0).
</input>
*/
void matrix_equal(adjmat mat, BOOL number);

/* <summary>
print_matrix -print Adjacency matrix in size NxN.
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN..
</input>
*/
void print_matrix(adjmat mat);

/* <summary>
build matrix - the function is user interface to build Adjacency matrix.
the user will be ask for every child leaf the appropriate parent
and assign boolean value (True) to the matrix.
</summary>
<input>
	adjmat mat - boolean Adjacency matrix in size NxN.
</input>
*/
void build_matrix(adjmat mat);

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
BOOL path(adjmat mat, int parent, int child);