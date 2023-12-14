// ****************************************
// Program Title: Project2
// Project File: AircraftData.cpp
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************
#include "AircraftData.h"
Aircraft::Aircraft(){}
Aircraft::~Aircraft() {}

Aircraft::Aircraft(AircraftType AType, char* planemake, char* desc, double roc, double wngs, double len, double cs, double ca)
{
	strcpy(make, planemake);
	strcpy(model, desc);
	this->Type = AType;
	this->cruiseSpeed = cs;
	this->cruiseAltitude = ca;
	this->climbSpeed = roc;
	this->wingspan = wngs;
	this->fuselageLength = len;
}

Aircraft *getInstance()
{
	static Aircraft *instance = NULL;
	if (instance == NULL)
	{
		instance = new Aircraft();
	}
	return instance;
}

void Aircraft::readData(char* infile)
{
	// Initial Declaration
	FlightDataParser* fdp = FlightDataParser::getInstance();
	int pass = fdp->getAircraftCount(PASSENGERJET);
	int bus = fdp->getAircraftCount(BUSINESSJET);
	int sig = fdp->getAircraftCount(SINGLEENGINE);

	// Run through the factory implementation instead of using the traditional method.
	char make[32]; char desc[32]; double roc; double wngspn; double len; double cspd; double calt;

	while (fdp->getAircraftData(BUSINESSJET, make, desc, &roc, &wngspn, &len, &cspd, &calt))
	{/*cout << "Read in the following aircraft:" << endl;cout << "Make: " << make << endl;cout << "Description: " << desc << endl;cout << "Rate of Climb: " << roc << endl;cout << "Wingspan: " << wngspn << endl;cout << "Length: " << len << endl;cout << "Cruising Speed: " << cspd << endl;cout << "Cruising Altitude: " << calt << endl;*/
		Aircraft NewAircraft(BUSINESSJET, make, desc, roc, wngspn, len, cspd, calt);
		AircraftList.push_back(NewAircraft);
	}

	while (fdp->getAircraftData(PASSENGERJET, make, desc, &roc, &wngspn, &len, &cspd, &calt))
	{/*cout << "Read in the following aircraft:" << endl;cout << "Make: " << make << endl;cout << "Description: " << desc << endl;cout << "Rate of Climb: " << roc << endl;cout << "Wingspan: " << wngspn << endl;cout << "Length: " << len << endl;cout << "Cruising Speed: " << cspd << endl;cout << "Cruising Altitude: " << calt << endl;*/
		Aircraft NewAircraft(PASSENGERJET, make, desc, roc, wngspn, len, cspd, calt);
		AircraftList.push_back(NewAircraft);
	}

	while (fdp->getAircraftData(SINGLEENGINE, make, desc, &roc, &wngspn, &len, &cspd, &calt))
	{/*cout << "Read in the following aircraft:" << endl;cout << "Make: " << make << endl;cout << "Description: " << desc << endl;cout << "Rate of Climb: " << roc << endl;cout << "Wingspan: " << wngspn << endl;cout << "Length: " << len << endl;cout << "Cruising Speed: " << cspd << endl;cout << "Cruising Altitude: " << calt << endl; */
		Aircraft NewAircraft(SINGLEENGINE, make, desc, roc, wngspn, len, cspd, calt);
		AircraftList.push_back(NewAircraft);
	}
}

vector<Aircraft> Aircraft::ReturnAircraftList()
{
	return this->AircraftList;
}

void Aircraft::setMake(char param)
{
	*this->make = param;
}

void Aircraft::setModel(char param)
{
	*this->model = param;
}

void Aircraft::setCruiseSpeed(double param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setCruiseAltitude(double param)
{
	this->cruiseAltitude = param;
}

void Aircraft::setClimbSpeed(double param)
{
	this->climbSpeed = param;
}

void Aircraft::setWingspan(double param)
{
	this->wingspan = param;
}

void Aircraft::setFuselageLength(double param)
{
	this->fuselageLength = param;
}

char* Aircraft::getMake()
{
	return this->make;
}

char* Aircraft::getModel()
{
	return this->model;
}

double Aircraft::getCruiseSpeed()
{
	return this->cruiseSpeed;
}

double Aircraft::getCruiseAltitude()
{
	return this->cruiseAltitude;
}

double Aircraft::getClimbSpeed()
{
	return this->climbSpeed;
}

double Aircraft::getWingspan()
{
	return this->wingspan;
}

double Aircraft::getFuselageLength()
{
	return this->fuselageLength;
}