//******************************************************************
// The following is a partial header comment block.  Modify the
// appropriate parts by putting in your information.  Look at
// the samples handed out to make any necessary additions
// You may delete this line and the three above it.
// Paycheck program
// Ron Bowman
// CPE112-02, L00
// Project due date: ##/##/##
// This program computes an employee's wages for the week
// If an employee works more than 40 hours they get 1.5 times
// their normal pay rate for all hours over 40.
//******************************************************************
// Put all preprocessor directives here
// The following are the necessary header files
#include <iostream> // header file for standard input output 
// add modification  #1 here 

using namespace std;

/* This function calculates the pay in one of two ways */
/* depending on the hours worked			*/
void CalcPay( float, float, float& );

// Global constant declarations
const float MAX_HOURS = 40.0;   // Maximum normal work hours
const float OVERTIME = 1.5;     // Overtime pay rate factor

int main()
{
    float payRate;       // Employee's pay rate
    float hours;         // Hours worked
    float wages;         // Wages earned based on pay rate and hours worked.
    // add modification  #2 here 
    int   empNum;        // Employee ID number

    // prompt for and read in the information for an employee
    // information read is the employee number, their pay rate 
    // and the number of hours they have worked for the week.
    cout << "Enter the employee number: "; 
    cin >> empNum;                          
    cout << "Enter pay rate: ";            
    cin >> payRate;                       
    cout << "Enter hours worked: ";      
    cin >> hours;                       

    CalcPay(payRate, hours, wages);         // call the function that Compute wages

    // output the employee information and the results
    // note how the output statement is broken up into multiple lines so that
    // the cout statement is not too long.

    // add modifications  #3 here.  This modification
    // adds an if statement to calculate regular and overtime pay

    // Modification #4 occurs here
    // This modification changes the cout statement as indicated in
    // the project handout
    cout << "Employee: " << empNum << endl  
         << "Pay rate: " << payRate << endl
         << "Hours: " << hours << endl
         << "Wages: $" << wages << endl;
    return 0;                               // Indicate successful
}                                           //   completion of the program

//******************************************************************
//******************************************************************
//     All function definitions are placed below main
//******************************************************************
//******************************************************************

void CalcPay( /* in */  float  payRate,     // Employee's pay rate
              /* in */  float  hours,       // Hours worked
              /* out */ float& wages )      // Wages earned

// CalcPay computes wages from the employee's pay rate
// and the hours worked, taking overtime into account

{
    if (hours > MAX_HOURS)                     // Is there overtime?
        wages = (MAX_HOURS * payRate) +        // Yes
                (hours - MAX_HOURS) * payRate * OVERTIME;
    else
        wages = hours * payRate;               // No
}
