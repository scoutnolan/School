#include <string>
#include <iomanip>
#include <iostream>
using namespace::std;

int main(){
int   beta;     // Normal int variable
int*  somePtr;  // Pointer declaration
float* someptr2;
cout << "Some pointer: " << somePtr << endl;
somePtr = &beta;    // Address-of operator &
cout << "Some pointer assigned to beta: " << somePtr << endl;
// int* somePtr = &beta; gives same result

beta = 15;      // Direct addressing

cout << "beta value: " << beta << endl;

*somePtr = 22;  // Indirect addressing
           // using dereference op *

cout << "beta value again: " << beta << endl;

cout << somePtr << endl;  // Prints 4000
cout << *somePtr << endl; // Prints 22
cout << &somePtr << endl; // Prints 1500

// More Pointer Questions…
(*somePtr)++;   // Increments the variable by one
cout << somePtr << endl;  // Prints 4000
cout << *somePtr << endl; // Prints 23
cout << &somePtr << endl; // Prints 1500

somePtr++;      // Be very careful here!!!
// The compiler knows that somePtr points to an integer value
// So, the compiler generates the machine language code that
// implements the following calculation
// somePtr = somePtr + sizeof(int);
cout << somePtr << endl;  // Prints 4004
cout << "Value of someptr: " << *somePtr << endl;
int arr[] = {4,5,6,7};
int* p = (arr+1);
cout << *arr+10 << endl;
int *ptr;
cout << *ptr << endl;
int numbers[] = {0,1,2,3,4};
//int* ptr = numbers;
//ptr++;
//cout << *ptr << endl;

int number = 22;
int *var = &number;
cout << *var << endl;
int num1;
cout << &num1 << endl;

//int *ptr;
//cout << *ptr << endl;





int alpha = 0;
cout << alpha << endl;
int *betaptr;
*betaptr = 10;
cout << alpha << endl;
cout << betaptr << endl;
}




/*int myArray[10]; // int array variable
//int* arrayptr;   // pointer declaration


// arrayptr = &myArray[0];
int *arrayptr = myArray;

void somefunc(int somearray[]){
    myArray[0] = 4;
}

void somefunctwo(int* myArray){
    myArray[0] = 4;
}*/




