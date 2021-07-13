#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // Hash function that accounts for collisions
    string hash [11];       // initializing two different arrays
    string array [11]; 
    array[0] = "Mia"; 
    array[1] = "Tim";       // Creating an array of different names, in the order of the video.
    array[2] = "Bea";
    array[3] = "Zoe";
    array[4] = "Sue";
    array[5] = "Len"; 
    array[6] = "Moe"; 
    array[7] = "Lou";
    array[8] = "Rae";
    array[9] = "Max";
    array[10] = "Tod";
    // Creating a "empty" array with each string value equal to "empty"
    for (int i = 0; i < 11; i++) 
    {
        hash[i] = "empty"; 
    }
    // for loop for all of the names
    for (int i = 0; i < 11; i++) 
    {
        int sum = 0; 
        int ascii = 0;
        string newarray = array[i]; 
        // here I am finding the ascii equivalent of the name inputted into the array
        for (int i = 0; i < 3; i++) 
        {
            sum = (int)newarray[i]; 
            ascii = ascii + sum; 
        }
        int placement = ascii % 11; 
        // if the location is empty
        if(hash[placement] == "empty") 
        {
            hash[placement] = newarray; // place the value into this place
        }
        // else the string value is not empty
        else 
        {
            int it = placement;         // create a new placement variable
            while(hash[it] != "empty")  // while the value is not empty
            {
                it++;                   // increment the new placement value
            }
            hash[it] = newarray;        // set the value equal to the new array
        }
    }
    // output for tha names and hash value
    for (int i = 0; i < 11; i++) 
    {
        int sum = 0;
        int ascii = 0;
        for (int n = 0; n < 3; n++) 
        {
            sum = (int)hash[i][n];
            ascii = ascii + sum;
        }         
        cout << hash[i] << " - " << ascii << endl;
    }
}

