#include "Shape.hpp"
#include <string>

#ifndef Triangle_HPP
#define Triangle_HPP

using namespace::std;
class Triangle : public Shape
{

private:
    float base;
    float height;
    float side;

public:

    Triangle(float b, float h, float s);

    void CalcArea();
    void CalcPerimeter();

    float GetBase();
    float GetHeight();
    float GetSide();
};


#endif // Triangle_HPP