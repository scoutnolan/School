// ************************************************
// Name: Nolan Anderson
// Course: CPE 381
// Assignment: Project 1 Phase 1
// Due date: 16 March 2021
// Compilation: UAH Blackhawk servers. Use make file to compile or:
//          	g++ -g -std=c++11 Anderson_N_Phase1.cpp -o PhaseOneExecutable
//              All of this is performed in bash.
// Execution    ./PhaseOneExecutable
// Description: Reads through a .wav file and modifies it by
//              adding noise to the original values. 
//              Also outputs additional information about the 
//              modifications made. 
// ************************************************
#include <iomanip>
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct wavHeader{
    char       chunkId[4];
    int        chunkSize;
    char       format[4];
    char       subChunk1Id[4];
    int        subChunk1Size;
    short int  audioFormat;
    short int  numChannels;
    int        sampleRate;
    int        byteRate;
    short int  blockAlign;
    short int  bitsPerSample;
    char       subChunk2Id[4];
    int        subChunk2Size;
};

int main(int argc, char* argv[])
{
    string in; 
	string WavModified = "Anderson_N_mod.wav";
	string OutSummary = "Anderson_N_sum.txt";
    cout << "Please enter a file name: ";
    cin >> in;
    // in = "Anderson_N_matlab.wav";

    wavHeader audioFile;

    FILE* input = fopen(in.c_str(), "r");
    FILE* output = fopen(WavModified.c_str(), "w+");
    FILE* summary = fopen(OutSummary.c_str(), "w+");

    fread(&audioFile, sizeof(audioFile), 1, input);
    fwrite(&audioFile, sizeof(audioFile), 1, output);

    int16_t data;
    long maxAbsVal = 0;
    float t = 0.0;
    int Amax = 65535;

    auto start = high_resolution_clock::now(); 
    while(!feof(input))
    {
        fread(&data, (audioFile.bitsPerSample / 8), 1, input);
        t += 1.0f / audioFile.sampleRate;
        if (abs(data) > maxAbsVal)              // Maximum absolute value of the sample
        {
            maxAbsVal = abs(data); 
        }
        short Max = 0.01 * Amax;                            // 0.01*Amax
        short random_noise = 0.02 * short(rand() / Amax);   // Randomnoise
        data = data + random_noise - Max;                   // Final output
        if(data > Amax/2)                                   // Overflow correction 
        {
            data = Amax/2;
        }                          
        fwrite(&data, (sizeof(data)), 1, output);           // Write to output file
    }

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start); 
    int sampleLength = (audioFile.subChunk2Size / 4) / audioFile.sampleRate;

    fprintf(summary, "Input File Name:               %s\n", in.c_str());
    fprintf(summary, "Output File Name:              %s\n", WavModified.c_str());
    fprintf(summary, "Summary File Name:             %s\n\n", OutSummary.c_str());
    fprintf(summary, "Sampling Frequency:            %d hz\n", audioFile.sampleRate);
    fprintf(summary, "Number of Channels:            %d\n", audioFile.numChannels);
    fprintf(summary, "Number of Bits In Each Sample: %d\n", audioFile.bitsPerSample);
    fprintf(summary, "Length:                        %ds\n", sampleLength);
    fprintf(summary, "Maximum Value of Sample:       %ld\n", maxAbsVal);
    fprintf(summary, "Execution Time:                %dms\n", duration);
    return 0;
}