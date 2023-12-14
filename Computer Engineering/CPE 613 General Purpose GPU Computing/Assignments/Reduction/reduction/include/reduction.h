#ifndef __reduction_h__
#define __reduction_h__

#ifdef __cplusplus
extern "C" {
#endif
  void sequential(int* array, int* sum, int elements);
  void atomicf(int* array, int* sum, int elements);
  void segmented(int* array, int* sum, int elements);
  void coalescing(int* array, int* sum, int elements);
  void sharedmem(int* array, int* sum, int elements);
  void coarsened(int* array, int* sum, int elements);
  void CUBCuda(int* array, int* sum, int elements);
  void ThrustCUDA(int* array, int* sum, int elements);

#ifdef __cplusplus
}
#endif

#endif
