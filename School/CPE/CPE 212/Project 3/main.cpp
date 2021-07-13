#include "classroom.hpp"
#include "list.hpp"
#include "student.hpp"

#include <iostream>
#include <fstream>
#include <string>


List<Assignment> ReadGradesFile(const std::string &file, bool &successful)
{
    std::ifstream infile;
    List<Assignment> list;
    infile.open(file.c_str());
    if(!infile.is_open())
    {
        std::cout << "Failed to open a file" << std::endl;
        successful = false;
        return list;
    }

    while(true)
    {
        Assignment a;
        infile >> a.StudentUID;
        infile >> a.Grade;
        if(infile.eof())
        {
            break;
        }
        list.AppendItem(a);
    }
    return list;
}


int main(int argc, char * const argv[])
{
        // Output usage message if test input file name is not provided
    if (argc != 2)
    {
        std::cout << "Usage:\n  P3  <inputfile>\n";
        return -1;
    }
    

    std::ifstream input;
    // Attempt to open test input file -- terminate if file does not open
    input.open(argv[1]);
    if (!input)
    {
        std::cout << "Error - unable to open input file" << std::endl;
        return 1;
    }

    {
        Student testStudent;
        Classroom classroom;

        std::string line;
        std::getline(input, line);

        char op;
        input >> op;
        
        while(input)
        {
            switch(op)
            {
                /// comment
                case '#':
                    getline(input, line);
                    std::cout << "# " << line << std::endl;
                break;
                /// test student
                case 'z':
                {
                    std::string studentFirst;
                    input >> studentFirst;
                    std::string studentLast;
                    input >> studentLast;
                    unsigned int id;
                    input >> id;
                    testStudent = Student(studentFirst, studentLast, id);
                }
                break;

                /// add student to classroom
                case 's':
                {
                    std::string studentFirst;
                    input >> studentFirst;
                    std::string studentLast;
                    input >> studentLast;
                    unsigned int id;
                    input >> id;
                    classroom.AddStudent(studentFirst, studentLast, id);
                }
                break; 

                /// Test Student Exam
                case 'n':
                {
                    float grade;
                    input >> grade;
                    testStudent.AddExam(grade);
                }
                break;

                /// Test student project
                case 'l':
                {
                    float grade;
                    input >> grade;
                    testStudent.AddProject(grade);
                }
                break;

                /// Test student final
                case 'k':
                {
                    float grade;
                    input >> grade;
                    testStudent.SetFinalExam(grade);
                }
                break;

                /// exams
                case 'e':
                {
                    std::string examFile;
                    input >> examFile;
                    bool successful = true;
                    List<Assignment> exams = ReadGradesFile(examFile, successful);
                    if(!successful)
                    {
                        std::cout << "Failure" << std::endl;
                        return -1;
                    }
                    classroom.AddExams(exams);
                }
                break;

                /// projects
                case 'p':
                {
                    std::string projectFile;
                    input >> projectFile;
                    bool successful = true;
                    List<Assignment> projects = ReadGradesFile(projectFile, successful);
                    if(!successful)
                    {
                        std::cout << "Failure" << std::endl;
                        return -1;
                    }
                    classroom.AddProjects(projects);
                }

                break;

                /// projects
                case 'f':
                {
                    std::string finalsFile;
                    input >> finalsFile;
                    bool successful = true;
                    List<Assignment> finals = ReadGradesFile(finalsFile, successful);
                    if(!successful)
                    {
                        std::cout << "Failure" << std::endl;
                        return -1;
                    }
                    classroom.SetFinalExams(finals);
                }

                break;

                /// Remove student UID
                case 'r':
                {
                    unsigned int uid;
                    input >> uid;
                    if(!classroom.RemoveStudent(uid))
                    {
                        std::cout << "UID not found: " << uid << std::endl;
                    }
                    else
                    {
                        std::cout << "Removed: " << uid << std::endl;
                    }
                }
                break;

                /// print test student
                case 't':
                    testStudent.PrintData();
                break;

                /// print full classroom
                case 'a':
                    classroom.PrintClassroomInformation();
                break;

                default:
                    std::cout << "Unknown input found" << std::endl;
                    return -1;
                break;
            }
            input >> op;
        }

    }
    return 0;
}
