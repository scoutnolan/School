// ****************************
// Project Title: Project 07
// Project File: Project_07.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 10/18/2019
// program description: project2 sample header
// What the program does
// ****************************
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;


// /home/work/cpe211/Executables/Project_07/Project_07_solution
// /home/work/cpe211data/Project_07/CompareSolution.bash  Project_07.cpp


// ***** Initializing functions ***** //
void Menu();
int obtain();
void coin(int);
void pi_cal(int);
void die(int);
// ***** Int Main ***** //
int main()
{
	int seed;
	// Setup the random number generator starting point by obtaining a seed
	cout << endl << "Enter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
    cout << seed << endl << endl; // echo print out the value entered
	srand(seed); // use the seed entered to initialize the generator
    int i = 0;
	int choice;
    Menu();
    choice = obtain();
    // ***** While loop to take input for menu and go through with the operation. ***** //
    while (choice != 4)
    {
        int pi_num, coin_num, die_num;
        //cin.ignore(INT_MAX,'\n');
        
        if (choice == 1) // if the choice is equal to one, go to the pi_cal function
        {
            pi_cal(pi_num);
        }
        else if (choice == 2) // if choice is equal to two, go to the coin function
        {
            coin(coin_num);
        }
        else if (choice == 3) // if choice is equal to 3, run the die function
        {
            die(die_num);
        }
        else if (choice == 4) // if choice is equal to 4, exit the program
        {
            cout << endl << "Exit selected.  Exiting the program now..." << endl << endl;
            i = 1;
            return 1;
        }
        else //(choice >= 5 || choice <= 0)
        {
            cout << endl << string(15, '*') << " Invalid Integer " << string(15, '*') << endl;
            cout << "==> Invalid integer entered." << endl;
            cout << "==> Please try again..." << endl;
            cout << string(47, '*') << endl << endl;
        }
        
    Menu();
	choice = obtain();
    }
    cout << endl << "Exit selected.  Exiting the program now..." << endl << endl;
    return 0;
}

// ********** FUNCTIONS ********** //


// ***** Menu function ***** //
void Menu()
{
    // ***** Menu options ***** //
    cout << string(24, '*') << endl;
    cout << string(5,'*') << " Menu Options " << string(5,'*') << endl;
    cout << string(24,'*') << endl;
    cout << "1) Approximate PI" << endl;
    cout << "2) Flip a fair coin" << endl;
    cout << "3) Toss a fair 5-sided die" << endl;
    cout << "4) Exit" << endl;
    cout << string(24,'*') << endl << endl;
    
}
int obtain()
{
	int choice;
    choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    char ch;
    while(cin.fail())
	{
	  cin.clear();
	  cin >> ch;
	  cout << ch << endl;
      cout << endl << string(14, '*') << " Invalid Character " << string(14, '*') << endl;
      cout << "==> Invalid character(s) entered." << endl;
      cout << "==> Please try again..." << endl;
      cout << string(47, '*') << endl << endl;
	  cin.ignore(INT_MAX,'\n');
	  Menu();
      cout << "Enter your choice: ";
      cin >> choice;
        
    }
cout << choice << endl;
cin.ignore(INT_MAX,'\n');
return choice;
}

// ***** Calculation for PI ***** //
void pi_cal(int)
{
    // Calculation for pi here
    int iterations, sqrt_xy, pairs, empty;
    double x, y, pi_calc;
    // Output for PI Caluclations
    cout << endl << "Monte Carlo Method for finding PI has been selected" << endl << endl;
    cout << "Number of iterations: ";
    cin >> iterations;
    cout << iterations << endl << endl;
    pairs = 0;
    empty = 0;
    for (int i = 1; i <= iterations; i++)
    {
        x = double(rand())/(double(RAND_MAX));
        y = double(rand())/(double(RAND_MAX));
        sqrt_xy = sqrt((x*x)+(y*y));
        if (sqrt_xy <= 0)
        {
            pairs++;
        }
        else
        {
            empty ++;
        }
    }
    pi_calc = 4*double(pairs)/double(iterations);
    cout << string(10,'*') << " Option 1: Calculating PI " << string(10,'*') << endl;
    //cout << fixed;
    cout.precision(6);
    cout << "For " << iterations << " iterations, pi is about " << fixed << pi_calc << endl;
    cout << string(46,'*') << endl << endl;
}


// ***** Coin flip function ***** //
void coin(int)
{
	int one, two, flip;
    one = 0; // initializing count variables
    two = 0;
	double  rand_int, p_heads, p_tails;
    cout << endl << "Flipping of a fair coin has been selected" << endl << endl;
    cout << "How many flips of the coin? ";
    cin >> flip; // input for number of flips to perform
    cout << flip << endl << endl;
    for (int i = 1; i <= flip; i++) // for range of 1 to number of flips, perform this.
    {
        rand_int = double(rand())/double(RAND_MAX);
		//cout << rand_int << endl; // value is 0 to 1
        if (rand_int <= 0.5)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
                   // total for number of flips
    p_tails = double(one) / double(flip) * 100.0;
    p_heads = double(two) / double(flip) * 100.0;
    // ***** Output for information above.
    cout << string(10, '*') << " Option 2: Flipping a Coin " << string(10,'*') << endl;
    cout << "For " << flip << " flips of a fair coin:" << endl;
    cout.precision(4);
    cout << "Heads percentage: "  << fixed << p_heads << endl; // heads percentage variable
    cout << "Tails percentage: "  << fixed << p_tails << endl; // tails percentage variable
    cout << string(47, '*') << endl << endl;
}

// ***** Rolling a die function ***** //
void die(int)
{
	int times;
	double s1, s2, s3, s4, s5, p_s1, p_s2, p_s3, p_s4, p_s5, rand_int;
    cout << endl << "Tossing of a fair 5-sided die has been selected" << endl << endl; // input for times to roll die
    cout << "How many times do you want to roll the die? ";
    cin >> times;
    cout << times << endl << endl;
    s1 = 0; // Initializing side variables
    s2 = 0;
    s3 = 0;
    s4 = 0;
    s5 = 0;
    for (int i = 1; i <= times; i++)
    {
        rand_int = double(rand())/double(RAND_MAX); // value is 0 to 1
        if (rand_int < 0.2) // if the random number is less than 0.2, add one to side one counter, and so on
        {
            s1++;
        }
        else if (rand_int >= 0.2 && rand_int < 0.4)
        {
            s2++;
        }
        else if (rand_int >= 0.4 && rand_int < 0.6)
        {
            s3++;
        }
        else if (rand_int >= 0.6 && rand_int < 0.8)
        {
            s4++;
        }
        else
        {
            s5++;
        }
    }
    p_s1 = double(s1) / double(times) * 100.0;    // percentage calculations for each side.
	p_s2 = double(s2) / double(times) * 100.0;
	p_s3 = double(s3) / double(times) * 100.0;
	p_s4 = double(s4) / double(times) * 100.0;
	p_s5 = double(s5) / double(times) * 100.0;
    cout.precision(4);
    // ***** Output of information calculated above ***** //
    cout << string(10,'*') << " Option 3: Tossing a Die " << string(10,'*') << endl;
    cout << "For " << times << " rolls of a fair die:" << endl;
    cout << "Side 1 percentage: "  << fixed << p_s1 << endl;
    cout << "Side 2 percentage: "  << fixed << p_s2 << endl;
    cout << "Side 3 percentage: "  << fixed << p_s3 << endl;
    cout << "Side 4 percentage: "  << fixed << p_s4 << endl;
    cout << "Side 5 percentage: "  << fixed << p_s5 << endl;
    cout << string(45,'*') << endl << endl;
}
