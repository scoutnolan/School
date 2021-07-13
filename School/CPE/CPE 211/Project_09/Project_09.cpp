// ****************************
// Project Title: Project 09
// Project File: Project_09.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 9/04/2019
// program description: Reads in file and makes an array and performs operations on the array
// What the program does
// ****************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

// /home/work/cpe211/Executables/Project_09/Project_09_solution
// /home/work/cpe211data/Project_09/CompareSolution.bash Project_09.cpp

// ********** Function Declarations ********** //

int OpenInputFile(ifstream& input);
int ReadFile(ifstream& input, float[], int);
float Average_func(float[], int);
float Median_func(float[], int);
float Var_func(float[], int, float);
void SortLowHigh(float[], int);

// ********** Main ********** //

int main()
{
    int int_num;
    ifstream InFile;
    int_num = OpenInputFile(InFile);                    // finding needed the size of the array
    float array[int_num];                               // array with proper array size
    //ReadFile(InFile, array, int_num);                   // reading the values from the file into the array
    if(ReadFile(InFile, array, int_num) == 0)
        return 1;
    SortLowHigh(array, int_num);                        // sorts the numbers from low to high
    float average = Average_func(array, int_num);       // average of the array
    float median = Median_func(array, int_num);         // median of the array
    float variance = Var_func(array, int_num, average); // variance of the array
    
    if (int_num == -1)
    {
        return false;
    }
    
    // ********** OUTPUT ********** //
    
    cout << endl << string(15,'*') << " File Statistics " << string(15,'*') << endl;
    cout << string(47, '*') << endl;
    cout << left << setw(25) << setfill('.') << "Number of Values" << setfill('.') << int_num << endl;
    cout << left << setw(25) << "Average" << setfill('.') << average << endl;
    cout << left << setw(25) << "Median" << setfill('.') << median << endl;
    cout << left << setw(25) << "Variance" << setfill('.') << variance << endl;
    cout << left << setw(25) << "Standard Deviation" << sqrt(variance) << endl;
    cout << string(47,'*') << endl << endl;
	return 0;
}

// ********** FUNCTIONS ********** //

// ********** Open File ********** //

int OpenInputFile(ifstream& input)
{
    string inFile; // declaring inFile name for input
    cout << endl;
    cout << "Enter the name of the input file (ctrl-c to exit): ";
    cin >> inFile;
    cout << inFile << endl; // echo print the infile name
    input.open(inFile.c_str());
    while (input.fail()) // if the file does not open then ask for a new input file until a good one is submitted.
    {
        input.clear(); // clears the input file stream
        cout << endl;
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> " << " Input file could not be opened." << endl;
        cout << "==>  " << inFile << " is an invalid file!!" << endl;
        cout << "==> " << " Try Again." << endl;
        cout << string(47,'*') << endl;
        cout << endl;
        cout << "Enter the name of the input file (ctrl-c to exit): ";
        cin >> inFile;
        cout << inFile << endl;
        input.open(inFile.c_str());
    }
    int int_num;
    input >> int_num;
    if (input.eof() == true)
    {
        cout << endl << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
        cout << "==> Input file is empty." << endl;
        cout << "==> Program terminated." << endl;
        cout << string(47,'*') << endl << endl;
        return -1;
    }
    if (input.fail())
    {
        cout << endl << string(15,'*') << " File Read Error " << string(15,'*') << endl;
        cout << "==> Error occurred reading the number of values" << endl;
        cout << "==> present in the input file." << endl;
        cout << "==> Program terminated." << endl;
        cout << string(47,'*') << endl << endl;
        return -1;
    }
    return int_num;
}

// ********** Floating Point ********** //

int ReadFile(ifstream& input, float array[], int int_num)
{
    for (int i = 0; i < int_num; i++)
    {
        input >> array[i];
        if (input.eof())
        {
            cout << endl << string(15,'*') << " File Read Error " << string(15,'*') << endl;
            cout << "==> Error occurred trying to reading in number #" << i+1 << endl;
            cout << "==> Number was not present in the input file." << endl;
            cout << "==> Program terminated." << endl;
            cout << string(47,'*') << endl << endl;
            return 0;
        }
        if (input.fail())
        {
            cout << endl << string(15,'*') << " File Read Error " << string(15,'*') << endl;
            cout << "==> Error occurred reading in number #" << i+1 << endl;
            cout << "==> Invalid Character found in file." << endl;
            cout << "==> Program terminated." << endl;
            cout << string(47,'*') << endl << endl;
            return 0;
        }
    }
    return 1;
}

// ********** SORT LOW TO HIGH ********** //

void SortLowHigh(float array[], int int_num)
{
    float temp;
    for(int i = 0; i < int_num-1; i++)
    {
        for(int j = i+1; j < int_num; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}



// ********** Average ********** //

float Average_func(float array[], int int_num)
{
    float sum = 0;
    for (int x = 0; x < int_num; ++x)
    {
        sum += array[x];
    }
    return sum /(float)int_num;
}



// ********** Median ********** //

float Median_func(float array[], int int_num)
{
    float median;
    if (int_num%2 == 0) // even
    {
        median = (array[((int_num-1)/2)] + array[(int_num/2)])/2.0;
    }
    else
    {
        median = array[(int_num/2)];// remainder of one, odd numer of
    }
    return median;
}



// ********** Variance ********** //

float Var_func(float array[], int int_num, float average)
{
    double sqDiff = 0;
    for (int i = 0; i < int_num; i++)
        sqDiff += (array[i] - average) *
        (array[i] - average);
    return sqDiff / int_num;
}
