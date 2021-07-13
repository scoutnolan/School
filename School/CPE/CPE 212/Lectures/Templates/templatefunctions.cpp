#include <string>
#include <iostream>

void Function(int data);
void Function(float data);
void Function(std::string data);

struct SomeType
{

};

void swap_int(int *one, int *two)
{
    int tmp = *one;
    *one = *two;
    *two = tmp;
}

void swap_float(float *one, float *two)
{
    float tmp = *one;
    *one = *two;
    *two = tmp;
}

template<typename SomeType>
void swap(SomeType *one, SomeType *two)
{
    SomeType tmp = *one;
    *one = *two;
    *two = tmp;

}



template<typename TypeOne, typename TypeTwo>
void AddAndPrint(TypeOne varOne, TypeTwo varTwo)
{
    std::cout << varOne + varTwo << std::endl;
}


int main()
{
    int data[2];
    data[0] = 1;
    data[1] = 20;
    float fData[2];
    fData[0] = 11.11f;
    fData[1] = 22.22f;


    std::cout << data[0] << " " << data[1] << std::endl;

    swap(&data[0], &data[1]);
    swap<float>(&fData[0], &fData[1]);

    std::cout << data[0] << " " << data[1] << std::endl;


    AddAndPrint(1.1, 2);

    AddAndPrint(1.2, "Hello!");

}

// template<typename T>
// void Function(T data);



// template<typename T>
// void Function(T data)
// {
//     // do stuff on T here
// }



// int main()
// {
//     int myInt = 123;
//     int myFloat = 12.3;

// }


