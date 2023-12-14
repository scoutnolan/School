#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include "list.hpp"
#include "student.hpp"


struct Assignment
{
    float Grade;
    unsigned int StudentUID;
};

/// Classroom is an implementation where the student will specialize an
/// implementation around a data structure with the defined public interface
/// of a List<>.  The classroom will provide a structured way to add and remove
/// students, add assignemnt grades to the students, and print the state
/// of the class.

/// FindStudent() and PrintClassroomInformation will be provided.
class Classroom
{
private:
    List<Student> _classList;

    /// provided
    Student* find_student(unsigned int UID, bool &found);

public:
    Classroom();

    /// verify there are no UIDs in the list
    /// then append.
    /// returns false when the append fails.
    bool AddStudent(const std::string &firstName, const std::string &lastName, 
                    unsigned int UID);
    bool RemoveStudent(unsigned int UID);


    void AddProjects(const List<Assignment> &projects);
    void AddExams(const List<Assignment> &exams);
    void SetFinalExams(const List<Assignment> &finals);


    /// provided
    void PrintClassroomInformation() const;
};


#endif // #ifndef CLASSROOM_HPP