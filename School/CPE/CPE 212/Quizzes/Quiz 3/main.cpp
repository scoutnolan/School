#include "Triangle.hpp"

#include <iostream>

int main()
{
    Triangle t(12.0, 6.0, 12.0);

    if(t.GetBase() != 12.0)
    {
        std::cout << "Base is incorrect" << std::endl;
        return -1;
    }

    if(t.GetHeight() != 6.0)
    {
        std::cout << "Height is incorrect" << std::endl;
        return -1;
    }

    if(t.GetSide() != 12.0)
    {
        std::cout << "Side is incorrect" << std::endl;
        return -1;
    }

    // Calculate Area
    t.CalcArea();
    // Calculate Perimeter
    t.CalcPerimeter();

    if (t.GetArea() != 36.0) {
        std::cout << "Area is incorrect" << std::endl;
        return -1; 
    }

    if (t.GetPerimeter() != 36.0) {
        std::cout << "Perimeter is incorrect" << std::endl;
        return -1; 
    }


    std::cout << "Implementation is correct!" << std::endl;
}