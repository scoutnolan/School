/*------------------------------------------------------------------------------
* Student:      Nolan Anderson
* Program:      Lab_2_1.c
* Date:         Aug 21, 2121
* Input:        None
* Output:       Prints the sizes of common c data types
* Description:  This c program prints the sizes and ranges of common data types:
*               char, short int, int, long int, long long int, unsigned char,
*               unsigned short int, unsigned int, unsigned
                long int, unsigned long long int, float, and double.
*-----------------------------------------------------------------------------*/
#include <msp430.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD;                               // Stop WatchDogTimer
    int unsignedmin = 0;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| Data Type              |    Size (in bytes)    | Minimum             | Maximum              |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| char                   | %d                     |%-21hhi| %-21hhi|\n", CHAR_BIT, SCHAR_MIN, SCHAR_MAX);
    printf("| short int              | %d                     |%-21hd| %-21hd|\n", sizeof(short int),                   SHRT_MIN, SHRT_MAX);
    printf("| int                    | %d                     |%-21d| %-21d|\n", sizeof(int),                         INT_MIN, INT_MAX);
    printf("| long int               | %d                     |%-21ld| %-21ld|\n", sizeof(long int),                    LONG_MIN, LONG_MAX);
    printf("| long long int          | %d                     |%-21lld| %-21lld|\n", sizeof(long long int),               LLONG_MIN, LLONG_MAX);
    printf("| unsigned char          | %d                     |%-21hhu| %-21hhu|\n", sizeof(unsigned char),               CHAR_MIN, UCHAR_MAX);
    printf("| unsigned short int     | %d                     |%-21hu| %-21hu|\n", sizeof(unsigned short int),          unsignedmin, USHRT_MAX);
    printf("| unsigned int           | %d                     |%-21u| %-21u|\n", sizeof(unsigned int),                unsignedmin, UINT_MAX);
    printf("| unsigned long int      | %d                     |%-21u| %-21lu|\n", sizeof(unsigned long int),           unsignedmin, ULONG_MAX);
    printf("| unsigned long long int | %d                     |%-21u| %-21llu|\n", sizeof(unsigned long long int),      unsignedmin, ULLONG_MAX);
    printf("| float                  | %d                     |%-21g| %-21g|\n", sizeof(float),                       FLT_MIN, FLT_MAX);
    printf("| double                 | %d                     |%-21g| %-21g|\n", sizeof(double),                      DBL_MIN, DBL_MAX);
    printf("-----------------------------------------------------------------------------------------------\n");
    return 0;
}
