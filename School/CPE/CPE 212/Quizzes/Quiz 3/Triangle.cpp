// Nolan Anderson

#include "Shape.hpp"
#include "Triangle.hpp"
#include <string>
using namespace::std;


// Triangle constructor
Triangle::Triangle(float b, float h, float s){
    base = b;
    height = h;
    side = s;
}

// Returning the base of the triangle
float Triangle::GetBase(){
    return base;
}


// Returning the height of the triangle
float Triangle::GetHeight(){
    return height;
}


// Returning the side of the triangle
float Triangle::GetSide(){
    return side;
}


// Calculating the area of the triangle
void Triangle::CalcArea(){
    Shape::SetArea(height*base / 2);
}


// Calculating the perimeter of the triangle
void Triangle::CalcPerimeter(){
    Shape::SetPerimeter((side*2) + base);
}