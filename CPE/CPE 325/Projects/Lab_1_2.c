/*------------------------------------------------------------------------------
* Student:      Nolan Anderson
* Program:      Calculate the number of Lower case, Upper Case, and integer values of a string
* Date:         Aug 20, 2020
* Input:        None
* Output:       A string and its number of lower case, upper case, and integer values
* Description:  This C Program takes reads a string and counts the number of lower case,
*               upper case, and numbers. It outputs the string and the data.
*-----------------------------------------------------------------------------*/
#include <ctype.h>
#include <msp430.h>
#include <stdio.h>
#include <string.h>

int main()
{
    WDTCTL = WDTPW + WDTHOLD;
    char str[] = "String Hello! Welcome to CPE325. It's a great day, isn't it?"; // declare string variable
    int len;                //declare length of string variable
    len = strlen(str);      // get the length of the string using strlen
    int i;                  // declaring initial variables and loop counters
    int lower = 0; int upper = 0; int num = 0; int random = 0;
    for (i = 0; i < len; i++)     // for loop to loop through the string
    {
        if(isupper(str[i]))       // check to see if the data at position i is upper case
        {
            upper = upper + 1;
        }
        if(islower(str[i]))       // check to see if the data at position i is lower case
        {
            lower = lower + 1;
        }
        if(isdigit(str[i]))       // check to see if the data at position i is a digit
        {
            num = num + 1;
        }
        else                            // check to see if the data at position i is a different character
        {
            random = random + 1;
        }
    }
    printf("%s \n", str); // output initial string
    // output the data of the string
    printf("Contains: The string contains %d upper-case and %d lower-case characters and %d digits", upper, lower, num);
    return(0);
}
