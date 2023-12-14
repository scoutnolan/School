// ****************************************
// Program Title: Project2
// Project File: FlightData.cpp
// Name: Nolan Anderson
// Course: CS-307
// Due Date: 04/25/2021
// ****************************************
#include "FlightData.h"
#pragma warning(disable : 4996)

Flight::Flight(){}

Flight::Flight(char* al, char* plane, int flNum, char* depCity, int depHr, int depMin, char* dstCity, int AMin, int AHr, int it)
{
	strcpy(airline, al);
	strcpy(aircraftType, plane);
	this->flightNumber = flNum;
	strcpy(departCity, depCity);
	this->departTimeHr = depHr;
	this->departTimeMin = depMin;
	this->arrHr = AHr;
	this->arrMin = AMin;
	strcpy(arriveCity, dstCity);
	this->index = it;
}

Flight::~Flight(){}

Flight *getInstance()
{
	static Flight *instance = NULL;
	if (instance == NULL)
	{
		instance = new Flight();
	}
	return instance;
}

void Flight::readData(char* infile)
{
	FlightDataParser *ParseFlight = ParseFlight->getInstance();
	ParseFlight->getInstance();
	ParseFlight->InitFlightData(infile);
	const int FlightCount = ParseFlight->getFlightCount();
	for (int i = 0; i < FlightCount; i++)
	{
		ParseFlight->getFlightData(airline, aircraftType, &flightNumber, departCity, &departTimeHr, &departTimeMin, arriveCity);
		Flight* NewFlight = new Flight(airline, aircraftType, flightNumber, departCity, departTimeHr, departTimeMin, arriveCity, arrMin, arrHr, index);
		FlightList.push_back(*NewFlight);
	}
	ParseFlight->getStartTime(&StartHr, &StartMin);
}

vector<Flight> Flight::ReturnFlightVector()
{
	return this->FlightList;
}

double Flight::CurrentLat(double lat1, double lat2, double elapsedTime, double TripTime)
{
	return lat1 + (lat2 - lat1) * (elapsedTime / TripTime);
}

double Flight::CurrentLon(double lon1, double lon2, double elapsedTime, double TripTime)
{
	return lon1 + (lon2 - lon1) * (elapsedTime / TripTime);
}

double Flight::CurrentAlt(double elapsedMin, double ROC)
{
	return elapsedMin / ROC;
}

void Flight::setFlightNumber(int param)
{
	this->flightNumber = param;
}

void Flight::setDepartTimeMin(int param)
{
	this->departTimeMin = param;
}

void Flight::setDepartTimeHr(int param)
{
	this->departTimeHr = param;
}

void Flight::setAirline(char param)
{
	*this->airline = param;
}

void Flight::setAircraftType(char param)
{
	*this->aircraftType = param;
}

void Flight::setDepartCity(char param)
{
	*this->departCity = param;
}

void Flight::setArriveCity(char param)
{
	*this->arriveCity = param;
}

int Flight::getFlightNumber()
{
	return this->flightNumber;
}

int Flight::getDepartMin()
{
	return this->departTimeMin;
}

int Flight::getDepartHour()
{
	return this->departTimeHr;
}

char* Flight::getAirline()
{
	return this->airline;
}

char* Flight::getAircraftType()
{
	return this->aircraftType;
}

char* Flight::getDepartCity()
{
	return this->departCity;
}

char* Flight::getArriveCity()
{
	return this->arriveCity;
}

int Flight::getStartMin()
{
	return this->StartMin;
}

int Flight::getStartHr()
{
	return this->StartHr;
}

void Flight::setArrMin(int param)
{
	this->arrMin = param;
}

void Flight::setArrHr(int param)
{
	this->arrHr = param;
}

int Flight::getArrHr()
{
	return this->arrHr;
}

int Flight::getArrMin()
{
	return this->arrMin;
}

void Flight::SetIndex(int param)
{
	this->index = param;
}

int Flight::getIndex()
{
	return this->index;
}