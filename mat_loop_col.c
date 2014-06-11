#ifndef MAT_LOOP_COL
#define MAT_LOOP_COL

// Triple loop for multiplying matrices - column oriented
void mat_loop_col(float* A, float* B, int m, int p, int n, float* C)
{
  int i,j,k;

  // Loop through rows
  for(i=0; i < m; i++)
  {
    // Loop through columns
    for(j=0; j < n; j++)
    {
      // Loop through elements
      for(k=0; k < p; k++)
      {
        C[i*n+j] = C[i*n+j] + A[i*p+k]*B[k*n+j];
      }
    }
  }
}

#endif