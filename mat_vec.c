#ifndef MAT_VEC
#define MAT_VEC

#include <OpenBLAS/cblas.h>
#include "mat.c"

// Matrix-Vector algorithm for multiplying matrices
void mat_vec(float* A, float* B, int m, int p, int n, float* C)
{
  float* x = (float*) calloc(p,sizeof(float));
  float* y = (float*) calloc(m,sizeof(float));
  
  // If memory allocation fails then exit with error
  if(x == NULL || y == NULL) { exit(1); }
  
  int j;
  
  // Loop through columns of B
  for(j=0; j < n; j++)
  {
    // Get column j of B and load into x
    get_col(B,p,n,j,x);
      
    // Get column j of C and load into y
    get_col(C,m,n,j,y);
      
    // Saxpy level 2 operation y <- alpha*A*x + y
    cblas_sgemv(CblasRowMajor,CblasNoTrans,m,p,1.0,A,p,x,1,1.0,y,1);
      
    // Set column j of C to y
    set_col(C,m,n,j,y);
  }

  // Free intermediate values
  free(x);
  free(y);
}

#endif