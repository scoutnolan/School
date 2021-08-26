#ifndef PROCESSQUEUE_HPP
#define PROCESSQUEUE_HPP

#include "Process.hpp"
#include "PriorityList.hpp"

#include <deque>
#include <iostream>


class ProcessQueue
{
    std::deque<PriorityList> _data;

    uint32_t _nextPID = 0;



    void ReheapUpList(int index);
    void ReheapDownList(int index);

public:
    ProcessQueue() = default;


    void PushProcess(const std::string & output, Priority p);
    void ExecuteNextProcess();

    bool IsEmpty() const;
};


#endif