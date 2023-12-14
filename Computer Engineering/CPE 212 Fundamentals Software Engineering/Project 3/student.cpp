#include "student.hpp"


Student::Student(const std::string & first, const std::string &last,
                unsigned int id)
{
    _firstName = first;
    _lastName = last;
    _studentID = id;

    _finalExamGrade = 0;

}

Student::Student()
{
    _firstName = "";
    _lastName = "";
    _studentID = 0;

    _finalExamGrade = 0;
}

unsigned int Student::GetID() const
{
    return _studentID;
}


float Student::CalculateFinalAverage() const
{
    float hwAVG = project_grades_average();
    float examAvg = exam_grades_average();
    float finalExamAvg = _finalExamGrade;

    return hwAVG * PROJECTS_WEIGHT + examAvg * EXAM_WEIGHT + finalExamAvg * FINAL_EXAM_WEIGHT;
}

std::string Student::GetFinalLetterGrade() const
{
    float avg = CalculateFinalAverage();

    if(avg >= 90.0f)
    {
        return "A";
    }
    if(avg >= 80.0f)
    {
        return "B";
    }
    if(avg >= 70.0f)
    {
        return "C";
    }
    if(avg >= 60.0f)
    {
        return "D";
    }
    return "F";
}

void Student::AddProject(float projectGrade)
{
    _projects.AppendItem(projectGrade);
}

void Student::AddExam(float examGrade)
{
    _exams.AppendItem(examGrade);
}

void Student::SetFinalExam(float examGrade)
{
    _finalExamGrade = examGrade;
}


float Student::project_grades_average() const
{
    if(_projects.Count() == 0)
    {
        return 0.0f;
    }

    float avg = 0.0f;
    _projects.ResetIterator();
    while(!_projects.AtEnd())
    {
        avg += *_projects.IterateItems();
    }

    return avg / (float)(_projects.Count());
}

float Student::exam_grades_average() const
{
    if(_exams.Count() == 0)
    {
        return 0.0f;
    }

    float avg = 0.0f;
    _exams.ResetIterator();
    while(!_exams.AtEnd())
    {
        avg += *_exams.IterateItems();
    }

    return avg / (float)(_exams.Count());
}

void Student::PrintData() const
{
    std::cout << _firstName << " " << _lastName << std::endl;
    std::cout << "ID: " << _studentID << std::endl;
    std::cout << "Final letter grade: " << GetFinalLetterGrade() << std::endl;
    std::cout << "Final course grade: " << CalculateFinalAverage() << std::endl;
    std::cout << "\tGRADES" << std::endl;
    std::cout << "Final Exam Grade: " << _finalExamGrade << std::endl;
    std::cout << "Projects final grade: " << project_grades_average() << std::endl;
    _projects.ResetIterator();
    int counter = 1;
    while(!_projects.AtEnd())
    {
        std::cout << counter++ << ") " << *_projects.IterateItems() << std::endl;
    }
    std::cout << "Exams final grade: " << exam_grades_average() << std::endl;
    _exams.ResetIterator();
    counter = 1;
    while(!_exams.AtEnd())
    {
        std::cout << counter++ << ") " << *_exams.IterateItems() << std::endl;
    }
    std::cout << std::endl;
}

bool Student::operator!=(const Student &otherStudent)
{
    return otherStudent.GetID() != this->_studentID;
}

bool Student::operator==(const Student &otherStudent)
{
    return otherStudent.GetID() == this->_studentID;
}
