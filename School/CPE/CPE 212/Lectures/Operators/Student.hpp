#include <iostream>
#include <string>

class Student
{
private:
    std::string _firstName;
    std::string _lastName;
    unsigned int _uid;

public:
    Student();
    Student(const std::string &first, const std::string &last, unsigned int uid);

    unsigned int GetUID() const;

    bool operator==(const Student &other) const;
    bool operator!=(const Student &other) const;

};