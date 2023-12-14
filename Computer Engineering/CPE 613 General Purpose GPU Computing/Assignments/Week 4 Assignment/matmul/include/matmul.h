#ifndef __matmul_h__
#define __matmul_h__

#ifdef __cplusplus
extern "C" {
#endif
  void MatrixMul(
    float* A, 
    float* B, 
    float* C, 
    int Size
  );

  void MatrixMulTile(
    float* A, 
    float* B, 
    float* C, 
    int Size
  );

  void MatrixMulCoarse(
    float* A,
    float* B, 
    float* C, 
    int Size
  );

#ifdef __cplusplus
}
#endif

#endif
