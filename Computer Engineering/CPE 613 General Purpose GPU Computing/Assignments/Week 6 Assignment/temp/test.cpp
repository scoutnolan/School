#include <Timer.hpp>
#include <convolution.h>

#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

#include <cuda_runtime.h>
#include <helper_cuda.h>

using namespace std;

void fileOut(string filename, float* filtImageHost, int width, int height);

int main(int argc, char** argv){

    ifstream inFile;
    inFile.open("grayscale.txt");
    
    int height, width;
    inFile >> width >> height;

    float   *grayImageHost  = (float*)malloc(width * height * sizeof(float));
    float   *filtImageHost  = (float*)malloc(width * height * sizeof(float));


    //get image values into arrays
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            inFile >> grayImageHost[r*width + c];
        }
    }

    //gaussian filter
    int k = 2; //max distance to the center
    int filtDim = 2 * k + 1;
    float std = 1.0f;
    float *filtGaussHost = (float*)malloc(filtDim * filtDim * sizeof(float));
    float gaussSum = 0.0f;

    for(int r = 0; r < filtDim; r++){
        for(int c = 0; c < filtDim; c++){
            filtGaussHost[r * filtDim + c] = exp(-(pow(r-k,2) + pow(c-k,2))/(2.0*std*std))/(2.0*PI*std*std);
            gaussSum += filtGaussHost[r * filtDim + c];
            #ifdef DEBUG
                cout << filtGaussHost[r * filtDim + c] << " ";
            #endif
        }   

        #ifdef DEBUG
            cout << endl;
        #endif
    }

    //normalize
    for(int i = 0; i < filtDim * filtDim; i++){
        filtGaussHost[i] /= gaussSum;
    }

    //DEVICE RESOURCE ALLOCATION AND DATA COPY    

    size_t imageSize = width * height * sizeof(float);
    size_t filtSize = filtDim * filtDim * sizeof(float);

    float *grayImageDevice = nullptr;
    float *filtImageDevice = nullptr;
    float *filtGaussDevice = nullptr;

    checkCudaErrors(
        cudaMalloc((void**)&grayImageDevice, imageSize)
    );

    checkCudaErrors(
        cudaMalloc((void**)&filtImageDevice, imageSize)
    );

    checkCudaErrors(
        cudaMalloc((void**)&filtGaussDevice, filtSize)
    );

    checkCudaErrors(
        cudaMemcpy(
            grayImageDevice, 
            grayImageHost, 
            imageSize,
            cudaMemcpyHostToDevice
        )
    );  

    checkCudaErrors(
        cudaMemcpy(
            filtGaussDevice, 
            filtGaussHost, 
            filtSize,
            cudaMemcpyHostToDevice
        )
    );

    //EXERCISE 1
    convolutionNaive(
        width,
        height,
        k,
        grayImageDevice,
        filtImageDevice,
        filtGaussDevice
    );


    checkCudaErrors(
        cudaMemcpy(
            filtImageHost,
            filtImageDevice,
            imageSize,
            cudaMemcpyDeviceToHost
        )
    );

    fileOut("Exercise1.txt", filtImageHost, width, height);

    //EXERCISE 2
    convolutionShared(
        width,
        height,
        k,
        grayImageDevice,
        filtImageDevice,
        filtGaussDevice
    );


    checkCudaErrors(
        cudaMemcpy(
            filtImageHost,
            filtImageDevice,
            imageSize,
            cudaMemcpyDeviceToHost
        )
    );

    fileOut("Exercise2.txt", filtImageHost, width, height);

    //EXERCISE 2
    convolutionShared(
        width,
        height,
        k,
        grayImageDevice,
        filtImageDevice,
        filtGaussDevice
    );

    checkCudaErrors(
        cudaMemcpy(
            filtImageHost,
            filtImageDevice,
            imageSize,
            cudaMemcpyDeviceToHost
        )
    );

    fileOut("Exercise2.txt", filtImageHost, width, height);

    //EXERCISE 3
    checkCudaErrors(
        cudaMemcpyToSymbol("constFilt", filtGaussHost, filtSize)
    );

    convolutionConst(
        width,
        height,
        k,
        grayImageDevice,
        filtImageDevice
    );

    checkCudaErrors(
        cudaMemcpy(
            filtImageHost,
            filtImageDevice,
            imageSize,
            cudaMemcpyDeviceToHost
        )
    );

    fileOut("Exercise3.txt", filtImageHost, width, height);

    
    //FREE MEMORY
    checkCudaErrors(cudaFree(grayImageDevice));
    checkCudaErrors(cudaFree(filtImageDevice));
    checkCudaErrors(cudaFree(filtGaussDevice));

    return 0;
}

void fileOut(string filename, float* filtImageHost, int width, int height){

    int *filtImageInt = (int*)malloc(sizeof(int) * width * height);
    ofstream outFile;
        
    for(int i = 0; i < height * width; i++){
        filtImageInt[i] = (int)ceil(filtImageHost[i]);
    }

    outFile.open(filename);

    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            outFile << filtImageInt[r * width + c] << " ";
        }
        outFile << endl;
    }

    delete filtImageInt;

}