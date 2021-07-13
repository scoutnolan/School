#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "Shape.hpp"

using namespace::std;
class Shape 
{
    private:
        float area, perimeter;
        string color;

    public:
        // Constructor
        Shape();
        
        // Pure virtual functions
        virtual void CalcArea() = 0;
        virtual void CalcPerimeter() = 0;
        

        // Setters
        void SetArea(float a);
        void SetPerimeter(float p);

        // Getters
        float GetArea();
        float GetPerimeter();

};

#endif // SHAPE_HPP