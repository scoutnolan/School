// Nolan Anderson
// Map program for quiz 11
#include <iostream>
#include <map>
using namespace std;
// ---------------------------- STRUCTURE FOR STUDENT ---------------------------- //
struct Student
{
    string student_name;
        float grade_num;
        string stringgrade;
        int num;

// ---------------------------- CALCULATE LETTER GRADE FUNCTION ---------------------------- //
    void CalculateLetterGrade()
    { // simple if / if else statements to run through to find the actual string grade. 
    if(grade_num >= 90)
        stringgrade = "A";

    else if(grade_num >= 75)
        stringgrade = "B";

    else if(grade_num >= 60)
        stringgrade = "C";

    else if(grade_num >= 45)
        stringgrade = "D";

    else
        stringgrade = "F";
    }
};
// ---------------------------- MAIN ---------------------------- //
int main()
{
    // Creating a new map.
    map<string, Student> Map; 
    Student stu_map[5];
    // Each of the following will have it's own "position" in the map. 
    // Student one with data
    stu_map[0].student_name = "Merry";
    stu_map[0].num = 25269610;
    stu_map[0].grade_num = 97.23;
    // Student 2 with data
    stu_map[1].student_name = "Bilbo";
    stu_map[1].num = 25269611;
    stu_map[1].grade_num = 77;
    // Student 3 with data
    stu_map[2].student_name = "Sam";
    stu_map[2].num = 25269612;
    stu_map[2].grade_num = 95.50;
    // Student 4 with data
    stu_map[3].student_name = "Frodo";
    stu_map[3].num = 25269613;
    stu_map[3].grade_num = 40;
    // Student 5 with data
    stu_map[4].student_name = "Pippin";
    stu_map[4].num = 25269614;
    stu_map[4].grade_num = 57.75;

    // This for loop will calculate the letter grade for each student and insert that data back into the map
    // And associate it with the student that it is currently on.
    for(Student stu : stu_map)
    {
        stu.CalculateLetterGrade();                               // Calculates the grade string
        Map.insert(pair<string, Student>(stu.student_name, stu));   // inserts that into the map for the string of the letter grade
    }
    map<string,Student>::iterator it= Map.find(stu_map[2].student_name);                       // finding the string for the letter grade
    if(it != Map.end())                                                                        // need to find if it is not at the end, if it is at the end then there is nothing to output.                                                                       
        cout << "Students name: " << it->first << endl;
        cout << "Students number grade: " << it->second.grade_num << endl;
        cout << "Students letter grade: " << it->second.stringgrade << endl;    // this outputs the letter grade.

    return 0;
}
