#include "PriorityList.hpp"

PriorityList::PriorityList(const Process &process, Priority priority) : 
        _priority(priority)
{
    _tasks.push_back(process);
}


/// TODO
void PriorityList::SwapList(PriorityList &otherList)
{
    
    this->_tasks.swap(otherList._tasks);
    Priority priority = this->Prio();
    this->_priority = otherList._priority;
    otherList._priority = priority;
}


/// TODO
Process PriorityList::Pop()
{
    Process process = _tasks.back();
    _tasks.pop_back();
    return process;
}

void PriorityList::Push(const Process & process)
{
    _tasks.push_front(process);
}

Priority PriorityList::Prio() const
{
    return _priority;
}

bool PriorityList::IsEmpty() const
{
    return _tasks.size() == 0;
}

bool operator==(const Process &process, const PriorityList &list)
{
    return process.Prio() == list.Prio();
}

bool operator!=(const Process &process, const PriorityList &list)
{
    return process.Prio() != list.Prio();
}

bool operator>(const Process &process, const PriorityList &list)
{
    return process.Prio() > list.Prio();
}

bool operator<(const Process &process, const PriorityList &list)
{
    return process.Prio() < list.Prio();
}

bool operator==(const PriorityList &list, const Process &process)
{
    return list.Prio() == process.Prio();
}

bool operator!=(const PriorityList &list, const Process &process)
{
    return list.Prio() != process.Prio();
}

bool operator>(const PriorityList &list, const Process &process)
{
    return list.Prio() > process.Prio();
}

bool operator<(const PriorityList &list, const Process &process)
{
    return list.Prio() < process.Prio();
}


bool operator==(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() == listb.Prio();
}

bool operator!=(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() != listb.Prio();
}

bool operator>(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() > listb.Prio();
}

bool operator<(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() < listb.Prio();
}



//_tempList = _tasks;
    //_tasks = otherList;
    //otherList = _tempList;
    // std::deque<Process> job;
    // Priority priority_job;
    // job = this->_tasks;
    // priority_job = this->_priority;
    // std::deque<Process> tmp; 
    // Priority tmp_priority;
    // tmp = otherList._tasks;
    // tmp_priority = otherList._priority;
    // otherList._priority = priority_job;
    // otherList._tasks = job;
    // this->_tasks = tmp;
    // this->_priority = tmp_priority;