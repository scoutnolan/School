#include <string>
#include <iostream>

template<typename TypeOne, typename TypeTwo>
void AddAndPrint(TypeOne varOne, TypeTwo varTwo)
{
    std::cout << varOne + varTwo << std::endl;
}

int main()
{
    AddAndPrint(1.0, 2);
    // Output: 3

    AddAndPrint(1.1, 2);
    // Output: 3.1

    AddAndPrint(1.2, "Hello!");
    // Output: ?
}

