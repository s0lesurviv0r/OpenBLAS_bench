#ifndef MAT_SAXPY
#define MAT_SAXPY

#include <OpenBLAS/cblas.h>
#include "mat.c"

// Saxpy operations for multiplying matrices
void mat_saxpy(float* A, float* B, int m, int p, int n, float* C)
{
  float* x = (float*) calloc(m,sizeof(float));
  float* y = (float*) calloc(m,sizeof(float));
  
  // If memory allocation fails then exit with error
  if(x == NULL || y == NULL) { exit(1); }
  
  int j,k;
  
  // Loop through columns of B
  for(j=0; j < n; j++)
  {
    // Loop through columns of A
    for(k=0; k < p; k++)
    {
      // Get column k of A and load into x
      get_col(A,m,p,k,x);
      
      // Get column j of C and load into y
      get_col(C,m,n,j,y);
      
      // Get alpha
      float alpha = B[k*n+j];
      
      // Saxpy level 1 operation y <- alpha*x + y
      cblas_saxpy(m,alpha,x,1,y,1);
      
      // Set column j of C to y
      set_col(C,m,n,j,y);
    }
  }

  // Free intermediate values
  free(x);
  free(y);
}

#endif