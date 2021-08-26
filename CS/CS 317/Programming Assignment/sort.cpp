//  ************************************************************** //
//  Author:         Nolan Anderson
//  Course:         CS317-03, Fall 2020
//  File:           sort.cpp
//  Input:          A variety of text files that contain n lines.
//  Output:         out.txt, sorts the input files lines alphabetically.
//  Description:    This file implements quicksort and mergesort and outputs the 
//                  final sorted array to output files. 
//  Compile:        g++ sort.cpp -std=c++11 -o sort
//  Execution:      ./sort
//  ************************************************************** //
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <chrono>
using namespace std;
using namespace std::chrono;

// QuickSort Function Declarations
void QuickSort(string inarray[], int l, int r);         // Quicksort the array input.
void QuickSortOut(string outarray[], int lines);                   // Output the QuickSort sorted array.
static int partition(string inarray[], int l, int r);   // Partition the array.

// MergeSort Function Declarations.
void MergeSort(string inarray[], int l, int r);         // Mergesort the array input.
void Merge(string inarr[], int l, int m, int r);        // Merge the two halves of the array.
void MergeSortOut(string inarray[], int lines);         // Output the MergeSort sorted array.

int arraysize = 200000;                                 // Max size of the array.

int main()
{
    // ******** FILE OPEN AND PARAMETERS ******* //
    string ch;                                          // Read in string from file. 
    int i = 0;                                          // Counter.
    string qarray[arraysize];                           // Array for quick sort (array gets overwritten on function call.)
    string marray[arraysize];                           // Array for merge sort (array gets overwritten on function call.)
    string filename;                                    // Name of file parameter.
	cout << "Enter name of the input file: " << endl;   // Simple cout statement
    cin >> filename;                                    // Input for the file name.
    ifstream InFile(filename.c_str());                  // Create ifstream parameter to get data from the filename.
    // **************************************** //


    // ****** PUT STRINGS INTO ARRAY ******* //
    string FileString;
    while (getline(InFile, FileString)) 
    {   
        qarray[i] = FileString;             // Quick sort array.
        marray[i] = FileString;             // Merge Sort array.
        ++i;
    }
    chrono::time_point<std::chrono::system_clock> QuickStart, QuickEnd;     // Start / end time variables.
    chrono::time_point<std::chrono::system_clock> MergeStart, MergeEnd;     // Start / end time variables. 
    chrono::duration<double> elapsed_seconds;                               // Total time variable.

    // ************ QUICKSORT CALL ************ //
    QuickStart = chrono::system_clock::now();                               // Start time.
    QuickSort(qarray, 0, i);                                                // QuickSort the array.
    QuickEnd = chrono::system_clock::now();                                 // End time.
    elapsed_seconds = QuickEnd - QuickStart;                                // Calculate total time.
    cout << "Time to QuickSort: " << elapsed_seconds.count() << "s\n";      // Output total time.
    // **************************************** //
    QuickSortOut(qarray, i);
    // ************ MERGESORT CALL ************ //
    MergeStart = chrono::system_clock::now();                               // Start time
    MergeSort(marray, 0, i);                                                // MergeSort the array.
    MergeEnd = chrono::system_clock::now();                                 // End time.
    elapsed_seconds = MergeEnd - MergeStart;                                // Calculate total time
    cout << "Time to MergeSort: " << elapsed_seconds.count() << "s\n";      // Output total time. 
    // **************************************** //
    MergeSortOut(marray, i);
    return 0;
}

// ********* QUICK SORT ********* //
// The purpose of this function is to sort the array defined in main using an 
// implementation of Quicksort. The output will be in QuickSort.txt
void QuickSort(string inarray[], int l, int r)  // Quicksort the array input.
{
    int j;
    if (l < r)                                  // If the left side is less than the right... Keep going, not sorted.
    {
        j = partition(inarray, l, r);           // j is now a partition of inarray of left and right portions of the array.
        QuickSort(inarray, l, j - 1);           // Quicksort the inarray, left side and partition - 1.
        QuickSort(inarray, j + 1, r);           // Quicksort the right side and parition + 1.
    }
}
// ****************************** //

// ******* PARTITION ****** //
// The purpose of this function is to partition the array and increment i and j along the array
// and compare to the pivot and do the proper swaps.
static int partition(string inarray[], int l, int r)
{
    int pivot = l;          // Pivot starts at the left index.
    int i, j;               // Variable declaration. 
    i = l; j = r + 1;       // increment is equal to left, j is equal to right + 1
    while(1)
    {
        do i++; while(inarray[i].compare(inarray[pivot]) <= 0 && (i < r));  // While the i < pivot, i++ (going up)
        do j--; while(inarray[j].compare(inarray[pivot]) >= 0 && (j > l));  // While the j > pivot, j-- (going down)
        if (i >= j) break;
        inarray[i].swap(inarray[j]);    // Swap the elements.
    }
    inarray[l].swap(inarray[j]);        // Swap the elements.
    return j;
}
// ****************************** //

// ******** OUTPUT ARRAY ******** //
// The purpose of this function is to output the array sorted in QuickSort.
void QuickSortOut(string outarray[], int lines)
{
    string filename;
    cout << "Please enter an output filename for Quick Sort: " << endl;
    cin >> filename;
    ofstream Quick (filename.c_str());              // Create ofstream parameter.
    if (Quick.is_open())                            // If the file is open...
    {
        for(int i = 0; i <= lines; i++)             // For loop to go through the array.
        {
            Quick << outarray[i] << "\n";           // Output each character sorted.
        }
        Quick.close();                              // Close the output file.
    }
    else cout << "Error opening QuickSort out file. ";             // This is for if the output file could not be opened.
}
// ****************************** //

// ********* MERGE SORT ********* //
// The purpose of this function is to sort the array defined in main using an 
// implementation of Mergesort. The output will be in MergeSort.txt
void MergeSort(string inarray[], int l, int r)       // Mergesort the array input.
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(inarray, l, m);       // Sort the left half
        MergeSort(inarray, m + 1, r);   // Sort the right half
        Merge(inarray, l, m, r);        // Merge the two array's.
    }
}
// ****************************** //

// ************ MERGE *********** //
// This function mergers the two array's that were sorted in the MergeSort function.
void Merge(string inarray[], int l, int m, int r)
{
    int LSize = m - l + 1;      // Size of left array.
    int RSize = r - m;          // Size of right array.
    string L[LSize], R[RSize];     // Left and right temp arrays.

    // Here I am creating some temp array's for swapping and incrementing.
    for(int i = 0; i < LSize; i++)
        L[i] = inarray[l + i];
    for(int j = 0; j < RSize; j++)
        R[j] = inarray[m + 1 + j];
    
    
    // Merge the temp arrays back into arr[l..r]
    int i = 0;  // Left array initial index.
    int j = 0;  // Right array initial index. 
    int k = l;  // Merged array initial index.
     
    while (i < LSize && j < RSize)  // While walking through is less than the size of the two arrays...      
    {
        if (L[i] <= R[j])           // If the left array is less than the right array.
        {
            inarray[k].swap(L[i]);
            i++;                    // Increment i.
        }
        else                        // Right array is greater than left array.
        {
            inarray[k].swap(R[j]);  // Swap the elements.
            j++;                    // Increment j.
        }
        k++;                        // Increment k.
    }
    // Once we get to the end of the array's we stop.
 
    // Copy over remaining elements.
    while (i < LSize) 
    {
        inarray[k].swap(L[i]);      // Swap elements.
        i++;
        k++;
    }
    // Copy over remaining elements. 
    while (j < RSize)
    {
        inarray[k].swap(R[j]);      // Swap elements.
        j++;
        k++;
    }
}
// ****************************** //

// ******** OUTPUT ARRAY ******** //
// The purpose of this function is to output the array sorted in MergeSort.
void MergeSortOut(string outarray[], int lines)
{
    string filename;
    cout << "Please enter an output filename for Merge Sort: " << endl;
    cin >> filename;
    ofstream Merge (filename.c_str());              // Create ofstream parameter.
    if (Merge.is_open())                            // If the file is open...
    {
        for(int i = 0; i <= lines; i++)             // For loop to go through the array.
        {
            Merge << outarray[i] << "\n";           // Output each character sorted.
        }
    }  
    else cout << "Error opening MergeSort out file. ";             // This is for if the output file could not be opened.
    Merge.close();
}
// ****************************** //