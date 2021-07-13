#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "list.hpp"

#include <string>

#define PROJECTS_WEIGHT .25f
#define EXAM_WEIGHT .4f
#define FINAL_EXAM_WEIGHT .35f

#define MAX_PROJECTS 6
#define MAX_EXAMS 2


/// the student object will be completely implemented and given to the class.
class Student
{
private:
    std::string _firstName;
    std::string _lastName;
    unsigned int _studentID;
    List<float> _projects;
    List<float> _exams;
    unsigned int _finalExamGrade;


    float project_grades_average() const;
    float exam_grades_average() const;

public:
    Student(const std::string & first, const std::string &last,
            unsigned int id);
    Student();

    unsigned int GetID() const;
    void AddProject(float projectGrade);
    void AddExam(float examGrade);
    void SetFinalExam(float examGrade);

    float CalculateFinalAverage() const;
    std::string GetFinalLetterGrade() const;


    bool operator==(const Student &otherStudent);
    bool operator!=(const Student &otherStudent);
    
    // provided
    void PrintData() const;

};


#endif // #ifndef STUDENT_HPP