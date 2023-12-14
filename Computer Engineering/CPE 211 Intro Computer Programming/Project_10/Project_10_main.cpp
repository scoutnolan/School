// *************************************************************
// main function declaration to run the class funcitons
// DO NOT MODIFY THIS FILE
// **************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P10.h" 

using namespace std;

int main()
{
    cout << endl << string(40,'*') << endl;
    cout << "Number Format:   11/15/2017\n";
    cout << "Name Format: November 15, 2017\n";

    // construct two objects of the class - one using 
    // default date the other using paramertized constructor
    //
    cout << string(40,'*') << endl << endl;
    cout << "Constructor Test\n";
    cout << "----------------\n";
    cout << "      Default Constructor\n";
    Date date1;
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl;

    cout << "      Parameterized Constructor\n";
    Date date2(6,20,1970);
    date2.WriteNumberFormat();
    date2.WriteNameFormat();
    cout << string(40,'*')  << endl;

    cout << "      Parameterized Constructor\n";
    Date date3(8,1980);
    date3.WriteNumberFormat();
    date3.WriteNameFormat();
    cout << string(40,'*') << endl << endl;
    
    // verifying SetDate date function
    cout << string(40,'*') << endl;
    cout << "Set Date Test\n";
    cout << "-------------\n";
    date1.SetDate(10,6,2000);
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl << endl;
    
    cout << boolalpha;
    // verifying before,after and same date function
    cout << string(40,'*') << endl;
    cout << "Before/After/Same Date Test\n";
    cout << "-------------\n";
    date2.SetDate(10,6,2000);
    date1.SetDate(10,6,2000);
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Same Date?: " <<  date1.SameDate(date2) << endl;
    cout << "Date1 before Date2: " << boolalpha <<  date1.BeforeDate(date2) << endl;
    cout << "Date2 before Date1: " << boolalpha <<  date2.BeforeDate(date1) << endl;
    cout << "Date1 after Date2: " << boolalpha <<  date1.AfterDate(date2) << endl;
    cout << "Date2 after Date1: " << boolalpha <<  date2.AfterDate(date1) << endl << endl;


    date1.SetDate(10,7,2000);
    date2.SetDate(10,6,2000);
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Same Date?: " <<  date1.SameDate(date2) << endl;
    cout << "Date1 before Date2: " << boolalpha <<  date1.BeforeDate(date2) << endl;
    cout << "Date2 before Date1: " << boolalpha <<  date2.BeforeDate(date1) << endl;
    cout << "Date1 after Date2: " << boolalpha <<  date1.AfterDate(date2) << endl;
    cout << "Date2 after Date1: " << boolalpha <<  date2.AfterDate(date1) << endl << endl;

    date1.SetDate(11,6,2000);
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Date1 before Date2: " << boolalpha <<  date1.BeforeDate(date2) << endl;
    cout << "Date2 before Date1: " << boolalpha <<  date2.BeforeDate(date1) << endl;
    cout << "Date1 after Date2: " << boolalpha <<  date1.AfterDate(date2) << endl;
    cout << "Date2 after Date1: " << boolalpha <<  date2.AfterDate(date1) << endl << endl;

    date1.SetDate(10,6,2001);
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Date1 before Date2: " << boolalpha <<  date1.BeforeDate(date2) << endl;
    cout << "Date2 before Date1: " << boolalpha <<  date2.BeforeDate(date1) << endl;
    cout << "Date1 after Date2: " << boolalpha <<  date1.AfterDate(date2) << endl;
    cout << "Date2 after Date1: " << boolalpha <<  date2.AfterDate(date1) << endl << endl;


    cout << string(40,'*') << endl;
    cout << "Testing every month for correct output\n";
    cout << "--------------------------------------\n";
    
    //cout << string(40,'*') << endl;
    for (int i = 1; i<=12; i++)
    {
        date1.SetDate(i,i,2018);
        date1.WriteNumberFormat();
        date1.WriteNameFormat();
        cout << string(40,'*') << endl;
    }


    cout << endl << string(40,'*') << endl;
    cout << "Increment test - extra credit\n";
    cout << "-----------------------------\n";
    date1.SetDate(1,1,2000);
    cout << "starting date: ";
    date1.WriteNumberFormat();
    cout << endl;
    for (int i = 1; i <420;i++)
    {
        date1.IncrementDate();
        if (i%30 == 0)
        {
            cout << "Date + 30: ";
            date1.WriteNumberFormat();
        }

        
     }
    cout << "Final Date: "; 
            date1.WriteNumberFormat();
}
