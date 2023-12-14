/*
    Nolan Anderson
    CPE 613 Week 4 Assignment 1 and 3
    This program compares the implementations of a naive, tiled, BLAS,
    and nvdias cuBLAS approach to matrix multiplication. It loops through a
    range of matrix values. 

    To run / compile: 
    module load cuda && module load blas
    make run
*/
#include <matmul.h>
#include <Timer.hpp>
#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <cublas_v2.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <typeinfo>
#include <iostream>
#define TILE_WIDTH 16
using namespace std; 

extern "C" void sgemm_(
    unsigned char   *   transA, // specifies the form of op(A)
    unsigned char   *   transB, // specifies the form of op(B)
    int             *   m,      // num rows
    int             *   n,      // num columns
    int             *   k,      // num col A, num row B
    float           *   alpha,  // specifies the scalar alpha 
    float           *   a,      // array of dimension (LDA, ka). must contain matrix A
    int             *   lda,    // specifies the first dimension of A
    float           *   b,      // array of dimension (LDB, kb). must contain matrix B
    int             *   ldb,    // specifies the first dimension of A
    float           *   beta,   // specifes the scalar beta
    float           *   c,      // array of dimension (LDC, n) must contain the matrix C
    int             *   ldc     // specified the first dimension of C
);

cublasStatus_t cublasSgemm(
  cublasHandle_t      handle, // cublas handle variable
  cublasOperation_t   transa, // specifies the form of A 
  cublasOperation_t   transb, // specifies the form of B                 
  int                 m,      // Rows of matrix A[i] and C[i]
  int                 n,      // Columns of matrix B[i] and C[i]
  int                 k,      // Columns of A[i] and rows of B[i]
  const float         *alpha, // Scalar used for multiplication
  const float         *A,     // Array of points to <type> array 
  int                 lda,    // leading deminsion of two-dim array (A[i]) 
  const float         *B,     // Array of pointers to <type> array 
  int                 ldb,    // leading dim of two-dim array (B[i])
  const float         *beta,  // Scalar used for multiplication
  float               *C,     // Array of pointers to <type> array
  int                 ldc     // leading dimension of two-dim array (C[i])
);

double relative_error_l2 (int n, float * c_reference, float * c_computed);

int main (int argc, char ** argv) {
  cublasStatus_t stat;
  cublasHandle_t handle;
  cublasCreate(&handle);

  ofstream outFile;
  outFile.open("/home/uahclsc0003/source/week4/MatrixMultiply/results.csv");
  outFile << "Matrix Size,ET Naive,ET Tile,ET Coarse,ET cuBLAS,GFlops Naive,GFlops tile,GFlops Coarse,GFlops cuBLAS,BW Naive,BW Tile,BW Coarse,BW cuBLAS\n";
  printf("=========================================================================================================================\n");
  int MatSize[8] = {8, 16, 32, 64, 128, 256, 512, 1024}; 
  for(int i = 0; i < 7; ++i)  // Loop through matrices. Each time we will create new threads
  {    
    // Initialize variables
    int dimSize = MatSize[i];  // Grab dimension size
    int matSize = dimSize*dimSize;  // Actual matrix size
    size_t MatrixBytes = matSize * sizeof(float);
    Timer MatMulTimer, MatMulTimerTile, MatMulTimercuBLAS, MatMulTimerTileC;
    float alpha = 1.0f;
    float beta = 0.0f;
    unsigned char trans = 'n';

    // Create matrices 
    float *DeviceA = nullptr; float  *DeviceB = nullptr; float  *DeviceC = nullptr; float  *DeviceCT = nullptr; float *DeviceCB = nullptr; float *DeviceCTC = nullptr;
    float *HostA, *HostB, *CReference, *CComputed, *CComputedTile, *CComputedcuBlas, *CComputedTileC;
    HostA = (float*)malloc(MatrixBytes);            // First matrix (A) on the host
    HostB = (float*)malloc(MatrixBytes);            // Second matrix (B) on the host
    CReference = (float*)malloc(MatrixBytes);       // Blas reference
    CComputed = (float*)malloc(MatrixBytes);        // Naive approach
    CComputedTile = (float*)malloc(MatrixBytes);    // Tile approach
    CComputedTileC = (float*)malloc(MatrixBytes);   // Tile approach, coarse
    CComputedcuBlas = (float*)malloc(MatrixBytes);  // nvdia cublas 

    // Populate the arrays with random values 0 - 10
    for(int r = 0; r < dimSize; r++)
      for(int c = 0; c < dimSize; c++)
      {
        HostA[r*dimSize + c] = (float)rand()/RAND_MAX;
        HostB[r*dimSize + c] = (float)rand()/RAND_MAX;
      }

    // Allocate and copy data over
    checkCudaErrors(cudaMalloc((void**)&DeviceA, MatrixBytes));
    checkCudaErrors(cudaMalloc((void**)&DeviceB, MatrixBytes));
    checkCudaErrors(cudaMalloc((void**)&DeviceC, MatrixBytes)); 
    checkCudaErrors(cudaMalloc((void**)&DeviceCT, MatrixBytes));
    checkCudaErrors(cudaMalloc((void**)&DeviceCB, MatrixBytes));
    checkCudaErrors(cudaMalloc((void**)&DeviceCTC, MatrixBytes));      
    checkCudaErrors(cudaMemcpy(DeviceA, HostA, MatrixBytes, cudaMemcpyHostToDevice));
    checkCudaErrors(cudaMemcpy(DeviceB, HostB, MatrixBytes, cudaMemcpyHostToDevice));
    
    // BLAS
    sgemm_(&trans, &trans, &dimSize, &dimSize, &dimSize, &alpha, HostB, &dimSize, HostA, &dimSize, &beta, CReference, &dimSize);

    // cuBLAS
    MatMulTimercuBLAS.start();
    cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, dimSize, dimSize, dimSize, &alpha, DeviceB, dimSize, DeviceA, dimSize, &beta, DeviceCB, dimSize);    
    MatMulTimercuBLAS.stop();

    // NAIVE
    MatMulTimer.start();
    MatrixMul(DeviceA, DeviceB, DeviceC, dimSize);
    MatMulTimer.stop();
    
    // TILE
    MatMulTimerTile.start();
    MatrixMulTile(DeviceA, DeviceB, DeviceCT, dimSize);
    MatMulTimerTile.stop(); 

    // TILE COARSE
    MatMulTimerTileC.start();
    MatrixMulCoarse(DeviceA, DeviceB, DeviceCTC, dimSize);
    MatMulTimerTileC.stop(); 

    // Copy down tile, naive, coarse tile, and cuBLAS down from the device
    checkCudaErrors(cudaMemcpy(CComputed, DeviceC, MatrixBytes, cudaMemcpyDeviceToHost));
    checkCudaErrors(cudaMemcpy(CComputedTile, DeviceCT, MatrixBytes, cudaMemcpyDeviceToHost)); 
    checkCudaErrors(cudaMemcpy(CComputedTileC, DeviceCTC, MatrixBytes, cudaMemcpyDeviceToHost)); 
    checkCudaErrors(cudaMemcpy(CComputedcuBlas, DeviceCB, MatrixBytes, cudaMemcpyDeviceToHost)); 

    double numWrite = matSize;
    double numberOfFlops = dimSize * dimSize * dimSize * 2;
    double numRead = matSize*matSize*2;

    // Plug and chug
    // Naive
    double relerr = relative_error_l2(matSize, CReference, CComputed);
    double Time_MS = MatMulTimer.elapsedTime_ms();
    double flopRate = numberOfFlops / (Time_MS / 1.0e3);
    double BandWidth {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS / 1.0e3)};
    bool boolNaive = relerr < 1.0e-7;

    // Tiled
    double relerrTile = relative_error_l2(matSize, CReference, CComputedTile);
    double Time_MS_Tile = MatMulTimerTile.elapsedTime_ms(); 
    double flopRateTile = numberOfFlops / (Time_MS_Tile / 1.0e3); 
    double BandWidth_Tile {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_Tile / 1.0e3)};
    bool boolTiled = relerrTile < 1.0e-7;

    // Coarse tiled
    double relerrTileC = relative_error_l2(matSize, CReference, CComputedTileC);
    double Time_MS_TileC = MatMulTimerTileC.elapsedTime_ms(); 
    double flopRateTileC = numberOfFlops / (Time_MS_TileC / 1.0e3); 
    double BandWidth_TileC {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_TileC / 1.0e3)};
    bool boolCoarse = relerrTileC < 1.0e-7;
    
    // cuBLAS
    double relerrcuBLAS = relative_error_l2(matSize, CReference, CComputedcuBlas);
    double Time_MS_cuBLAS = MatMulTimercuBLAS.elapsedTime_ms();
    double flopRatecuBLAS = numberOfFlops / (Time_MS_cuBLAS / 1.0e3);
    double BandWidth_cuBLAS {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_cuBLAS / 1.0e3)};
    bool boolcuBLAS = relerrcuBLAS < 1.0e-7;

    // Output calculations / findings
    printf("Matrix size %d\n", matSize);
    printf("Approach  Execution Time     Computational Rate              Effective Bandwidth           Relative Error           P/F   \n");
    printf("Naive     %f seconds | %20.16e Gflops | %20.16e Gbps | %20.16e | %s    \n", Time_MS / 1.0e3, flopRate / 1e9, BandWidth / 1e9, relerr, boolNaive ? "PASSED" : "FAILED");
    printf("Tile      %f seconds | %20.16e Gflops | %20.16e Gbps | %20.16e | %s    \n", Time_MS_Tile / 1.0e3, flopRateTile / 1e9, BandWidth_Tile / 1e9, relerrTile, boolTiled ? "PASSED" : "FAILED");
    printf("Coarse    %f seconds | %20.16e Gflops | %20.16e Gbps | %20.16e | %s    \n", Time_MS_TileC / 1.0e3, flopRateTileC / 1e9, BandWidth_TileC / 1e9, relerrTileC, boolCoarse ? "PASSED" : "FAILED");
    printf("cuBLAS    %f seconds | %20.16e Gflops | %20.16e Gbps | %20.16e | %s    \n", Time_MS_cuBLAS / 1.0e3, flopRatecuBLAS / 1e9, BandWidth_cuBLAS / 1e9, relerrcuBLAS, boolcuBLAS ? "PASSED" : "FAILED");
    printf("=========================================================================================================================\n");

    // Write to csv file
    outFile << matSize << "," << Time_MS/1.0e3 << "," << Time_MS_Tile/1.0e3 << "," << Time_MS_TileC/1.0e3 << "," << Time_MS_cuBLAS/1.0e3 << "," << flopRate / 1e9 << "," << flopRateTile / 1e9 << "," << flopRateTileC / 1e9 << "," << flopRatecuBLAS / 1e9 << "," << BandWidth / 1e9 << "," << BandWidth_Tile / 1e9 << "," << BandWidth_TileC / 1e9 << "," << BandWidth_cuBLAS / 1e9 << "\n";
      
    // Free cuda memory
    checkCudaErrors(cudaFree(DeviceA));
    checkCudaErrors(cudaFree(DeviceB));
    checkCudaErrors(cudaFree(DeviceC));
    checkCudaErrors(cudaFree(DeviceCT));
    checkCudaErrors(cudaFree(DeviceCTC));
    checkCudaErrors(cudaFree(DeviceCB));
  }
  return 0;
  outFile.close();
}

double relative_error_l2 (int n, float  * c_reference,  float * c_computed) {
  double difference_norm_squared = 0.0;
  double reference_norm_squared = 0.0;
  for (int idx = 0; idx < n; ++idx){
    auto & reference_value = c_reference[idx]; double difference {c_reference[idx] - c_computed[idx]};
    difference_norm_squared += difference * difference;
    reference_norm_squared += reference_value * reference_value;
  }
  return sqrt (difference_norm_squared / reference_norm_squared);
}