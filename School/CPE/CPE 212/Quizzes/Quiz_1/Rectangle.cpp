#include "Rectangle.hpp"

float GetLocation();
float GetWidth();
float GetLength();

Rectangle::Rectangle(){
	location.x = 0; // location is a private variable
	location.y = 0;
	length = 0; 
	width = 0;
	
}

Rectangle::Rectangle(float x, float y, float l, float w)
{
    // Complete this function, assigning the location, 
    // length and width appropriately.
	location.x = x; // passing in x from the main.cpp Rectangle r(1.0....)
	location.y = y;
	length = l;
	width = w;
}

float GetLocation(float x, float y, float location)
{
	return location;
}


float GetWidth(float length)
{
	return length;
}


float GetLength(float width)
{
	return width;
}



// Declare and complete the final 3 functions
// whenever you declared a member of a function or class
// GetLength function
Location Rectangle::GetLocation() // data type locations // member function
// getlocation
{ // have to associate it with a class (Rectangle)
	// return the location to implement this function
	return location;
	// location 		
}

float Rectangle::GetLength(){ // variable l only makes sense in its scope.
// l does not exist here
	return length;
}

float Rectangle::GetWidth(){
	return width;
}