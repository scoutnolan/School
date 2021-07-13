// ****************************
// Project Title: Project 06
// Project File: Project_06.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 10/06/2019
// program description: Inputs a text file of names and grades and output's it into an output file
// ****************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <typeinfo>
using namespace std;

//Sample solution
//- /home/work/cpe211/Executables/Project_06/Project_06_solution
//Comparison script
//- /home/work/cpe211data/Project_06/CompareSolution.bash Project_06.cpp


int main(int argc, char* argv[])
{
	if (argc != 3) // if the amount of arguments is greater than 2, perform this.
	{
		cout << endl;
		cout << "Incorrect number of command line arguments provided. \n";
		cout << "This program requires 2 command line arguments: \n";
		cout << "An input filename and an output filename \n \n";
		cout << "Program usage is: \n";
		cout << "./Project_06 InputFileName OutputFileName \n \n";
		return 1;
	}
    
	
	// Variable Delcaration
	ifstream inFile; // input
	ofstream outFile; // output
    string inputFileName, outFileName;
	string line1, line2, line3, first, last;
	int total, average, total_sol, i, j, k, count, homework_total, exam_total, quiz_total, average_p2, average_total, count_students;
	int quiznum, homeworknum, examnum;
	int quiz, homework, exam;
    
    
    
    // ***** Opening and naming command line argument ***** //
    cout << endl;
    inputFileName = argv[1]; // assign command line argument value to a string variable
    inFile.open(inputFileName.c_str());
    cout << "Opening Input File: " << inputFileName << endl;
    cout << endl;
    outFile.open(argv[2]);
    cout << "Opening Output File: " << argv[2] << endl;
    cout << endl;
    
    
    // ***** Testing to see if the file exists ***** //
    while (inFile.fail()) // if the file does not exist, then do this.
    {
    	cout << endl;
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> Input file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << inputFileName << endl;
        cout << "==> Please try again...\n";
        cout << string(47,'*') << endl << endl;
        inFile.clear(); // clears the input file stream
		cout << "Enter the name of the input file: " << endl;
    	cin >> inputFileName; // user inputs new name of file
   	 	inFile.open(inputFileName.c_str()); // opens the new input file
    	cout << inputFileName << endl; // echo prints the new input file name
        cout << "Opening Output File: " << argv[2] << endl << endl; // echo the output fule
        
    }
	
	// ***** Testing for output file existance ***** //
    while (outFile.fail()) // if the file does not exist, then do this.
    {
    	cout << endl;
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> Output file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << argv[2] << endl;
        cout << "==> Please try again...\n";
        cout << string(47,'*') << endl << endl;
        outFile.clear();
		cout << "Enter the name of the output file: " << endl;
    	cin >> outFileName; // recieves input for the new output file name
   	 	outFile.open(outFileName.c_str()); // opens the output file
    	cout << outFileName << endl << endl; // echo prints new output file name
	}
    
    
    // ***** First line information ***** //
    inFile >> quiz >> homework >> exam; // obtains the how many number of quiz, homework, and exam scores
	if (inFile.eof())
    {
        cout << endl;
        cout << "*************" << " Input File Is Empty " << "*************" << endl;
        cout << "==> The input file is empty.\n";
        cout << "==> Terminating the program.\n";
        cout << string(47,'*') << endl << endl;
        outFile << "Input file " << inputFileName << " is empty. \n";
        return 1;
    }
    
    
    // ***** Count initializers ****** //
    homework_total = 0; exam_total = 0; average_total = 0;
    count_students = 0;
    count = 0;
    i = 0; j = 0; k = 0;
    int count_count = 0;
    // ***** Starting for output ***** //
    outFile << "#  " << "Last        " << "First  " << "Quiz  " << "HW   " << " Exam " << " Total  " << "Average" << endl; // First line info for each part of the file
    outFile << setw(3) << left << "-" << setw(12) << "----------" << setw(7) << "-----" << setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl; // seperating dashes
    
    
	
	
	// ***** Sample solution data ***** //
    
    inFile >> last >> first;
        while (i < quiznum)
        {
            inFile >> quiz;             // gets the quiz scores
            quiz_total = quiz_total + quiz;   // total of all quiz scores
            i++;
        }
    	while (j < homeworknum)
    	{
	        inFile >> homework;
	        homework_total = homework_total + homework;
	        j++;
    	}
        while (k < examnum)
        {
            inFile >> exam;             // gets exam scores
            exam_total = exam_total + exam;   // totals all exam scores found
            k++;               // updates count
        }
        
        
    total_sol = quiz_total + homework_total + exam_total; // total score for solution set
    average = (total_sol) / (total_sol) * 100; // average for solution set (100%)
    outFile << "   " << setw(10) << last <<  "  " << setw(5) << first << " " << setw(4) << quiz_total << " " << setw(2) << homework_total << " " << setw(3) << exam_total << " " << setw(3) << total_sol << " " << average << endl; // output of all the above info
	
	
	
	
	// *** Sees if there are any students in the file *** // 
	if (inFile.eof())
	{
		cout << "Input file did not contain any students" << endl;
		outFile << setw(3) << left << "-" << setw(12) << "----------" << setw(7) << "-----" << setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl; // seperating dashes
		outFile << "Input file did not contain any students" << endl;
		return 1;
	}

    outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" << setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl; // seperating dashes

	// *************************************************************************************//
	/////  NOTE /////
	// THE FOLLOWING CODE DOES NOT WORK. FOR SOME REASON THERE IS A INFINITE LOOP HAPPENING // 
	// *************************************************************************************//
	
	// ********* The following grabs the info from each line using count controlled loops ********* //
	//inFile >> quiz >> homework >> exam;
//    inFile >> last >> first;
//    
//    // ** resetting counters ** //
//    
//    while (!inFile.eof())
//    {
//    	i = 0; j = 0; k = 0; quiz_total = 0; homework_total = 0; exam_total = 0; count_students = 0;
//	    while (i < quiznum) // while the count is less than the number of the quizzes, do this.
//	    {
//	        inFile >> quiz;                     // quiz scores
//	        quiz_total = quiz_total + quiz;           // total of all the quiz scores
//	        i++;                       // updates count
//	    }
//	    while (j < homeworknum) // while the count is less than the number of specified homeworks, do this
//	    {
//	        inFile >> homework;                 // homework scores
//	        homework_total = homework_total + homework; // total of all homework scores
//	        j++;                   // updates count
//	    }
//	    while (k < examnum) // while the count is less than than the number of specified exams, do this.
//	    {
//	        inFile >> exam;                     // exam scores
//	        exam_total = exam_total + exam;           // total of all exam scores
//	        k++;
//	    }
//    
//    
//        count_students++; // student number
//        total = quiz_total + homework_total + exam_total; // total # of quiz, homeworks, and exam scores added
//        average_p2 = total / average; // average for each student
//        average_total = (average_total + average_p2) / count_students; // total average for all students
//        outFile << count_students << last << first << quiz_total << homework_total << exam_total <<  average_p2 << endl;
//        inFile.ignore();
//        inFile >> last >> first;
//    }
    
    
    
    // ***** Last line and class average ***** //
    outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" << setw(6) << "----" << setw(6) << "---" << setw(6) << "----" << setw(7) << "-----" << setw(9) << "-------" << endl << endl; // seperating dashes
    outFile << "Class Average = " << average_total << endl; // outputs the total average of the exam.


    outFile.close();
	return 0;
}
