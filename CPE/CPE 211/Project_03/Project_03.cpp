// ****************************
// Project Title: Investment over time, compounded at different rates
// Project File: Project_03.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 9/04/2019
// program description: Takes user input and finds the amount an investment will amount to.
// Takes user input and finds the value of someones investment at different compound types.
// ****************************
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    //P = Starting balance, A = final balance, R = simple interest reate,
    //N = # of times compounded per year, T = Number of years invested,
    //Reff = Effective simple interest rate
    double P;               //Doubles for all of the different variables I used.
    double T;
    double R;
    double a_simple;
    double base_month;
    double exp_month;
    double a_month;
    double eff_month;
    double eff_month_balance;
    double base_daily;
    double exp_daily;
    double a_daily;
    double eff_daily;
    double eff_daily_balance;
    double a_continue;
    double eff_continue;
    double eff_continue_balance;
    
    
    
    
    cout << "Input the starting balance; ";       // Prompt for intial balance
    cin >> P;                                     // Input for initial balance
    cout << P << endl;                            // Echo initial value
    
    cout << "\n";
    
    cout << "Input the interest rate (Ex: 5 for 5%): " ;     // Prompt for interest rate
    cin >> R;                                     // Input for interest rate
    cout << R << endl;                            // Echo interest rate
    
    cout << "\n";
    
    cout << "Input the number of years: ";        // Prompt for years invested
    cin >> T;                                     // Input for the # of years invested
    cout << T << endl;                            // Echo the years invested value
    
    cout << "\n";                                 // Makes an empty line in the code
    
    cout << "For a principle of $" << P << "," << endl;            // next 4 lines echo's the inputs from above
    cout << "at an interest rate of " << R << "%," << endl;
    cout << "for a period of " << T << " years, " << endl;
    cout << "The final account balance would be:" << endl;
    R = R / 100;
    
    
    // ***** SIMPLE INTEREST ***** //
    
    
    cout << "\n";
    a_simple = P * (1.0 + T * R);                 // Finds simple effective interest rate balance
    cout << "Simple interest: " << endl;
    cout << "\tBalance = $" << fixed << showpoint << setprecision(2) <<  a_simple << endl;  // Outputs the balance found above and ends the line, set precision is maintained throughout the rest of the code unless changed.
    cout << "\n" << endl;
    
    
    // ***** COMPOUND MONTHLY ***** //
    
    
    cout << "Compounded Monthly: " << endl;
    base_month = (1.0+(R/12.0));                            // Base of the Compound interest formula
    exp_month  = (12.0*T);                                  // Exponent of the compound interest formula
    a_month    = P * pow(base_month,exp_month);             // Finds the balance for compound interest using the power function
    eff_month       = (1.0/(12.0*T))*((a_month/P)-1.0)*12;
    eff_month_balance = P * (1.0 + T * eff_month);          //Finds the balance using the effective interest rate.
    cout << "\tBalance = $" << a_month << endl;             // Output statement for the amount in the month.
    cout << "\tThe effective Simple Interest rate: " << eff_month * 100.0 << "%" << endl;
    cout << "\tBalance using Simple Interest at the Effective Rate = " << eff_month_balance << endl;
    cout << "\n" << endl;
    
    
    
    // ***** COMPOUND DAILY ***** //
    
    
    cout << "Compounded Daily: " << endl;
    base_daily = (1.0+(R/365.0));                   // Base of the compound interest formula
    exp_daily  = (365.0*T);                         // Exponent for the compound interest formula
    a_daily    = P * pow(base_daily,exp_daily);     // Finds the balance for compound interest using the power function
    eff_daily  = (1.0/(365.0*T))*((a_daily/P)-1.0)*365;;              // Finds the effective interest rate
    eff_daily_balance = P * (1.0 + T * eff_daily);  // Finds the balance using effective interest rate
    cout << "\tBalance = $" << a_daily << endl;
    cout << "\tThe Effective Simple Inerest Rate: " << eff_daily * 100.0 << "%" << endl; // *10 to put it into standard percentage
    cout << "\tBalance using Simple Interest at the Effective Rate = $" << eff_daily_balance << endl;
    cout << "\n" << endl;
    
    
    
    // ***** COMPOUND CONTINUOUSLY ***** //
    
    
    cout << "Compounded continuously " << endl;
    a_continue  = P * exp(R*T);                       // Using the exp() function, (e^something), this line finds the balance when compounded continuously
    eff_continue = (exp(R*T)-1.0)/T;                  // Finds the effective interest rate
    eff_continue_balance = P * (1.0 + T * eff_continue);    // Finds the balance using the effective interest rate
    cout << "\tBalance = $" << a_continue << endl;
    cout << "\tThe Effective Simple Inerest Rate: " << eff_continue * 100.0 << "%" << endl; // *10 to put it into standard percentage
    cout << "\tBalance using Simple Interest at the Effective Rate = $" << eff_continue_balance << endl;
    
    
    return 0;
    
}



