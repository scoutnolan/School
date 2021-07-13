#include "classroom.hpp"
///home/facstaff/taf0004/CPE212SP20/Project03/P3 <insert_test_name>
///
Classroom::Classroom()
{

}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
Student* Classroom::find_student(unsigned int UID, bool &found)
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        Student* s = _classList.IterateItems();
        if(s->GetID() == UID)
        {
            found = true;
            return s;
        }
    }
    found = false;
}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
void Classroom::PrintClassroomInformation() const
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        std::cout << "****************************************" << std::endl;
        _classList.IterateItems()->PrintData();
        std::cout << std::endl;
    }
}

/// modify code below this line
// ========================================
bool Classroom::AddStudent(const std::string &firstName, const std::string &lastName, unsigned int UID)
{
    
    Student student(firstName, lastName, UID);          // creating a new student object based on the parameters passed in
    bool newbool = true;                                // create a new boolean operator to call into the find_student function
    find_student(UID,newbool);
    if(newbool)                                         // if the UID was found in the find_student function...
    {                    
        return false;                                   // return false to the output since you do not need to add two.
    }
    else                                                // if the UID was not found,
    {
        _classList.AppendItem(student);                 // adding the student object to the class list
        return true;                                    // and return true back to main
    }
}

    /// adds the item to the list.
    /// does not add a student that already exists, based on the UID
    /// returns true if the student was successfully added

bool Classroom::RemoveStudent(unsigned int UID)
{
                                            // new student object to delete
    bool newbool = true;                    // new boolean variable to call into find_student
    Student* student = find_student(UID, newbool);
    find_student(UID,newbool);
    if(newbool)                             // if the student ID is found
    {
        _classList.DeleteItem(*student);    // delete the student
        return true;                        // then return true
    }   
    else                                    // if the student is not found
    {
        return false;                       // return false
    }
}
    /// removes the student from the list based on UID.
    /// returns true if the student was successfully removed

void Classroom::AddProjects(const List<Assignment> &projects)
{
    Assignment* proj;                               // new project object
    bool found;                                     // empty bool variable
    Student* stu;                                   // new student object
    projects.ResetIterator();                       // reset the iterator so that you can itetarate through from the beginning
    while(!projects.AtEnd())
    {           
        proj = projects.IterateItems();             // iterate through the projects
        found = false;                                         // boolean variable
        stu = find_student(proj->StudentUID,found); // setting the student object to the return object from the find_student function
        if(found)                                   // if the objecct is found
        {
            stu->AddProject(proj->Grade);           // add a project to the student object
        }
    }
    /// adds the projects to the required student's list of projects
}

void Classroom::AddExams(const List<Assignment> &projects)
{
    Assignment* exam;
    bool found;
    Student* stu;
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        exam = projects.IterateItems();             
        found = false;
        stu = find_student(exam->StudentUID,found);
        if(found)
        {
            stu->AddExam(exam->Grade);
            //std::cout << stu->GetID() << ": " << exam->Grade << std::endl; // output for the student ID and the grade   
            //std::cout << "Added to student: " << stu->GetID() << std::endl;// added to the student
        }
    }
    /// adds the exams to the required student's list of exams
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
    Assignment *final;
    bool found;
    Student* stu;
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        final = projects.IterateItems();
        found = false;
        stu = find_student(final->StudentUID,found);
        if(found)
        {
            stu->SetFinalExam(final->Grade);
        }
        else
        {
            stu->SetFinalExam(0);
        }
    }  
    /// sets the required student's FinalExam score.
}