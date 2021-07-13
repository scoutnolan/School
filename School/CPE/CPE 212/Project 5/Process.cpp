#include "Process.hpp"

std::string PriorityToString(Priority p)
{
    switch(p)
    {
        case Priority::Low:
            return "Low";
        case Priority::Rank1:
            return "Rank1";
        case Priority::Rank2:
            return "Rank2";
        case Priority::Rank3:
            return "Rank3";
        case Priority::Rank4:
            return "Rank4";
        case Priority::Rank5:
            return "Rank5";
        case Priority::Rank6:
            return "Rank6";
        case Priority::Rank7:
            return "Rank7";
        case Priority::Rank8:
            return "Rank8";
        case Priority::HIGH:
            return "HIGH";
    }
}


Process::Process(const std::string & output, Priority p, uint32_t PID) : 
    _processOutput(output), 
    _priority(p),
    _pid(PID)
{

}

void Process::ExecuteProcess(std::ostream & os) const
{
    os << "Process: " << _pid << std::endl;
    os << "\tPriority: " << PriorityToString(_priority) << std::endl;
    os << "\t" << _processOutput << std::endl;
}

uint32_t Process::PID() const
{
    return _pid;
}

Priority Process::Prio() const
{
    return _priority;
}

bool Process::operator==(const Process &other) const
{
    return _priority == other.Prio();
}

bool Process::operator!=(const Process &other) const
{
    return ! (*this == other);
}

bool Process::operator<(const Process &other) const
{
    return this->Prio() < other.Prio();
}

bool Process::operator>(const Process &other) const
{
    return this->Prio() > other.Prio();
}

