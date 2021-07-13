#include "Student.hpp"

Student::Student()
{

}

Student::Student(const std::string &first, const std::string &last, unsigned int uid)
{
    _firstName = first;
    _lastName = last;
    _uid = uid;
}

unsigned int Student::GetUID() const
{
    return _uid;
}

bool Student::operator!=(const Student &other) const
{
    return _uid != other.GetUID();
}

bool Student::operator==(const Student &other) const
{
    return _uid == other.GetUID();
}


//Return_type ClassName::operator op(Arguments list)
//
    // function body
//    