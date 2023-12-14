/*
    Nolan Anderson
    CPE 613 Chapter 8, 9, 10 assignment
    Sum reduction and optimization

    To run / compile: 
    module load cuda && module load blas
    make run
*/

#include <reduction.h>
#include <Timer.hpp>
#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <cmath>
#include <cstdio>
#include <typeinfo>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std; 
ofstream excel; // excel file for results 

template <typename R> void reduce(int n){
    
    float numFlops = n; // number of flops is just adds
    Timer time; // Timer to return
    R* HostArray = new R[n]; // Create and populate new array of type R
    for(int r = 0; r < n; ++r)
        HostArray[r] = (int)rand()%100;

    size_t ArraySize = n * sizeof(R);
    size_t ResultSize = sizeof(R);
    
    for(int exercise = 0; exercise <= 8; exercise++){
        if(exercise == 0){  // Host version
            int sum = 0;
            time.start();
            for(int i = 0; i < n; i++)
                sum += HostArray[i];
            time.stop();
            excel << n << "," << "int" << "," << "Host" << "," << time.elapsedTime_ms() / 1.0e3 << "," << sum << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) << "\n";
        }
        else{
            R *Result = (int*)malloc(sizeof(int));
            R* DeviceArray = nullptr;
            R* HostResult = nullptr;

            checkCudaErrors(cudaMalloc(&DeviceArray, ArraySize));
            checkCudaErrors(cudaMalloc(&HostResult, ResultSize));
            checkCudaErrors(cudaMemcpy(DeviceArray, HostArray, ArraySize, cudaMemcpyHostToDevice));

            switch(exercise){
                case 1: // Sequential CUDA
                    time.start();
                    sequential(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Sequential" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 2: // Atomics
                    time.start();
                    atomicf(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Atomic" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 3: // Segmented reduction
                    time.start();
                    segmented(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Segmented" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 4: // Coalescing
                    time.start();
                    coalescing(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Coalescing" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 5: // Shared memory
                    time.start();
                    sharedmem(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Shared Memory" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 6: // Corasened
                    time.start();
                    coarsened(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "Coarsened" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) <<"\n";
                    break;
                case 7: // CUB
                    time.start();
                    CUBCuda(DeviceArray, HostResult, n);
                    time.stop();
                    checkCudaErrors(cudaMemcpy(Result, HostResult, ResultSize, cudaMemcpyDeviceToHost));
                    excel << n << "," << "int" << "," << "CUB" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *Result << ","  << numFlops / (time.elapsedTime_ms() / 1.0e3) << "\n";
                    break;
                case 8: // Thrust
                    R *TResult = (int*)malloc(sizeof(int));
                    time.start();
                    ThrustCUDA(HostArray, TResult, n);
                    time.stop();
                    excel << n << "," << "int" << "," << "Thrust" << "," << time.elapsedTime_ms() / 1.0e3 << "," << *TResult << "," << numFlops / (time.elapsedTime_ms() / 1.0e3) << "\n";
                    free(TResult);
                    break;
            }
            checkCudaErrors(cudaFree(DeviceArray)); // free device and host result each loop
            checkCudaErrors(cudaFree(HostResult));
            free(Result); // free result for next array size
        }
    }
    free(HostArray); // free the host array for next array size
}

int main(){
    excel.open("/home/uahclsc0003/source/Reduction/Reduction.csv");     // Excel file for results
    excel << "Array Size,Datatype,Approach,ET,Sum,Flop Rate \n";    // headers
    int ArraySize[5] = {4096, 8192, 16384, 32768, 65536}; // Array of values
    for(int i = 0; i <= 4; i++) // Loop through matrices. Each time we will create new threads
        reduce<int>(ArraySize[i]);
    excel.close();
    return 0;
}