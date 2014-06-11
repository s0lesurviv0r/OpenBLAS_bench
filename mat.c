#ifndef MATC
#define MATC

// Get row from matrix A which has n columns and put in x
void get_row(float* A, int n, int row, float* x)
{
  int j;
  for(j=0; j < n; j++)
  {
    x[j] = A[row*n+j];
  }
}

// Get col from matrix A which has m rows, n columns and put in x
void get_col(float* A, int m, int n, int col, float* x)
{
  int i;
  for(i=0; i < m; i++)
  {
    x[i] = A[i*n+col];
  }
}

// Place column c into the m-by-n matrix A specified by col
void set_col(float* A, int m, int n, int col, float* c)
{
  int i;
  for(i=0; i < m; i++)
  {
    A[i*n+col] = c[i];
  }
}

#endif