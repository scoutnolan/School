#include <matmul.h>
#include <helper_cuda.h>
#define TILE_WIDTH 16
#define COARSE_FACTOR 4

__global__ void MatrixMulKernel(float* A, float* B, float* C, int Size)
{
  int Row = blockIdx.y * blockDim.y + threadIdx.y;
  int Col = blockIdx.x * blockDim.x + threadIdx.x;
  if((Row < Size) && (Col < Size)){
    float Cvalue = 0;
    for(int k = 0; k < Size; ++k){
      Cvalue += A[Row * Size + k] * B[k * Size + Col];
    }
    C[Row * Size + Col] = Cvalue;
  }
}

__global__ void MatrixMulKernelTile(float * A, float * B, float * C, int Size) { 
  __shared__ float Ads[TILE_WIDTH][TILE_WIDTH];
  __shared__ float Bds[TILE_WIDTH][TILE_WIDTH];
  int bx = blockIdx.x; int by = blockIdx.y;
  int tx = threadIdx.x; int ty = threadIdx.y;
  int row = by * TILE_WIDTH + ty;
  int col = bx * TILE_WIDTH + tx;
  float CValue = 0.0f;
  for(unsigned int ph = 0; ph < ceil(Size/(float)TILE_WIDTH); ++ph){
      if((row < Size) && (ph * TILE_WIDTH + tx) < Size)
        Ads[ty][tx] = A[row * Size + ph * TILE_WIDTH + tx];
      if((ph * TILE_WIDTH + ty) < Size && col < Size)
        Bds[ty][tx] = B[(ph * TILE_WIDTH + ty) * Size + col];
      __syncthreads();
      for(unsigned int i = 0; i < TILE_WIDTH; ++i)
          CValue += Ads[ty][i] * Bds[i][tx];
      __syncthreads();
  }
  if(row < Size && col < Size)
    C[row * Size + col] = CValue;
}

__global__ void MatrixMulKernelCoarse(float * A, float * B, float * C, int Size) { 
  __shared__ float Ads[TILE_WIDTH][TILE_WIDTH];
  __shared__ float Bds[TILE_WIDTH][TILE_WIDTH];
  unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;
  unsigned int colStart = blockIdx.x * blockDim.x + threadIdx.x;
  float sum[COARSE_FACTOR];
  for(unsigned int c = 0; c < COARSE_FACTOR; ++c){
    sum[c] = 0.0f;
  }    

  for(unsigned int tile = 0; tile < Size / TILE_WIDTH; ++tile)
  {
    if((row < Size) && (tile * TILE_WIDTH + threadIdx.x) < Size)
      Ads[threadIdx.y][threadIdx.x] = A[row * Size + tile * TILE_WIDTH + threadIdx.x];
    for(unsigned int c = 0; c < COARSE_FACTOR; ++c){
      unsigned int col = colStart + c * TILE_WIDTH;
      if((tile * TILE_WIDTH + threadIdx.y) < Size && col < Size)
        Bds[threadIdx.y][threadIdx.x] = B[(tile*TILE_WIDTH + threadIdx.y)*Size + col];
      __syncthreads();
      for(unsigned int i = 0; i < TILE_WIDTH; ++i){
        sum[c] += Ads[threadIdx.y][i] * Bds[i][threadIdx.x];
      }
      __syncthreads();
    }
    for(unsigned int c = 0; c < COARSE_FACTOR; ++c){
      unsigned int col = colStart + c*TILE_WIDTH;
      if(row < Size && col < Size)
        C[row*Size + col] = sum[c];
    }
  }
}

void MatrixMul(float* A, float* B, float* C, int Size)
{
  int blockSize;
  int minGridSize;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, MatrixMulKernel, 0, 0));

  dim3 numThreadsPerBlock(16, 16);
  dim3 numBlocks((Size + numThreadsPerBlock.x - 1)/numThreadsPerBlock.x,
                  (Size + numThreadsPerBlock.y - 1)/numThreadsPerBlock.y);

  MatrixMulKernel<<<numThreadsPerBlock, numBlocks>>> (A, B, C, Size); 
}

void MatrixMulTile(float* A, float* B, float* C, int Size){
  int blockSize;
  int minGridSize;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, MatrixMulKernelTile, 0, 0));
  int numThread=16; //number of threads per Block axis
  int numBlocks=Size/numThread;
  if(Size%numThread)
      numBlocks++;
  dim3 dimGrid(numBlocks,numBlocks);
  dim3 dimBlock(numThread,numThread);
  MatrixMulKernelTile<<<dimGrid,dimBlock>>> (A, B, C, Size); 
}

void MatrixMulCoarse(float* A, float* B, float* C, int Size)
{
  int blockSize;
  int minGridSize;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&minGridSize, &blockSize, MatrixMulKernelCoarse, 0, 0));  
  int numThread=16; //number of threads per Block axis
  int numBlocks=Size/numThread;
  if(Size%numThread)
      numBlocks++;
  dim3 dimGrid(numBlocks,numBlocks);
  dim3 dimBlock(numThread,numThread);
  MatrixMulKernelCoarse<<<dimGrid,dimBlock>>> (A, B, C, Size); 
}

