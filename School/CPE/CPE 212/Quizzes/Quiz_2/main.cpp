#include "Square.hpp"

#include <iostream>

int main()
{
    Square s(6.0);

    if(s.GetLength() != 6.0)
    {
        std::cout << "Length is incorrect" << std::endl;
        return -1;
    }

    // Calculate Area
    s.CalcArea();
    // Calculate Perimeter
    s.CalcPerimeter();

    if (s.GetArea() != 36.0) {
        std::cout << "Area is incorrect" << std::endl;
        return -1; 
    }

    if (s.GetPerimeter() != 24.0) {
        std::cout << "Perimeter is incorrect" << std::endl;
        return -1; 
    }


    std::cout << "Implementation is correct!" << std::endl;
}