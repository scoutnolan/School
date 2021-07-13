#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


struct Location
{
    float x, y;
};

class Rectangle
{
	// base constructor
private:
    Location location; // structure that contains 2 floats
    float length;      
    float width;

public:

    Rectangle();
    Rectangle(float x, float y, float l, float w);

    Location GetLocation();
    float GetLength();
    float GetWidth();
};


#endif // RECTANGLE_HPP
