// ****************************************
// Program Title: Project2
// Project File: AircraftFactory.
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************

#include "AircraftFactory.h"
AircraftFactory::AircraftFactory() {}
AircraftFactory::~AircraftFactory() {}
Business::Business() {}
Business::~Business() {}
Passenger::Passenger() {}
Passenger::~Passenger() {}
Single::Single() {}
Single::~Single() {}


Aircraft AircraftFactory::getAircraft() {
	FlightDataParser* fdp = FlightDataParser::getInstance();
	char make[32]; char model[32]; double climbSpeed; double wingspan; double fuselageLength; double cruiseSpeed; double cruiseAltitude;
	while (fdp->getAircraftData(NOTYPE, make, model, &climbSpeed, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude))
	{
		Aircraft NewAircraft(NOTYPE, make, model, climbSpeed, wingspan, fuselageLength, cruiseSpeed, cruiseAltitude);
		return NewAircraft;
	}
}

Aircraft Business::getAircraft() {
	FlightDataParser* fdp = FlightDataParser::getInstance();
	char make[32]; char model[32]; double climbSpeed; double wingspan; double fuselageLength; double cruiseSpeed; double cruiseAltitude;
	while (fdp->getAircraftData(BUSINESSJET, make, model, &climbSpeed, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude))
	{
		Aircraft NewAircraft(BUSINESSJET, make, model, climbSpeed, wingspan, fuselageLength, cruiseSpeed, cruiseAltitude);
		return NewAircraft;
	}
}

Aircraft Passenger::getAircraft() {
	FlightDataParser* fdp = FlightDataParser::getInstance();
	char make[32]; char model[32]; double climbSpeed; double wingspan; double fuselageLength; double cruiseSpeed; double cruiseAltitude;
	while (fdp->getAircraftData(PASSENGERJET, make, model, &climbSpeed, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude))
	{
		Aircraft NewAircraft(PASSENGERJET, make, model, climbSpeed, wingspan, fuselageLength, cruiseSpeed, cruiseAltitude);
		return NewAircraft;
	}
}

Aircraft Single::getAircraft() {
	FlightDataParser* fdp = FlightDataParser::getInstance();
	char make[32]; char model[32]; double climbSpeed; double wingspan; double fuselageLength; double cruiseSpeed; double cruiseAltitude;
	while (fdp->getAircraftData(SINGLEENGINE, make, model, &climbSpeed, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude))
	{
		Aircraft NewAircraft(SINGLEENGINE, make, model, climbSpeed, wingspan, fuselageLength, cruiseSpeed, cruiseAltitude);
		return NewAircraft;
	}
}


