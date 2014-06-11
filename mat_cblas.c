#ifndef MAT_CBLAS
#define MAT_CBLAS

#include <OpenBLAS/cblas.h>
#include "mat.c"

// cblas for multiplying matrices
void mat_cblas(float* A, float* B, int m, int p, int n, float* C)
{
  cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
          m, n, p, 1.0, A, p, B, n, 0.0, C, n);
}

#endif