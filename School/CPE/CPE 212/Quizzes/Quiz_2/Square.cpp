#include "Square.hpp"
#include <iostream>


Square::Square(float l){
    length = l;
}

float Square::GetLength()
{
    return length;
}


void Square::CalcArea()
{
    Shape::SetArea(length*length);
}

void Square::CalcPerimeter()
{
    Shape::SetPerimeter(length*4);
}

void Square::SetColor(string c)
{
    Shape::SetColor(c);
}