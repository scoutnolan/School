// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
///Users/nolan
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P10.h"

using namespace std;


// /home/work/cpe211/Executables/Project_10/Project_10_solution
// /home/work/cpe211data/Project_10/CompareSolution.bash   Project_10.cpp
// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT

// ********** Initial Constructor Date ********** //

Date::Date()
{
    //Initialize variables.
    month = 1;
    day = 1;
    year = 1900;
};

// ********** Parametrized date ********** //

Date::Date(int initMonth, int initDay, int initYear)
{
    month = initMonth;
    day = initDay;
    year = initYear;
}

// ********** Parametrized date ********** //

Date::Date(int initMonth, int initYear)
{
    day = 1;
    month = initMonth;
    year = initYear;
}

// ********** Set Date ********** //

void Date::SetDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}


// ********** Increment date func ********** //
void Date::IncrementDate()
{
    day++;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            day = 1;
            month ++;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            month++;
            day = 1;
        }
        
    }
    else if (month > 12)
    {
        year ++;
        month = 1;
    }
    else
    {
        if (day > 28)
        {
            month++;
            day = 1;
        }
    }
}
// ********** Write number format ********** //
void Date::WriteNumberFormat() const
{
    cout << setfill('0');
    cout << setw(2) << right << month << "/" << setw(2) << right << day << "/" << setw(2) << right << year << endl;
    cout << setfill(' ');
}

void Date::WriteNameFormat() const
{
    // Using a switch statement to assign the month
    switch(month)
    {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
    }
    
    cout << " " << day << ", " << year << endl;
}

// ********** Same Date ********** //

bool Date::SameDate(Date d2) const
{
    return(month == d2.month && day == d2.day && year == d2.year);
}

// ********** Before Date ********** //

bool Date::BeforeDate(Date d2) const
{
     return (month < d2.month || month == d2.month && day < d2.day || month == d2.month && day == d2.day && year < d2.year);
}

// ********** After Date ********** //

bool Date::AfterDate(Date d2) const
{
    return (month > d2.month || month == d2.month && day > d2.day || month == d2.month && day == d2.day && year > d2.year);
}

