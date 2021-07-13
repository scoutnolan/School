#include "Shape.hpp"
#include <string>

#ifndef SQUARE_HPP
#define SQUARE_HPP

using namespace::std;
class Square : public Shape
{

private:
    float length;

public:

    Square(float l);

    void CalcArea();
    void CalcPerimeter();

    float GetLength();
    void SetColor(string c);
};


#endif // SQUARE_HPP