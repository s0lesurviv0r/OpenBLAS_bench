#ifndef RAND_MATRIX
#define RAND_MATRIX

#include <math.h>

/**
 * Return a random real floating point number
 * @ref http://stackoverflow.com/a/17452867/892607
 */
float randf()
{
  float r;
    
  do
  {
    int s = rand() % 2;  // note x % 1 = 0
    int e = (rand() % 255);
    int f = rand() % (1 << 23);

    int tmp = (s << 31) | (e << 23) | f;

    r = (float)*((float*)(&tmp));
  }
  while(!isfinite(r));
    
  return r;
}

// Generate a random matrix A of dimensions m-by-n
void rand_matrix(int m, int n, float* A)
{ 
  int i,j;
  // Loop through rows
  for(i=0; i < m; i++)
  {
    // Loop through columns
    for(j=0; j < n; j++)
    {
      // Place random float as element
      A[i*n+j] = randf();
    }
  }
}

#endif