#ifndef PRIORITYLIST_HPP
#define PRIORITYLIST_HPP

#include "Process.hpp"

#include <deque>


class PriorityList
{
private:
    Priority _priority;
    std::deque<Process> _tasks;


public:
    PriorityList(const Process &process, Priority priority);

    Process Pop();
    void Push(const Process & process);

    void SwapList(PriorityList &other);

    Priority Prio() const;
    bool IsEmpty() const;
};


/// equality operators so that we can compare the priorities of the 
/// Process and PriorityList objects
bool operator==(const Process &process, const PriorityList &list); 
bool operator!=(const Process &process, const PriorityList &list); 
bool operator<(const Process &process, const PriorityList &list); 
bool operator>(const Process &process, const PriorityList &list); 
bool operator==(const PriorityList &list, const Process &process); 
bool operator!=(const PriorityList &list, const Process &process); 
bool operator<(const PriorityList &list, const Process &process); 
bool operator>(const PriorityList &list, const Process &process); 
bool operator==(const PriorityList &lista, const PriorityList &listb); 
bool operator!=(const PriorityList &lista, const PriorityList &listb); 
bool operator<(const PriorityList &lista, const PriorityList &listb); 
bool operator>(const PriorityList &lista, const PriorityList &listb); 


#endif