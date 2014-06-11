#ifndef MAT_OUTER
#define MAT_OUTER

#include <OpenBLAS/cblas.h>
#include "mat.c"

// Outer product algorithm for multiplying matrices
void mat_outer(float* A, float* B, int m, int p, int n, float* C)
{
  float* x = (float*) calloc(m,sizeof(float));
  float* y = (float*) calloc(n,sizeof(float));
  
  // If memory allocation fails then exit with error
  if(x == NULL || y == NULL) { exit(1); }
  
  int k;

  // Loop through elements
  for(k=0; k < p; k++)
  {
    // Get column k from A and put into x
    get_col(A,m,p,k,x);
    
    // Get row k from B and put into y
    get_row(B,n,k,y);
    
    // Calculate outer product - level 2 operation y <- x*y^T + A
    cblas_sger(CblasRowMajor,m,n,1.0,x,1,y,1,C,n);
  }

  // Free intermediate values
  free(x);
  free(y);
}

#endif