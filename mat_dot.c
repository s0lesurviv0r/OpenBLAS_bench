#ifndef MAT_DOT
#define MAT_DOT

#include <OpenBLAS/cblas.h>
#include "mat.c"

// Dot product algorithm for multiplying matrices
void mat_dot(float* A, float* B, int m, int p, int n, float* C)
{
  float* x = (float*) calloc(p,sizeof(float));
  float* y = (float*) calloc(p,sizeof(float));
  
  // If memory allocation fails then exit with error
  if(x == NULL || y == NULL) { exit(1); }
  
  int i,j;

  // Loop through columns
  for(j=0; j < n; j++)
  {
    // Loop through rows
    for(i=0; i < m; i++)
    {
      // Get row i from A and put into x
      get_row(A,p,i,x);
      get_col(B,p,n,j,y);
      
      // Level 1 operation C <- x*y
      C[i*n+j] = cblas_sdot(p,x,1,y,1);
    }
  }

  // Free intermediate values
  free(x);
  free(y);
}

#endif