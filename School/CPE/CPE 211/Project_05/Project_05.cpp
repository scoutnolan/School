// ****************************
// Project Title: Shipping cost
// Project File: Project_05.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 9/27/2019
// program description: Finds the price of shipping a certain package based on file parameters
// Reads in data from a file and calculates the price to ship the data in that file. Also checks to make sure that the contents of the file are usable in the program
// ****************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;
//  /home/work/cpe211/Executables/Project_05/Project_05_solution
//  /home/work/cpe211data/Project_05/CompareSolution.bash Project_05.cpp
int main()
{
// *********** Delcaring Variables ************ //
    
    float base_rate, total_cost, weight_adjust, length_adjust;
    int length, width, height, weight, total_length;
    string line1, line2, line3, line4, line5, line6, package_type, parcel, media, bulk;
    
// ************* Input File ************** //
	cout << endl;
    string filename;
    ifstream InFile;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    InFile.open(filename.c_str());
    cout << filename << endl;
    
// ************ Testing file stream (14 -does not exist) ******** //

    if (InFile.fail())
    {
        cout << endl;
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> Input file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << filename << endl;
        cout << "==> Terminating program!!!\n";
        cout << string(47,'*') << endl << endl;
        return 1;
    }
    
// ************ Testing if file is empty (1) ********** //
    getline(InFile,line2,'\n');
    InFile >> package_type;

    if (InFile.eof())
    {
        cout << endl;
        cout << string(16,'*') << " File Is Empty " << string(16,'*') << endl;
        cout << "==> Input file is empty.\n";
        cout << "==> No information to process.\n";
        cout << "==> Terminating program.\n";
        cout << string(47,'*') << endl << endl;
        return 1;
    }
	
    
// ************ Testing if file has invalid package type (4,11) ************* //

    if (package_type != "parcel")
	{
		if (package_type != "media")
		{
			if (package_type != "bulk")
			{
                cout << endl;
				cout << string(12,'*') << " Invalid Package Type " << string(13,'*') << endl;
        		cout << "==> Error in data file!!!" << endl;
        		cout << "==> The package type is incorrect" << endl;
        		cout << "==> Terminating program!!!" << endl;
        		cout << string(47,'*') << endl << endl;
        		return 1;
			}
		}
    }
    
// ********* Invalid character presient in package parameters (5,12) *********** //
    
    getline(InFile,line3,'\n');
    InFile >> length;
    getline(InFile,line4, '\n');
    InFile >> width;
    getline(InFile,line5, '\n');
    InFile >> height;
    getline(InFile,line6, '\n');
    InFile >> weight;
    
    if (InFile.fail()) // tests the type of these variables
    {
        cout << endl;
        cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
        cout << "==> Reading of one or more package" << endl;
        cout << "==> parameters failed!!" << endl;
        cout << "==> Terminating program!!!" << endl;
        cout << string(47,'*') << endl << endl;
        return 1;
    }

// ************ One ot more of the package paramters is negative (6-9,13) ******** //

    if (length < 0 || width < 0 || height < 0 || weight < 0) // essentially if any of these values are negative, do this
    {
        cout << endl;
        cout << string(11,'*') << " Package Parameter Error " << string(11,'*') << endl;
        cout << "==> One or more of the package parameters" << endl;
        cout << "==> has a negative value!!!" << endl;
        cout << "==> Terminating program!!!" << endl;
        cout << string(47,'*') << endl << endl;
        return 1;
    }

// ************ Package Type Calculation *********** //
    
    if (package_type == "parcel")
    {
        base_rate = 2.25;
    }
    else if (package_type == "media")
    {
        base_rate = 3.50;
    }
    else if (package_type == "bulk")
    {
        base_rate = 4.75;
    }
    
// ************ Calculation for length ************ //

    total_length = length + width + height; // adding the total length of the package
    if (total_length < 40)
    {
        length_adjust = 1.00;
    }
    if (total_length >= 40 && total_length < 60)
    {
        length_adjust = 2.50;
    }
    if (total_length >= 60)
    {
        length_adjust = 3.75;
    }
    
// ************ Calculation for weight ************ //
    
    if (weight < 10) // if statements to find the weight adjustment
    {
        weight_adjust = 1.00;
    }
    if (weight >= 10 && weight < 25)
    {
        weight_adjust = 3.00;
    }
    if (weight >= 25)
    {
        weight_adjust = 4.50;
    }
    
// ************ Calculation for total cost ************ //

    total_cost = (base_rate) * (length_adjust) * (weight_adjust);

// ************ output package attributes ************ //
	cout << fixed << setprecision(2);
    cout << endl;
    cout << string(50,'-') << endl;
    cout << "The package attributes are:" << endl;
    cout << setfill('.') << setw(30) << left << "Package Type" << package_type << endl;
    cout << setfill('.') << setw(30) << left << "Total Length" << total_length << " inches" << endl;
    cout << setfill('.') << setw(30) << left << "Weight" << weight << " pounds" << endl;
    cout << string(50,'-');
    
// ******** Package rate factors ********* //
    cout << endl;
    cout << "The package rate factors are:" << endl;
    cout << setfill('.') << setw(30) << left << "Package Base Rate" << base_rate << " dollars" << endl;
    cout << setfill('.') << setw(30) << left << "Length Factor Used" << length_adjust << endl;
    cout << setfill('.') << setw(30) << left << "Weight Factor Used" << weight_adjust << endl;
    cout << string(50,'-') << endl;
    
    
// ******** Total Cost output ******** //
    
    cout << setprecision(2) << "The final cost of mailing the package is: $" << total_cost << endl << endl;
    return 0;
}


