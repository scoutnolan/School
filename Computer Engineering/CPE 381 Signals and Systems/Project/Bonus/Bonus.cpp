// ************************************************
// Name: Nolan Anderson
// Course: CPE 381
// Assignment: Project Bonus
// Due date: 26 April 2021
// Compilation: UAH Blackhawk servers. Use make file to compile or:
//          	g++ -g -std=c++11 Anderson_N_Phase2.cpp -o PhaseOneExecutable
//              All of this is performed in bash.
// Execution    ./PhaseTwoExecutable
// Description: Reads through a .wav file and modifies it by
//              removing noise from the signal.
//              Also outputs additional information about the 
//              modifications made. 
// ************************************************
#ifndef __USE_SQUARE_BRACKETS_FOR_ELEMENT_ACCESS_OPERATOR
#define __USE_SQUARE_BRACKETS_FOR_ELEMENT_ACCESS_OPERATOR 
#endif//!__USE_SQUARE_BRACKETS_FOR_ELEMENT_ACCESS_OPERATOR

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctime>			
#include <iostream>		
#include <fstream>			
#include <math.h>		
#include <cstring>		
#include "../fft.h"
#include "../fft_settings.h"

using namespace std;
using namespace simple_fft;
using namespace impl;

const float Pi = 3.14159f;
const uint16_t Max = 32767;         // 16bit integer Max.
const int16_t Min = -32768;         // 16bit unsigned integer min.

// Wave header 
struct waveHeader {
	char chunkID[4];
	uint32_t chunkSize;
	char format[4];
	uint32_t subChunk1ID;
	uint32_t subChunk1Size;
	uint16_t audioFormat;
	uint16_t numChannels;
	uint32_t sampleRate;
	uint32_t byteRate;
	uint16_t blockAlign;
	uint16_t bitsPerSample;
	char DATA[4];
	uint32_t  dataSize;
};

typedef struct waveHeader* HBuff;
typedef real_type* RealArray1D;
typedef complex_type* ComplexArray1D;
const int NFFT = 2048;
const int overlap = 512;

int main(void)
{
	// **************** // 
	waveHeader WaveObj;	// Wave header object
	HBuff MHead = (HBuff)malloc(sizeof(WaveObj));
	clock_t StartTimer;
	clock_t EndTimer;
	double ProcessTime = 0;
	double PlayTime = 0;
	double* CList{};		// Coefficients.
	int CLength = 0;
	int16_t* LChannel;		// Left Channel
	int16_t* RChannel;		// Right Channel
	int16_t CSample = 0;			// Current 
	int16_t InSample = 0;			// Input 
	int16_t OutSample = 0;			// Output 
	int16_t FiltSample = 0;			// Sample filtered
	unsigned long NumSamples = 0;	// Number of samples
	unsigned long Index = 0;		// Index to move through samples.
	complex_type rms;
	complex_type sq;
	complex_type avg;
	int iterator = 0;
	int it2 = 0;
	const char* errormsg;
	double FMAX;
	double t = 0;
	int max = 0;
	// **************** //

	// **************** //
	// Input output handling
	FILE* wavFile;
	ofstream sumFile;
	string filename;
	//cout << "Input file?\n";
	//cin >> filename;
	filename = "Anderson_N_matlab.wav";
	wavFile = fopen(filename.c_str(), "rb");
	sumFile.open("Anderson_N_sum.txt");
	fread(&WaveObj, sizeof(WaveObj), 1, wavFile);		// Input file into the header.

	if (!wavFile) { cout << "ERROR: Could not open input file. Restart program" << endl; return 0; }
	if (!sumFile) { cout << "ERROR: Could not open summary file. Restart program" << endl; return 0; }
	// **************** //

	StartTimer = clock();
	if (wavFile)
	{
		ofstream Excel;
		Excel.open("Anderson_N_bonus.csv");
		if (!Excel) { cout << "ERROR: Could not open Excel file. Restart program" << endl; return 0; }
		// Initialize I/O.
		Excel << "TIME (s), FMAX, POWER" << endl;	// Initialize EXCEL.

		fread(MHead, 1, sizeof(WaveObj), wavFile);	// Read into the header object.

		// Initialize complex and real values.
		RealArray1D in = new real_type[NFFT];				// inputvals
		ComplexArray1D fft = new complex_type[NFFT / 2];	// fftvals
		short int over_buff[overlap];
		bool window = true;

		// Loop Through File.
		while(!feof(wavFile))
		{
			int j = 0;
			for (int it = 0; it < NFFT && !feof(wavFile); iterator++)
			{
				if (it <= overlap && !window)
				{
					in[it] = over_buff[it];
					it++;
				}
				else if (iterator % 2 == 0)
				{
					fread(&CSample, sizeof(CSample), 1, wavFile);
					in[it] = CSample;
					if (it >= NFFT * 0.75)
					{
						over_buff[it2] = CSample;
						it2++;
					}
					j++;
					NumSamples++;
				}
				else { fread(&CSample, sizeof(CSample), 1, wavFile); }
			}
			bool result = FFT(in, fft, NFFT / 2, errormsg);

			FMAX = abs(fft[0]);
			for (max = 0; max < NFFT / 2; max++)
			{
				if (abs(fft[max]) > FMAX) 
				{ 
					FMAX = abs(fft[max]); 
					Excel << t << "," << FMAX << "," << rms.real() << endl;

				}
			}

			for (int it = 0; it < NFFT / 2; it++) { sq = sq + (fft[it] * conj(fft[it])); }

			avg = sq / complex_type(NFFT);
			rms = sqrt(avg);

			FMAX = max * double(double(WaveObj.sampleRate) / double(NFFT / 2));
			FMAX = 0;
			window = false;
			t = (t - 0.25) + 1;
		} 

		fclose(wavFile);
		Excel.close();
	}

	else {
		cout << "Cannot open output file. " << endl;
	}

	// Perform final calcuations
	NumSamples = ((WaveObj.dataSize / WaveObj.numChannels) / (WaveObj.bitsPerSample / 8));
	EndTimer = clock();
	ProcessTime = -1.0 * (double(StartTimer) - double(EndTimer)) / CLOCKS_PER_SEC;
	PlayTime = double(NumSamples / WaveObj.sampleRate);

	// Output to summary file
	sumFile << "--------------------------" << endl;
	sumFile << "Anderson_N_sum.txt" << endl;
	sumFile << "Displays the information of processing the wav file." << endl;
	sumFile << "Number of Samples \t\t=  " << NumSamples << " samples" << endl;
	sumFile << "Bits per Sample \t\t=  " << WaveObj.bitsPerSample << " bits" << endl;
	sumFile << "Sample Frequency \t\t=  " << WaveObj.sampleRate << " Hz" << endl;
	sumFile << "Data Size \t\t\t\t=  " << WaveObj.dataSize << " bytes" << endl;
	sumFile << "Number of Channels \t\t=  " << WaveObj.numChannels << " channels" << endl;
	sumFile << "Byte Rate Taken \t\t=  " << WaveObj.byteRate << " bps" << endl;
	sumFile << "Playing Time \t\t\t=  " << PlayTime << " seconds" << endl;
	sumFile << "Processing Time \t\t=  " << ProcessTime << " seconds" << endl;
	//sumFile << "Maximum found at Index \t=  " << AIndex << " [sample]" << endl;
	//sumFile << "Maximum Frequency \t\t=  " << MaxFatA << " [Hz]" << endl;
	sumFile << "--------------------------" << endl;
	return 0;
}