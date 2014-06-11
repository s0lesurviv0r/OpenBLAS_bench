#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "randf.c"
#include "mat_loop_col.c"
#include "mat_loop_row.c"
#include "mat_saxpy.c"
#include "mat_dot.c"
#include "mat_vec.c"
#include "mat_outer.c"
#include "mat_cblas.c"

void bench(void (*AlgoPtr)(), char* label, float* A, float* B, int n)
{   
  // Results of matrix multiplication
  float* C = (float*) calloc(n*n,sizeof(float));
    
  clock_t start_clock, ticks;
  
  // Mark start time
  start_clock = clock();
  
  // Multiply matrices
  AlgoPtr(A,B,n,n,n,C);
  
  // Mark end time
  ticks = clock() - start_clock;
  
  // Free memory of the resulting matrix
  free(C);
        
  // Calculate algorithm runtime
  float runtime = ((float)ticks)/CLOCKS_PER_SEC;
  
  // Calculate flops
  float flops = fabsf((float)(2*n*n*n)/runtime);
  
  // Output results
  printf("%s,%i,%E\n",label,n,flops);
}

int main()
{ 
  // Print CSV headers
  printf("Algorithm,n,FLOPs\n");
  
  // Variables for matrix sizes
  int n;
  
  int sizes[] = {100,250,500,1000,2500,5000};
  int sizes_len = 6;
  
  int i;
  
  // Pointers to random matrices for multiplication
  float* A;
  float* B;
  
  for(i=0; i < sizes_len; i++)
  {
    n = sizes[i];

    // Allocate memory for matrices A and B
    A = (float*) calloc(n*n,sizeof(float));
    B = (float*) calloc(n*n,sizeof(float));

    // If memory allocation fails then exit with error
    if(A == NULL || B == NULL) { exit(1); }

    // Generate random matrices for multiplication
    rand_matrix(n,n,A);
    rand_matrix(n,n,B);

    // Benchmark each algorithm
    bench(mat_loop_col,"mat_loop_col",A,B,n);
    bench(mat_loop_row,"mat_loop_row",A,B,n);
    bench(mat_dot,"mat_dot",A,B,n);
    bench(mat_saxpy,"mat_saxpy",A,B,n);
    bench(mat_vec,"mat_vec",A,B,n);
    bench(mat_outer,"mat_outer",A,B,n);
    bench(mat_cblas,"mat_cblas",A,B,n);

    // Free memory of the random matrices
    free(A);
    free(B);
  }
  
  return 0;
}
