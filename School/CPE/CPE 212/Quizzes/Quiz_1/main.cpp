#include "Rectangle.hpp"

#include <iostream>

int main()
{
    Rectangle r(1.0, 2.0, 3.0, 4.0); // class rectangle, populating the class 
    //structure. Going to pass in the (values) into r.

    if(r.GetLength() != 3.0)
    {
        std::cout << "Length is incorrect" << std::endl;
        return -1;
    }

    if(r.GetWidth() != 4.0)
    {
        std::cout << "Width is incorrect" << std::endl;
        return -1;
    }

    Location l = r.GetLocation();
    if(l.x != 1.0)
    {
        std::cout << "Length.X is incorrect" << std::endl;
        return -1;
    }

    if(l.y != 2.0)
    {
        std::cout << "Length.y is incorrect" << std::endl;
        return -1;
    }

    std::cout << "Implementation is correct!" << std::endl;
}