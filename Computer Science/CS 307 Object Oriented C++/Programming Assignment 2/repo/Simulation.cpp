// ****************************************
// Program Title: Project2
// Project File: Simulation.cpp
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************
#pragma warning(disable : 4996)

#include "Simulation.h"

Simulation::Simulation(){}

Simulation::~Simulation(){}

void Simulation::initializeSimulation()
{
	printf("==============================================================\n");
	printf("|          AIRLINE FLIGHT SIMULATION DEMONSTRATION           |\n");
	printf("|            CS 307 -- Programming Assignment 2              |\n");
	printf("==============================================================\n");
	printf("\nPlease enter the name of the simulation data file\n");
	getline(cin, inputFile);
	char* inFileCharArray = &inputFile[0];
	ifstream userInFile(inFileCharArray);
	string cityFile, flightFile;
	char myCityFile[32];
	char myFlightFile[32];

	if (!userInFile)
	{
		cout << "Error opening file: " << inputFile << endl;
		cout << "Terminating program" << endl;
		exit(1);
	}
	else
	{
		cout << "Successfully opened file " << inputFile << endl;
		getline(userInFile, cityFile);
		getline(userInFile, flightFile);
		cout << "Opened City file " << cityFile << "..." << endl;
		cout << "Opened Airline/Flight file " << flightFile << "..." << endl;

		string temp1 = "../" + cityFile;
		string temp2 = "../" + flightFile;
		strcpy(myCityFile, temp1.c_str());
		strcpy(myFlightFile, temp2.c_str());

		cout << "Starting the simulation." << endl;
	}
	printf("\nWhat speed do you want to run the simulation? (1, 2, or 3)\n");
	cin >> clockMult;
	if (clockMult > 3 || clockMult < 1)
	{
		cout << "Error!! Invalid simulation speed" << endl;
		cout << "Exiting program now..." << endl;
		exit(2);
	}

	// Start with default values
	testCity = new City();
	testFlight = new Flight();
	testAircraft = new Aircraft();

	//City *testCity = testCity->getInstance();
	//Flight *testFlight = testFlight->getInstance();
	//Aircraft *testAircraft = testAircraft->getInstance();


	// Then read in the data
	testCity->readData(myCityFile);
	testFlight->readData(myFlightFile);
	testAircraft->readData(myFlightFile);

	// Get start time
	CurrentHr = testFlight->getStartHr();
	CurrentMin = testFlight->getStartMin();
	PrintStartTime();
}

void Simulation::runSimulation(double clocktime)
{
	_ftime_s(&tStruct);
	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); 
	outputTime = thisTime + 1.0 / clocktime; 
	vector<Flight> InAir;
	vector<Flight> Flights = testFlight->ReturnFlightVector();
	vector<Aircraft> Airplanes = testAircraft->ReturnAircraftList();
	vector<City> Cities = testCity->ReturnCityVector();
	bool finished = false;
	while (!finished) 
	{
		_ftime_s(&tStruct); 
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); 
		if (thisTime >= outputTime)
		{
			// Output a new flight.
			for (auto& it : Flights)
			{
				int tempHr = it.getDepartHour();
				int tempMin = it.getDepartMin();
				if (CurrentHr == tempHr && CurrentMin == tempMin)	// Find the time
				{
					PrintNewFlights(*testAircraft, *testCity, it, CurrentHr, CurrentMin);
					Flight NewInAir(it.getAirline(), it.getAircraftType(), it.getFlightNumber(), it.getDepartCity(), it.getDepartHour(), it.getDepartMin(), it.getArriveCity(), it.getArrMin(), it.getArrHr(), it.getIndex());
					InAir.push_back(NewInAir);
					NewInAir.setArrHr(CalcETAHr(it, *testAircraft, *testCity, CurrentHr, CurrentMin));
					NewInAir.setArrMin(CalcETAMin(it, *testAircraft, *testCity, CurrentHr, CurrentMin));
				}
			}

			CurrentMin += 1;
			Counter += 1;


			// Increment time.
			if (CurrentMin >= 60)		// Check for minute overflow
			{
				CurrentHr += 1;
				if (CurrentHr == 13)	// Check for hour overflow
				{
					CurrentHr = 1;
				}
				CurrentMin = 0;
			}
			outputTime += 1.0 / clocktime; // Set time for next 1 second interval



			// Output all current flights.
			if ((Counter % 5) == 0)
			{
				printf("\n\n================================================================\n");
				printf("|  Flight Simulation - Status reports on all flights enroute.  |\n");
				printf("================================================================\n");
				for (auto& all : InAir)
				{
					PrintAllFlights(*testAircraft, *testCity, all, CurrentHr, CurrentMin);
					if (CurrentHr == all.getArrHr() && CurrentMin == all.getArrMin())
					{
						InAir.erase(InAir.begin());
					}
				}
				PrintCurrentTime();
				printf("================================================================\n");
			}

			for (auto &it : InAir)
			{
				if (CurrentHr == it.getArrHr() && CurrentMin == it.getArrMin())
				{
					PrintArrival(*testCity, it, CurrentMin, CurrentHr);
					PrintCurrentTime();
					InAir.erase(InAir.begin());
					if (InAir.empty())
					{
						cout << endl << endl << "===============================================" << endl;
						cout <<  "Terminating program, all flights have arrived. " << endl;
						cout << "===============================================" << endl;
						finished = true;
					}
				}
			}

			if (CurrentHr == 12)
			{
				cout << endl << endl << "Terminating program, all flights have arrived but not removed from the list. " << endl;
				cout << "Current location and altitude not calculated. " << endl;
				finished = true;
			}

		}
	}
}

void Simulation::PrintAllFlights(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> AircraftData = A.ReturnAircraftList();								// Vector of Aircraft data
	vector<City> CityData = C.ReturnCityVector();										// Vector of city data
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());			// Distance
	double tempTripTime = 0;
	double tempElapsedTimeHr = CurrentHr - F.getDepartHour();
	double tempElapsedTimeMin = CurrentMin - F.getDepartMin();
	double tempElapsedTime = 0;	double tempSpeed = 0;
	int tempHour = 0;	int tempMin = 0;
	printf("%s Flight %d - %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());

	// Time of flight calculation
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempTripTime = C.TripTime(tempDistance, it.getCruiseSpeed());
			tempSpeed = it.getCruiseSpeed();
		}
	}

	// Arrives at...
	for (auto& it : CityData)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\tArrives: %s (%.2f, %.2f) at", it.getSymbol(), it.getLatitude(), it.getLongitude());
		}
	}

	// Time of flight calculation
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}
	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));


	if ((F.getDepartHour() + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = F.getDepartHour() + hours;
	}
	if ((F.getDepartMin() + min) >= 60) {
		tempMin = (F.getDepartMin() + min) - 60;
		tempHour++;
	}
	else {
		tempMin = F.getDepartMin() + min;
	}

	if (tempHour <= 9 && tempMin <= 9) { printf(" %0d:%0d\n", tempHour, tempMin); }
	else if (tempHour <= 9 && tempMin >= 10) { printf(" %0d:%d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin <= 9) { printf(" %d:%0d\n", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin >= 10) { printf(" %d:%d\n", tempHour, tempMin); }

	tempElapsedTime = tempElapsedTimeHr + tempElapsedTimeMin;

	double DFS = C.DistFromStart(tempDistance, tempTripTime, tempElapsedTime);
	double DTD = C.DistToDst(DFS, tempDistance);
	printf("\t\tCurrent location: \n"); // double // double // DOES NOT WORK
	printf("\t\t\t\t%.2f miles from %s, %.2f miles to %s\n", DFS, F.getDepartCity(), DTD, F.getArriveCity()); // double // char // double // char


	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			printf("\t\tCurrent Speed: %.2f MPH\n", it.getCruiseSpeed());
		}
	}
	for (auto& it : AircraftData)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			printf("\t\tCurrent Altitude: %.2f Feet\n", it.getCruiseAltitude());
		}
	}
}

void Simulation::PrintNewFlights(Aircraft A, City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("now departing: %s flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> tempCity = C.ReturnCityVector();
	vector<Aircraft> tempAircraft = A.ReturnAircraftList();
	for (auto& it : tempCity)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)	// if the symbol is equal to the departure city symbol
		{
			printf("\t\tfrom %s, %s\n", it.getName(), it.getState());
		}
	}
	for (auto& it : tempCity)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)
		{
			printf("\t\ten route to %s, %s\n", it.getName(), it.getState());
		}
	}

	int tempHour = CalcETAHr(F, A, C, CurrentHr, CurrentMin);
	int tempMin = CalcETAMin(F, A, C, CurrentHr, CurrentMin);

	if (tempHour <= 9 && tempMin <= 9) { printf("\t\tEstimated Time of Arrival: %0d:0%d", tempHour, tempMin); }
	else if (tempHour <= 9 && tempMin >= 10) { printf("\t\tEstimated Time of Arrival: %0d:%d", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin <= 9) { printf("\t\tEstimated Time of Arrival: %d:0%d", tempHour, tempMin); }
	else if (tempHour >= 10 && tempMin >= 10) { printf("\t\tEstimated Time of Arrival: %d:%d", tempHour, tempMin); }
	PrintCurrentTime();
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

}

void Simulation::PrintArrival(City C, Flight F, int CurrentHr, int CurrentMin)
{
	printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Now arriving: %s Flight %d, %s\n", F.getAirline(), F.getFlightNumber(), F.getAircraftType());
	vector<City> temp = C.ReturnCityVector();
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getArriveCity()) == 0)	// if the symbol is equal to the departure city symbol
		{
			printf("\t\tAt %s, %s\n", it.getName(), it.getState());
		}
	}
	for (auto& it : temp)
	{
		if (strcmp(it.getSymbol(), F.getDepartCity()) == 0)
		{
			printf("\t\tfrom %s, %s\n", it.getName(), it.getState());
		}
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void Simulation::PrintCurrentTime()
{
	if (CurrentHr <= 9 && CurrentMin <= 9) { printf("\nCurrent clock time: %0d:0%d\n", CurrentHr, CurrentMin); }
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("\nCurrent clock time: %0d:%d\n", CurrentHr, CurrentMin); }
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("\nCurrent clock time: %d:0%d\n", CurrentHr, CurrentMin); }
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("\nCurrent clock time: %d:%d\n", CurrentHr, CurrentMin); }
}

void Simulation::PrintStartTime()
{
	if (CurrentHr <= 9 && CurrentMin <= 9) { printf("*** Starting simulation at 0%d:0%d ***\n", CurrentHr, CurrentMin); }
	else if (CurrentHr <= 9 && CurrentMin >= 10) { printf("*** Starting simulation at 0%d:%d ***\n", CurrentHr, CurrentMin); }
	else if (CurrentHr >= 10 && CurrentMin <= 9) { printf("*** Starting simulation at %d:0%d ***\n", CurrentHr, CurrentMin); }
	else if (CurrentHr >= 10 && CurrentMin >= 10) { printf("*** Starting simulation at %d:%d ***\n", CurrentHr, CurrentMin); }
}

void Simulation::setClockMult(int param)
{
	this->clockMult = param;
}

int Simulation::getClockMult()
{
	return this->clockMult;
}

int Simulation::CalcETAMin(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> tempAircraft = A.ReturnAircraftList();
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());			// Distance
	double tempSpeed = 0;
	int tempHour = 0;
	int tempMin = 0;

	// Time of flight calculation
	for (auto& it : tempAircraft)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));
	if ((CurrentHr + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = CurrentHr + hours;
	}
	if ((CurrentMin + min) >= 60) {
		tempMin = (CurrentMin + min) - 60;
		tempHour++;
	}
	else
	{
		tempMin = CurrentMin + min;
	}
	return tempMin;
}

int Simulation::CalcETAHr(Flight F, Aircraft A, City C, int CurrentHr, int CurrentMin)
{
	vector<Aircraft> tempAircraft = A.ReturnAircraftList();
	double tempDistance = C.calcDistance(F.getDepartCity(), F.getArriveCity());			// Distance
	double tempSpeed = 0;
	int tempHour = 0;
	int tempMin = 0;
	// Time of flight calculation
	for (auto& it : tempAircraft)
	{
		if (strcmp(F.getAircraftType(), it.getMake()) == 0)
		{
			tempSpeed = it.getCruiseSpeed();
		}
	}

	double eta = (tempDistance / tempSpeed);
	int hours = int(floor(eta));
	double temp = eta - floor(eta);
	int min = int(round(temp * 60));
	if ((CurrentHr + hours) >= 24) {
		tempHour = 0;
	}
	else
	{
		tempHour = CurrentHr + hours;
	}
	if ((CurrentMin + min) >= 60) {
		tempMin = (CurrentMin + min) - 60;
		tempHour++;
	}
	else
	{
		tempMin = CurrentMin + min;
	}
	return tempHour;
}