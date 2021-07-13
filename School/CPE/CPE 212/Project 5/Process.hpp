#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>
#include <iostream>
#include <stdint.h>



enum class Priority : uint32_t
{
    Low = 1,
    Rank1 = 2,
    Rank2 = 3,
    Rank3 = 4,
    Rank4 = 5,
    Rank5 = 6,
    Rank6 = 7,
    Rank7 = 8,
    Rank8 = 9,
    HIGH = 10,
};

std::string PriorityToString(Priority p);


class Process
{
    std::string _processOutput = "Blank Process";
    Priority _priority = Priority::Low;
    uint32_t _pid;

public:
    Process() = default;
    Process(const std::string & output, Priority p, uint32_t PID);

    void ExecuteProcess(std::ostream & os) const;

    uint32_t PID() const;
    Priority Prio() const;

    bool operator==(const Process &other) const;
    bool operator!=(const Process &other) const;
    bool operator<(const Process &other) const;
    bool operator>(const Process &other) const;
};

#endif