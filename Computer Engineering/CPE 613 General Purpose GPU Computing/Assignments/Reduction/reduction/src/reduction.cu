#include <reduction.h>
#include <helper_cuda.h>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/complex.h>
#include <thrust/execution_policy.h>
#include <thrust/transform.h>
#include <cub/cub.cuh>

#define COARSE_FACTOR 2
#define BLOCK_DIM 1024

// 1. A sequential CUDA version where one CUDA thread loops over all entries.
__global__ void sequential_reduction_kernel(int* array, int* sum, int elements){
  float tempsum = 0.0f;
  if(threadIdx.x == 0){
      for(int i = 0; i < elements; i++)
          tempsum += array[i];
  }  
  *sum = tempsum;
}

// 2. A parallel CUDA version using atomics (slide 4 of Chapter 10's slides)
__global__ void atomic_reduction_kernel(int* array, int* sum, int elements){
  unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;
  if(i < elements)
      atomicAdd(sum, array[i]);
}

// 3. A segmented reduction (slide 9 of Chapter 10)
__global__ void segmented_reduction_kernel(int* array, int* sum, int elements){
  unsigned int segment = 2*blockDim.x*blockIdx.x;
  unsigned int i = segment + 2*threadIdx.x;
  for(unsigned int stride = 1; stride <= blockDim.x; stride *=2){
      if(threadIdx.x % stride == 0){
          array[i] += array[i + stride];
      }
      __syncthreads();
  }
  if(threadIdx.x == 0)
    atomicAdd(sum, array[i]);
}

// 4.  A segmented reduction with coalescing and minimal divergence (slide 13 of Chapter 10)
__global__ void coalescing_reduction_kernel(int* array, int* sum, int elements){
  unsigned int segment = 2*blockDim.x*blockIdx.x;
  unsigned int i = segment + threadIdx.x;
  for(unsigned int stride = blockDim.x; stride > 0; stride /=2){
      if(threadIdx.x < stride){
          array[i] += array[i + stride];
      }
      __syncthreads();
  }    
  if(threadIdx.x == 0){
    atomicAdd(sum, array[i]);
  }
}

// 5.  A shared memory segmented reduction (slide 16 of Chapter 10)
__global__ void sharedmem_reduction_kernel(int* array, int* sum, int elements){
  unsigned int segment = 2* blockDim.x * blockIdx.x;
  unsigned int i = segment + threadIdx.x;

  // Load data to shared memory
  __shared__ float array_s[BLOCK_DIM];
  array_s[threadIdx.x] = array[i] + array[i + BLOCK_DIM];
  __syncthreads();

  // Reduction tree in shared memory
  for(unsigned int stride = BLOCK_DIM / 2; stride > 0; stride /= 2)
  {
      if(threadIdx.x < stride){
          array_s[threadIdx.x] += array_s[threadIdx.x + stride];
      }
      __syncthreads();
  }
  if(threadIdx.x == 0)
    atomicAdd(sum, array_s[0]);
}

// 6. A coarsened shared memory segmented reduction (slide 17 of Chapter 10)
__global__ void coarsened_reduction_kernel(int* array, int* sum, int elements){
  unsigned int segment = COARSE_FACTOR * 2 * blockDim.x * blockIdx.x;
  unsigned int i = segment + threadIdx.x;

  // Load data into shared memory
  __shared__ float array_s[BLOCK_DIM];
  float threadSum = 0.0f;
  for(unsigned int c = 0; c < COARSE_FACTOR * 2; ++c){
      threadSum += array[i + c * BLOCK_DIM];
  }
  array_s[threadIdx.x] = threadSum;
  __syncthreads();

  // Reduction tree in shared memory
  for(unsigned int stride = BLOCK_DIM/2; stride > 0; stride /=2){
      if(threadIdx.x < stride){
          array_s[threadIdx.x] += array_s[threadIdx.x + stride];
      }
      __syncthreads();
  }
  if(threadIdx.x == 0)
    atomicAdd(sum, array_s[0]);
}

// 1 
void sequential(int* array, int* sum, int elements){
  int TB_SIZE = BLOCK_DIM;
  int GRID_SIZE = (elements/2 + TB_SIZE - 1) / TB_SIZE;
  sequential_reduction_kernel<<<GRID_SIZE, TB_SIZE>>> (array, sum, elements);
}

// 2
void atomicf(int* array, int* sum, int elements){
  int MIN; int BLOCK;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&MIN, &BLOCK, atomic_reduction_kernel, 0, 0));
  int GRID_SIZE = (elements + BLOCK - 1)/ BLOCK; 
  atomic_reduction_kernel<<<GRID_SIZE, BLOCK>>> (array, sum, elements);
}

// 3
void segmented(int* array, int* sum, int elements){
  int MIN; int BLOCK;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&MIN, &BLOCK, segmented_reduction_kernel, 0, 0));
  int GRID_SIZE = (elements/2 + BLOCK - 1)/ BLOCK; 
  segmented_reduction_kernel<<<GRID_SIZE, BLOCK>>> (array, sum, elements);
}

// 4
void coalescing(int* array, int* sum, int elements){
  int MIN; int BLOCK;
  checkCudaErrors(cudaOccupancyMaxPotentialBlockSize(&MIN, &BLOCK, coalescing_reduction_kernel, 0, 0));
  int GRID_SIZE = (elements/2 + BLOCK - 1)/ BLOCK; 
  coalescing_reduction_kernel<<<GRID_SIZE, BLOCK>>> (array, sum, elements);
}

// 5
void sharedmem(int* array, int* sum, int elements){
  int TB_SIZE = BLOCK_DIM;
  int GRID_SIZE = (elements/2 + TB_SIZE - 1) / TB_SIZE;
  sharedmem_reduction_kernel<<<GRID_SIZE, TB_SIZE>>> (array, sum, elements);
}

// 6
void coarsened(int* array, int* sum, int elements){
  int TB_SIZE = BLOCK_DIM;
  int GRID_SIZE = ((elements/2 + TB_SIZE - 1) / TB_SIZE)/COARSE_FACTOR;
  coarsened_reduction_kernel<<<GRID_SIZE, TB_SIZE>>> (array, sum, elements);
}

void CUBCuda(int* array, int* sum, int elements){
  void     *d_temp_storage = NULL;    // CUB temp allocations
  size_t   temp_storage_bytes = 0;
  cub::DeviceReduce::Sum(d_temp_storage, temp_storage_bytes, array, sum, elements); // Storage requirements
  cudaMalloc(&d_temp_storage, temp_storage_bytes); // Allocate temporary storage
  cub::DeviceReduce::Sum(d_temp_storage, temp_storage_bytes, array, sum, elements);
}
  
void ThrustCUDA(int* array, int* sum, int elements){
  thrust::device_vector<int> thrustVec(array, array + elements);
  *sum = thrust::reduce(thrustVec.begin(), thrustVec.end());
}