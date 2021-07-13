#include "Student.hpp"

#include <iostream>
#include <iomanip>


template<typename Type>
void PrintEqual(const Type &one, const Type &two)
{
    std::cout << std::boolalpha << (one == two) << std::endl;
}

int main()
{
    PrintEqual(1, 2);
    PrintEqual(1, 1);

    Student one("Josh", "Langford", 12345678);
    Student two("Leo", "Langford", 87654321);

    PrintEqual(one, two);
}