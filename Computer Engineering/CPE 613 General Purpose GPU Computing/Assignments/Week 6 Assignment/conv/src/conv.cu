#include <conv.h>
#include <helper_cuda.h>

#define FILTER_RADIUS 2
__constant__ float constantFilter[(2*FILTER_RADIUS+1)* (2*FILTER_RADIUS+1)];
#define TILE_WIDTH 4
#define IN_TILE_DIM 16
#define OUT_TILE_DIM ((IN_TILE_DIM) - 2 * (FILTER_RADIUS))

// Number 1 naive approach. Load image and filter from main memory.
__global__ void convolution_2D_basic_kernel(float* N, float *F, float *P, int r, int width, int height){
  int outCol = blockIdx.x * blockDim.x + threadIdx.x;
  int outRow = blockIdx.y * blockDim.y + threadIdx.y;
  float Pvalue = 0.0f;
  if(outCol < width && outRow < height){
    for(int fRow = 0; fRow < 2*r+1; fRow++){
      for(int fCol = 0; fCol < 2*r+1; fCol++){
        int inRow = outRow - r + fRow;
        int inCol = outCol - r + fCol;
        if(inRow >= 0 && inRow < height && inCol >=0 && inCol < width){
          Pvalue += F[fRow * r + fCol] * N[inRow * width + inCol];
        }
      }
    }
    P[outRow * width + outCol] = Pvalue;
  }
}

// Number 2 filter in shared memory approach.
__global__ void convolution_2D_filter_shared_mem_kernel(float* N, float *F, float *P, int r, int width, int height){
  int outCol = blockIdx.x * blockDim.x + threadIdx.x;
  int outRow = blockIdx.y * blockDim.y + threadIdx.y;

  __shared__ float filter[FILTER_RADIUS * FILTER_RADIUS];
  float Pvalue = 0.0f;
  if(outCol < width && outRow < height){
    for(int row = 0; row < 2 * r + 1; row++){
      for(int col = 0; col < 2 * r + 1; col++){
        filter[row * r + col] = F[row * r + col];
      }
    }
    __syncthreads();

    for(int fRow = 0; fRow < 2 * r+1; fRow++){
      for(int fCol = 0; fCol < 2 * r+1; fCol++){
        int inRow = outRow - r + fRow;
        int inCol = outCol - r + fCol;
        if(inRow >= 0 && inRow < height && inCol >=0 && inCol < width){
          Pvalue += filter[fRow * r + fCol] * N[inRow * width + inCol];
        }
      }
    }
    P[outRow * width + outCol] = Pvalue;
  }
}

// Number 3 filter in constant memory.
__global__ void convolution_2D_const_mem_kernel(float* N, float *P, int r, int width, int height){
  int outCol = blockIdx.x * blockDim.x + threadIdx.x;
  int outRow = blockIdx.y * blockDim.y + threadIdx.y;
  float Pvalue = 0.0f;
  if(outCol < width && outRow < height){
    for(int fRow = 0; fRow < 2*r+1; fRow++){
      for(int fCol = 0; fCol < 2*r+1; fCol++){
        int inRow = outRow - r + fRow;
        int inCol = outCol - r + fCol;
        if(inRow >= 0 && inRow < height && inCol >=0 && inCol < width){
          Pvalue += constantFilter[fRow * r + fCol] * N[inRow * width + inCol];
        }
      }
    }
    P[outRow * width + outCol] = Pvalue;
  }
}

// Number 4 - tile input to shared memory, and load filter into shared memory. 
__global__ void convolution_2D_input_shared_filter_const_kernel(float* N, float *F, float *P, int r, int width, int height){

  int outCol = blockIdx.x * OUT_TILE_DIM + threadIdx.x - FILTER_RADIUS;
  int outRow = blockIdx.y * OUT_TILE_DIM + threadIdx.y - FILTER_RADIUS;
  __shared__ float N_s[IN_TILE_DIM][IN_TILE_DIM];
  __shared__ float filter[FILTER_RADIUS * FILTER_RADIUS];
  
  if(outCol < width && outCol >= 0 && outRow >= 0 && outRow < height){
    N_s[threadIdx.y][threadIdx.x] = N[outRow * width + outCol];
  }else{
    N_s[threadIdx.y][threadIdx.x] = 0.0;
  }
  __syncthreads();
  
  if(outCol < width && outCol >= 0 && outRow >= 0 && outRow < height){
    // Pull the filter into shared memory
    for(int row = 0; row < 2*FILTER_RADIUS + 1; row++){
      for(int col = 0; col < 2*FILTER_RADIUS + 1; col++){
        filter[row * FILTER_RADIUS * FILTER_RADIUS + col] = F[row * FILTER_RADIUS * FILTER_RADIUS + col];
      }
    }
    __syncthreads();

    int tCol = threadIdx.x - FILTER_RADIUS;
    int tRow = threadIdx.y - FILTER_RADIUS;
    float Pvalue = 0.0f;

    if(tCol >= 0 && tCol < OUT_TILE_DIM && tRow >= 0 && tRow < OUT_TILE_DIM){
      for(int row = 0; row < 2 * FILTER_RADIUS + 1; row++){
        for(int col = 0; col < 2 * FILTER_RADIUS + 1; col++){
          if(outCol < width && outRow < height)
            Pvalue += filter[row * FILTER_RADIUS + col] * N_s[tRow + row][tCol + col];
        }
      }
      P[outRow * width + outCol] = Pvalue;
    }
  }
}

// Number 5 - Tile input to shared memory, load filter to constant memory.
__global__ void convolution_tiled_2D_const_mem_kernel(float *N, float *P, int r, int width, int height)
{
  int outCol = blockIdx.x * OUT_TILE_DIM + threadIdx.x - FILTER_RADIUS;
  int outRow = blockIdx.y * OUT_TILE_DIM + threadIdx.y - FILTER_RADIUS;
  __shared__ float N_s[IN_TILE_DIM][IN_TILE_DIM];
  
  if(outCol < width && outCol >= 0 && outRow >= 0 && outRow < height){
    N_s[threadIdx.y][threadIdx.x] = N[outRow * width + outCol];
  }else{
    N_s[threadIdx.y][threadIdx.x] = 0.0;
  }
  __syncthreads();


  if(outCol >= 0 && outCol < width && outRow >= 0 && outRow < height){
    int tileCol = threadIdx.x - FILTER_RADIUS;
    int tileRow = threadIdx.y - FILTER_RADIUS;
    float Pvalue = 0.0f;
    if(tileCol >= 0 && tileCol < OUT_TILE_DIM && tileRow >= 0 && tileRow < OUT_TILE_DIM){
      for(int fRow = 0; fRow < 2 * FILTER_RADIUS + 1; fRow++){
        for(int fCol = 0; fCol < 2 * FILTER_RADIUS + 1; fCol++){
            Pvalue += constantFilter[fRow * r + fCol] * N_s[tileRow + fRow][tileCol + fCol];
        }
      }
      P[outRow * width + outCol] = Pvalue;
    }
  }
}

// Number 6 - Tile input to sharead memory where in/out tile sizes are identical and load the filter into constant memory. 
__global__ void convolution_cached_tiled_2D_const_mem_kernel(float *N, float *P, int r, int width, int height)
{
  int col = blockIdx.x * OUT_TILE_DIM + threadIdx.x - FILTER_RADIUS;
  int row = blockIdx.y * OUT_TILE_DIM + threadIdx.y - FILTER_RADIUS;
  
  __shared__ float N_s[IN_TILE_DIM][IN_TILE_DIM];
  if(row < height & col < width){
    N_s[threadIdx.y][threadIdx.x] = N[row * width + col];
  } else {
    N_s[threadIdx.y][threadIdx.x] = 0.0;
  }
  __syncthreads();

  if(col < width && row < height){
    float Pvalue = 0.0f;
    for(int fRow = 0; fRow < 2 * FILTER_RADIUS + 1; fRow++){
      for(int fCol = 0; fCol < 2 * FILTER_RADIUS + 1; fCol++){
        if(threadIdx.x - FILTER_RADIUS + fCol >= 0 &&
           threadIdx.x - FILTER_RADIUS + fCol < TILE_WIDTH && 
           threadIdx.y - FILTER_RADIUS + fRow >= 0 &&
           threadIdx.y - FILTER_RADIUS + fRow < TILE_WIDTH){
            Pvalue += constantFilter[fRow * r + fCol] * N_s[threadIdx.y + fRow][threadIdx.x + fCol];
        }
        else{
          if(row - FILTER_RADIUS + fRow >= 0 &&
             row - FILTER_RADIUS + fRow < height &&
             col - FILTER_RADIUS + fCol >= 0 &&
             col - FILTER_RADIUS + fCol < width){
              Pvalue += constantFilter[fRow * r + fCol] * N[(row - FILTER_RADIUS + fRow) * width + col - FILTER_RADIUS + fCol];
          }
        }
      }
      P[row * width + col] = Pvalue;
    }
  }
}

void Number1(float* N, float *F, float *P, int r, int width, int height)
{
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_2D_basic_kernel<<<grid, blocks>>> (N, F, P, r, width, height);
}

void Number2(float* N, float *F, float *P, int r, int width, int height){
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_2D_filter_shared_mem_kernel<<<grid, blocks>>> (N, F, P, r, width, height);
}

void Number3(float* N, float *P, int r, int width, int height){
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_2D_const_mem_kernel<<<grid, blocks>>> (N, P, r, width, height);
}

void Number4(float* N, float *F, float *P, int r, int width, int height){
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_2D_input_shared_filter_const_kernel<<<grid, blocks>>> (N, F, P, r, width, height);
}

void Number5(float *N, float *P, int r, int width, int height){
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_tiled_2D_const_mem_kernel<<<grid, blocks>>> (N, P, r, width, height);
}

void Number6(float *N, float *P, int r, int width, int height){
  dim3 blocks(16, 16);
  dim3 grid((width + blocks.x - 1)/blocks.x, (height + blocks.y - 1)/blocks.y);
  convolution_cached_tiled_2D_const_mem_kernel<<<grid, blocks>>> (N, P, r, width, height);
}