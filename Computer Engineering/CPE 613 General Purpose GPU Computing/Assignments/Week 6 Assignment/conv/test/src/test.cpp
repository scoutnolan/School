/*
    Nolan Anderson
    CPE 613 Week 6 Assignment 2
    Convolution assignment with applying a filter to a grayscale image. 

    To run / compile: 
    module load cuda && module load blas
    make run
*/

#include <conv.h>
#include <Timer.hpp>
#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std; 

#define FILTER_RADIUS 2
__constant__ float constantFilter[(2*FILTER_RADIUS+1)* (2*FILTER_RADIUS+1)];

void outputImage(string filename, float* InImage, int width, int height){
    int *outImage = (int*)malloc(sizeof(int) * width * height);
    ofstream outFile;
    for(int i = 0; i < height * width; i++)
        outImage[i] = (int)ceil(InImage[i]);
    outFile.open(filename);
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            outFile << outImage[r * width + c] << " ";
        }
        outFile << endl;
    }
    delete outImage;
}

int main (int argc, char ** argv) {

  ofstream excel;
  excel.open("/home/uahclsc0003/source/week6/MatrixMultiply/results.csv");
  excel << "Num,ET,Comp Rate,Effective Bandwidth \n";
  // Pull in the image, get dimension size.
  ifstream inFile;
  inFile.open("/home/uahclsc0003/source/week6/MatrixMultiply/conv/test/src/grayscale.txt"); 
  int width, height;
  inFile >> width >> height;
  size_t dimSize = width * height;
  size_t matrixSize = width * height * sizeof(float);  
  float *grayMatrix = (float*)malloc(matrixSize);
  float *imageHost = (float*)malloc(matrixSize);

  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      inFile >> grayMatrix[row * width + col];
    }
  }

  // Create the filter
  int k = 2; //max distance to the center
  float PI = 3.14159265;
  int filtDim = 2 * k + 1;//;
  float std = 1.0f;
  float *filterHost = (float*)malloc(filtDim * filtDim * sizeof(float));
  float sum = 0.0f;
  for(int r = 0; r < filtDim; r++){
      for(int c = 0; c < filtDim; c++){
          filterHost[r * filtDim + c] = exp(-(pow(r-k,2) + pow(c-k,2))/(2.0*std*std))/(2.0*PI*std*std);
          sum += filterHost[r * filtDim + c];
      }   
  }
  for(int i = 0; i < filtDim * filtDim; i++){
      filterHost[i] /= sum;
  }

  // Create the matrices we will pass to the device.
  size_t filterSize = filtDim * filtDim * sizeof(float);  //  Size of the filter
  float *Original = nullptr; float *Filter = nullptr; float *Output = nullptr;
  
  // Allocate space on the device
  checkCudaErrors(cudaMalloc((void**)&Original, matrixSize)); // Input
  checkCudaErrors(cudaMalloc((void**)&Filter, filterSize));   // Filter
  checkCudaErrors(cudaMalloc((void**)&Output, matrixSize));   // Output Image

  // Copy data to the device
  checkCudaErrors(cudaMemcpy(Original, grayMatrix,  matrixSize, cudaMemcpyHostToDevice));
  checkCudaErrors(cudaMemcpy(Filter, filterHost, filterSize, cudaMemcpyHostToDevice));

  // Create the timer
  Timer Timer1, Timer2, Timer3, Timer4, Timer5, Timer6;

  // Call the functions in matmul.cu
  Timer1.start();
  Number1(Original, Filter, Output, k, width, height);
  Timer1.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number1.txt", imageHost, width, height);

  Timer2.start();
  Number2(Original, Filter, Output, k, width, height);
  Timer2.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number2.txt", imageHost, width, height);

  checkCudaErrors(cudaMemcpyToSymbol(constantFilter, filterHost, filterSize));
  Timer3.start();
  Number3(Original, Output, k, width, height);
  Timer3.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number3.txt", imageHost, width, height);

  Timer4.start();
  Number4(Original, Filter, Output, k, width, height);
  Timer4.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number4.txt", imageHost, width, height);

  Timer5.start();
  Number5(Original, Output, k, width, height);
  Timer5.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number5.txt", imageHost, width, height);

  Timer6.start();
  Number6(Original, Output, k, width, height);
  Timer6.stop();
  checkCudaErrors(cudaMemcpy(imageHost, Output, matrixSize, cudaMemcpyDeviceToHost));
  outputImage("Number6.txt", imageHost, width, height);

  double numWrite = dimSize;
  double numberOfFlops = ((float) 2 * FILTER_RADIUS * FILTER_RADIUS * dimSize);
  double numRead = FILTER_RADIUS * FILTER_RADIUS * 2 * dimSize;

  // Plug and chug
  double Time_MS_1 = Timer1.elapsedTime_ms();
  double flopRate_1 = numberOfFlops / (Time_MS_1 / 1.0e3);
  double BandWidth_1 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_1 / 1.0e3)};

  double Time_MS_2 = Timer2.elapsedTime_ms();
  double flopRate_2 = numberOfFlops / (Time_MS_2 / 1.0e3);
  double BandWidth_2 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_2 / 1.0e3)};

  double Time_MS_3 = Timer3.elapsedTime_ms();
  double flopRate_3 = numberOfFlops / (Time_MS_3 / 1.0e3);
  double BandWidth_3 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_3 / 1.0e3)};

  double Time_MS_4 = Timer4.elapsedTime_ms();
  double flopRate_4 = numberOfFlops / (Time_MS_4 / 1.0e3);
  double BandWidth_4 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_4 / 1.0e3)};

  double Time_MS_5 = Timer5.elapsedTime_ms();
  double flopRate_5 = numberOfFlops / (Time_MS_5 / 1.0e3);
  double BandWidth_5 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_5 / 1.0e3)};

  double Time_MS_6 = Timer6.elapsedTime_ms();
  double flopRate_6 = numberOfFlops / (Time_MS_6 / 1.0e3);
  double BandWidth_6 {(numRead + numWrite) * sizeof(float) * 8 / (Time_MS_6 / 1.0e3)};

  // Output calculations / findings
  printf("Approach  Execution Time     Computational Rate              Effective Bandwidth \n");
  printf("Number 1  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_1 / 1.0e3, flopRate_1 / 1e9, BandWidth_1 / 1e9);
  printf("Number 2  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_2 / 1.0e3, flopRate_2 / 1e9, BandWidth_2 / 1e9);
  printf("Number 3  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_3 / 1.0e3, flopRate_3 / 1e9, BandWidth_3 / 1e9);  
  printf("Number 4  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_4 / 1.0e3, flopRate_4 / 1e9, BandWidth_4 / 1e9);
  printf("Number 5  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_5 / 1.0e3, flopRate_5 / 1e9, BandWidth_5 / 1e9);
  printf("Number 6  %f seconds | %20.16e Gflops | %20.16e Gbps |\n", Time_MS_6 / 1.0e3, flopRate_6 / 1e9, BandWidth_6 / 1e9);
  printf("=========================================================================================================================\n");
  excel << "1" << "," << Time_MS_1 / 1.0e3 << "," << flopRate_1 / 1e9 << "," << BandWidth_1 / 1e9 << "\n";
  excel << "2" << "," << Time_MS_2 / 1.0e3 << "," << flopRate_2 / 1e9 << "," << BandWidth_2 / 1e9 << "\n";
  excel << "3" << "," << Time_MS_3 / 1.0e3 << "," << flopRate_3 / 1e9 << "," << BandWidth_3 / 1e9 << "\n";
  excel << "4" << "," << Time_MS_4 / 1.0e3 << "," << flopRate_4 / 1e9 << "," << BandWidth_4 / 1e9 << "\n";
  excel << "5" << "," << Time_MS_5 / 1.0e3 << "," << flopRate_5 / 1e9 << "," << BandWidth_5 / 1e9 << "\n";
  excel << "6" << "," << Time_MS_6 / 1.0e3 << "," << flopRate_6 / 1e9 << "," << BandWidth_6 / 1e9 << "\n";

  checkCudaErrors(cudaFree(Original));
  checkCudaErrors(cudaFree(Filter));
  checkCudaErrors(cudaFree(Output));
  excel.close();
  return 0;
}