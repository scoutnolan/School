// ****************************************
// Program Title: Project2
// Project File: Simulation.h
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************
#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "CityData.h"
#include "FlightData.h"
#include "AircraftData.h"
#include <sys/types.h>	// needed for the _ftime_s() function
#include <sys/timeb.h>	// contains definition of _timeb struct
#include <time.h>		// needed for other time functions and structures
#include <string>
#include <limits>
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
private:
	int clockMult{ 0 };
	int Counter{ 0 };
	int CurrentMin{ 0 };
	int	CurrentHr{ 0 };
	string inputFile;
	struct _timeb tStruct { 0 };
	double thisTime{ 0 };
	double outputTime{ 0 };
	vector <Aircraft> AircraftList;

public:
	Simulation();
	~Simulation();
	double getFlightETA(double distance, char* mak, vector<Aircraft> aircraft);
	void runSimulation(double clocktime);
	void initializeSimulation();
	void PrintCurrentTime();
	void PrintStartTime();
	void PrintAllFlights(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	void PrintNewFlights(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin);
	void PrintArrival(City C, Flight F, int CurrentHr, int CurrentMin);
	int CalcETAHr(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin);
	int CalcETAMin(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin);
	
	City* testCity;
	Flight* testFlight;
	Aircraft* testAircraft;

	// Set functions
	void setClockMult(int param);
	void setInFile(string param);

	// Get functions
	int getClockMult();
	string getInFile();
};

#endif
