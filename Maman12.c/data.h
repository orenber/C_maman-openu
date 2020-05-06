
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 11
typedef enum
{
	FALSE = 0, TRUE = 1

}BOOL;

typedef BOOL adjmat[N][N];

BOOL path(adjmat mat, int parent, int child);
void matrix_equal(BOOL *mat, BOOL number);
void print_matrix(adjmat mat);
void build_matrix(adjmat mat);
 