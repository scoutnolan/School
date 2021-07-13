#include <iostream>
#include <string>


int main()
{
    std::string person_array [11]; // create array of people
    std::string hash_array [11]; // create hash array

    person_array[0] = "Mia"; // initializing the character names
    person_array[1] = "Tim";
    person_array[2] = "Bea";
    person_array[3] = "Zoe";
    person_array[4] = "Sue";
    person_array[5] = "Len"; 
    person_array[6] = "Moe"; 
    person_array[7] = "Lou";
    person_array[8] = "Rae";
    person_array[9] = "Max";
    person_array[10] = "Tod";

     for (int i = 0; i < 11; i++) // initialize our hash_array to a sentinel value
     {
        hash_array[i] = "NULL"; // sentinel value, will never have this in input with 3 character names
     }

     for (int i2 = 0; i2 < 11; i2++) // main loop for each character
     {
        int add = 0; // new vars for add and sum for all chars
        int sum = 0;
        std::string temp = person_array[i2]; // holding/modify variable
        for (int i3 = 0; i3 < 3; i3++) // for every letter in their name
        {
            add = (int)temp[i3]; // use (int) to get ASCII value quickly of their name
            sum = sum + add; // make ASCII sum
        }
        int mod = sum % 11; // find mod
        if(hash_array[mod] == "NULL") // if it is unoccupied, awesome. add it in.
        {
            hash_array[mod] = temp;
        }
        else // else it has a person's name in it, so iterate down the list until you find a free spot
        {
            int iterator = mod;
            while(hash_array[iterator] != "NULL")
            {
                iterator++;
            }

            hash_array[iterator] = temp; // and once free spot is found, insert it
        }
        

     }

     for (int i4 = 0; i4 < 11; i4++) // for each character in the hashed array
     {
         int add2 = 0; // new vars
         int sum2 = 0;
        for (int i5 = 0; i5 < 3; i5++) // for each letter, find the ASCII value and add it
        {
            add2 = (int)hash_array[i4][i5];
            sum2 = sum2 + add2;
        }         

        std::cout << hash_array[i4] << " - " << sum2 << std::endl; // cout statement
     }
     
}