/*------------------------------------------------------------------------------
* Student:      Nolan Anderson
* Program:      Lab_2_3.c
* Date:         Aug 21, 2121
* Input:        None
* Output:       Takes the dot product of two minimum 5 element arrays
* Description:  This program takes in two input arrays and performs a dot
*               product of the two. Then it outputs the dot product of the two
*               array's.
*-----------------------------------------------------------------------------*/
#include <msp430.h>
#include <stdio.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD;
    int array[] = {-1, 2, 5, 3, -5, 6};                 // First array
    int array2[] = {-7, 8, 23, 13, 23, 28};             // Second Array
    int product = 0;                                    // Product initializer
    int i = 0;                                          // Loop Initializer
    printf("Input Array X: [");                         // Printing out first statement
    for(i = 0; i < 6; i++)                              // Loop through the values
    {
        product = product + array[i] * array2[i];       // Perform the dot product on the two arrays
        printf(" %d", array[i]);                        // Output first array values
    }
    printf("]\nInput Array Y: [");                      // Output start for second array
    for(i = 0; i < 6; i++)
    {
        printf(" %d", array2[i]);                       // Output values for second array
    }
    printf("]\nDot product is: %d", product);           // Last line to output product.
    return 0;
}
