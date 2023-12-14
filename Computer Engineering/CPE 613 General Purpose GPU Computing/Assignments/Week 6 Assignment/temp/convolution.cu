#include <convolution.h>
#include <helper_cuda.h>

#define FILTRAD 5

__constant__ float constFilt[FILTRAD*FILTRAD];

//EXERCISE 1
__global__ void convolution_naive_kernel(
    int         width,
    int         height,
    int         filtRad,
    float   *   grayImageDevice,
    float   *   filtImageDevice,
    float   *   filterDevice
) {
    int outCol = blockIdx.x * blockDim.x + threadIdx.x;
    int outRow = blockIdx.y * blockDim.y + threadIdx.y;

    float pVal = 0.0f;
    if(outCol < width && outRow < height)
        for(int r = 0; r < 2 * filtRad + 1; r++){
            for(int c = 0; c < 2 * filtRad + 1; c++){
                int inRow = outRow - filtRad + r; 
                int inCol = outCol - filtRad + c;

                if(inRow >= 0 && inRow < height && inCol >= 0 && inCol < width){
                    pVal += filterDevice[r * filtRad + c] * grayImageDevice[inRow * width + inCol];
                }
            }
        }

        filtImageDevice[outRow * width + outCol] = pVal;
    }

void convolutionNaive(
    int     width,
    int     height,
    int     filtRad,
    float * grayImageDevice,
    float * filtImageDevice,
    float * filtGaussDevice
) {

    dim3 numBlocks(16,16);
    dim3 gridSize((width + numBlocks.x - 1)/numBlocks.x,
                  (height + numBlocks.y - 1)/numBlocks.y);

    convolution_naive_kernel <<< gridSize, numBlocks >>>(
        width,
        height,
        filtRad,
        grayImageDevice,
        filtImageDevice,
        filtGaussDevice
    );

    checkCudaErrors(cudaGetLastError());
}

//EXERCISE 2

__global__ void convolution_shared_kernel(
    int     width,
    int     height,
    int     filtRad,
    float * grayImageDevice,
    float * filtImageDevice,
    float * filterDevice
) {
    
    int outCol = blockIdx.x * blockDim.x + threadIdx.x;
    int outRow = blockIdx.y * blockDim.y + threadIdx.y;

    __shared__ float filter[FILTRAD*FILTRAD];

    float pVal = 0.0f;

    if(outCol < width && outRow < height){
        //load filter
        for(int r = 0; r < 2*filtRad + 1; r++){
            for(int c = 0; c < 2*filtRad + 1; c++){
                filter[r * filtRad*filtRad + c] = filterDevice[r * filtRad*filtRad + c];
            }
        }

        __syncthreads();

        for(int r = 0; r < 2 * filtRad + 1; r++){
            for(int c = 0; c < 2 * filtRad + 1; c++){
                int inRow = outRow - filtRad + r; 
                int inCol = outCol - filtRad + c;

                if(inRow >= 0 && inRow < height && inCol >= 0 && inCol < width){
                    pVal += filter[r * filtRad + c] * grayImageDevice[inRow * width + inCol];
                }
            }
        }

        filtImageDevice[outRow * width + outCol] = pVal;
    }
}


void convolutionShared(
    int     width,
    int     height,
    int     filtRad,
    float * grayImageDevice,
    float * filtImageDevice,
    float * filtGaussDevice
) {

    dim3 numBlocks(16,16);
    dim3 gridSize((width + numBlocks.x - 1)/numBlocks.x,
                  (height + numBlocks.y - 1)/numBlocks.y);

    convolution_shared_kernel <<< gridSize, numBlocks >>>(
        width,
        height,
        filtRad,
        grayImageDevice,
        filtImageDevice,
        filtGaussDevice
    );

    checkCudaErrors(cudaGetLastError());
}

//EXERCISE 3
__global__ void convolution_const_kernel(
    int         width,
    int         height,
    int         filtRad,
    float   *   grayImageDevice,
    float   *   filtImageDevice
) {
    int outCol = blockIdx.x * blockDim.x + threadIdx.x;
    int outRow = blockIdx.y * blockDim.y + threadIdx.y;

    float pVal = 0.0f;
    if(outCol < width && outRow < height)
        for(int r = 0; r < 2 * filtRad + 1; r++){
            for(int c = 0; c < 2 * filtRad + 1; c++){
                int inRow = outRow - filtRad + r; 
                int inCol = outCol - filtRad + c;

                if(inRow >= 0 && inRow < height && inCol >= 0 && inCol < width){
                    pVal += constFilt[r * filtRad + c] * grayImageDevice[inRow * width + inCol];
                }
            }
        }

        filtImageDevice[outRow * width + outCol] = pVal;
    }

void convolutionConst(
    int     width,
    int     height,
    int     filtRad,
    float * grayImageDevice,
    float * filtImageDevice
) {

    dim3 numBlocks(16,16);
    dim3 gridSize((width + numBlocks.x - 1)/numBlocks.x,
                  (height + numBlocks.y - 1)/numBlocks.y);

    convolution_const_kernel <<< gridSize, numBlocks >>>(
        width,
        height,
        filtRad,
        grayImageDevice,
        filtImageDevice
    );

    checkCudaErrors(cudaGetLastError());
}

