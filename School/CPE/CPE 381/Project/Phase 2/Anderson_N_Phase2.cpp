// ************************************************
// Name: Nolan Anderson
// Course: CPE 381
// Assignment: Project 1 Phase 2
// Due date: 19 March 2021
// Compilation: UAH Blackhawk servers. Use make file to compile or:
//          	g++ -g -std=c++11 Anderson_N_Phase2.cpp -o PhaseOneExecutable
//              All of this is performed in bash.
// Execution    ./PhaseTwoExecutable
// Description: Reads through a .wav file and modifies it by
//              removing noise from the signal.
//              Also outputs additional information about the 
//              modifications made. 
// ************************************************

#include "filter_22050.h" 	// 22050 Filter coeffecients 
#include "filter_11025.h" 	// 11025 Filter coeffecients
#include <ctime>			
#include <iostream>		
#include <fstream>			
#include <math.h>		
#include <cstring>		

using namespace std;		
									
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

uint16_t FilterFIR(int16_t* Channel, int FirstLength, double* B1);

int main() {
	// Initialize Values
	waveHeader WaveObj;	// Wave header object
	clock_t StartTimer;
	clock_t EndTimer;
	double ProcessTime = 0;
	double PlayTime = 0;
	double* CList{};		// Coefficients.
	int CLength=0;			
	int16_t* LChannel;		// Left Channel
	int16_t* RChannel;		// Right Channel
	int16_t CSample = 0;			// Current 
	int16_t InSample = 0;			// Input 
	int16_t OutSample = 0;			// Output 
	int16_t FiltSample = 0;			// Sample filtered
	unsigned long NumSamples = 0;	// Number of samples
	unsigned long Index = 0;		// Index to move through samples.

	// Input output handling
	FILE* inFile;		
	FILE* outFile;     	
	ofstream sumFile;	
	string filename;
	cout << "Input file?\n";
	cin >> filename; 

	inFile = fopen(filename.c_str(), "rb");
	outFile = fopen("Anderson_N_filt.wav", "wb");
	sumFile.open("Anderson_N_sum.txt");
							
	if (!inFile) {cout << "ERROR: Could not open input file. Restart program" << endl; return 0;}
	if (!outFile) {cout << "ERROR: Could not open output file. Restart program" << endl; return 0;}
	if (!sumFile) {cout << "ERROR: Could not open summary file. Restart program" << endl; return 0;}

	StartTimer = clock();	
	fread(&WaveObj, sizeof(WaveObj), 1, inFile);		// Input file into the header.
	fwrite(&WaveObj, sizeof(WaveObj), 1, outFile);	// Write the Header into the output file.

	// Check channels and frequency values
	if (WaveObj.numChannels == 2) {}
	else {
		cout << "ERROR: Not enough channels (needs 2)" << endl;
		cout << "Number of Channels " << WaveObj.numChannels << endl;
		return 0;
	}

	if (WaveObj.sampleRate == 22050) {
		CLength = BL1;
		CList = (double*)B1;
	}
	else if (WaveObj.sampleRate == 22050 / 2) {
		CLength = BL2;
		CList = (double*)B2;
	}
	else {
		cout << "ERROR: Please use sample rate of 22050 or 11025." << endl;
		cout << "Given sample rate: " << WaveObj.sampleRate << endl;
	}

	LChannel = new int16_t[CLength];
	RChannel = new int16_t[CLength];

	long MaxA = 0;
	long AIndex = 0;
	long MaxFatA = 0;

	// While not at end of file, input even samples into left channel
	// and input odd samples into right channel.
	long unsigned int i = 0;
	while (!feof(inFile) && i < WaveObj.dataSize) {
		fread(&CSample, sizeof(short), 1, inFile);			// Read sample
		if (i % 2 == 0) {									// Even
			memcpy(LChannel, &LChannel[1], sizeof(short) * (CLength - 1));
			LChannel[CLength - 1] = CSample;
			OutSample = FilterFIR(LChannel, CLength, CList);
		}
		else {												// Odd
			memcpy(RChannel, &RChannel[1], sizeof(short) * (BL1 - 1));
			RChannel[BL1 - 1] = CSample;
			OutSample = FilterFIR(RChannel, CLength, CList);
		}
		fwrite(&OutSample, sizeof(short), 1, outFile);		// Write to file
		if (abs(CSample) > MaxA) {
			MaxA = abs(CSample);
			AIndex = i / 2;
		}
		i++;
	}
	
	// Perform final calcuations
	NumSamples = ((WaveObj.dataSize / WaveObj.numChannels) / (WaveObj.bitsPerSample / 8)); 
	MaxFatA = WaveObj.sampleRate * AIndex / NumSamples; 	
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
	sumFile << "Maximum found at Index \t=  " << AIndex << " [sample]" << endl;
	sumFile << "Maximum Frequency \t\t=  " << MaxFatA << " [Hz]" << endl;
	sumFile << "--------------------------" << endl;

	fclose(inFile); fclose(outFile); sumFile.close();
	return 1;
}

// This function takes in the values from the filter designs and returns the final value. 
// Called by the while loop.
uint16_t FilterFIR(int16_t* Channel, int FirstLength, double* B1) {
	double y = 0; 
	for (int i = 0; i < (FirstLength - 1); i++)
		y += (B1[i] * double(Channel[BL1 - i])); 
	return uint16_t(y);	
}