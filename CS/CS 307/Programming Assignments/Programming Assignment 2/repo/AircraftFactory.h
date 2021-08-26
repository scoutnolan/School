// ****************************************
// Program Title: Project2
// Project File: AircraftFactory.h
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************
#include "AircraftData.h"
#include "AircraftTypes.h"
#include <time.h>		// needed for other time functions and structures
#include <string>
#include <limits>
using namespace std;

//=================================
// AircraftFactory.h
//=================================

class AircraftFactory {
public:
	AircraftFactory();
	~AircraftFactory();
	virtual Aircraft getAircraft();
};

class Business : public AircraftFactory {
public:
	Business();
	~Business();
	virtual Aircraft getAircraft();
};

class Passenger : public AircraftFactory {
public:
	Passenger();
	~Passenger();
	virtual Aircraft getAircraft();
};

class Single : public AircraftFactory {
public:
	Single();
	~Single();
	virtual Aircraft getAircraft();
};