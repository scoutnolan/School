#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



struct studentRec{
    string firstname;
    string lastname;
    float gpa;
};

int main(){
    studentRec someStudent, nextStudent;
    someStudent.firstname = "Joe";
    someStudent.lastname = "Bob";
    someStudent.gpa = 3.35;
    nextStudent.firstname = "Bob";
    nextStudent.lastname = "Joe";
    nextStudent.gpa = 4.0;

    cout << someStudent.firstname << " " << someStudent.lastname << " GPA: " << someStudent.gpa << endl;
    cout << nextStudent.firstname << " " << nextStudent.lastname << " GPA: " << nextStudent.gpa << endl;

}