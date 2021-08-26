/*------------------------------------------------------------------------------
* Student:      Nolan Anderson
* Program:      Calculate the first 10 products of an integer
* Date:         Aug 20, 2020
* Input:        None
* Output:       A multiplication table of the first 10 products of a predetermined number.
* Description:  This C Program takes an integer variable and sends it to the function
*               print_multiplication_table() and outputs the first 10 products of that
*               integer. The integer is predetermined and no need for input.
*-----------------------------------------------------------------------------*/
#include <msp430.h>
#include <stdio.h>

// Function prototype
void print_table(int);

int main()
{
    WDTCTL = WDTPW + WDTHOLD;
    int a = 5;                              // delcaring a number to be multiplied by
    print_table(a);                 // function call
}
void print_table(a)
{
    int b;                              // temp variable to multiply
    int i;                              // for loop counter
    for(i = 1; i < 11; i++)             // For loop to run through each number to be multiplied
    {
        b = i*a;                    // multiply the number by i
        printf("%d X %d = %d \n", a, i, b); // output the data using print f
    }
}
