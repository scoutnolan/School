#include "ProcessQueue.hpp"

#include <fstream>
#include <iostream>
#include <string>


static void TrimName(std::string & name)
{
    if(name.front() == ' ')
    {
        name.erase(0, 1);
    }
    if(name.front() == '\"')
    {
        name.erase(0, 1);
    }
    if(name.back() == '\"')
    {
        name.erase(name.size() - 1);   
    }
}

static std::string ReadName(std::ifstream &stream)
{
    int quoteCount = 0;
    std::string name;
    while(quoteCount < 2)
    {
        std::string tmp;
        stream >> tmp;
        for(const auto & c : tmp)
        {
            if(c == '\"')
            {
                quoteCount ++;
            }
        }
        name += tmp;
        if(quoteCount != 2)
        {
            name += " ";
        }
    }
    TrimName(name);
    return name;
}



int main(int argc, char* const argv[])
{
    std::ifstream inputs;
    std::string comment;

    char op;


    // Output usage message if test input file name is not provided
    if (argc != 2)
    {
        std::cout << "Usage:\n  P5 <inputfile>\n";
        return 1;
    }

    // Attempt to open test input file -- terminate if file does not open
    inputs.open(argv[1]);
    if (!inputs)
    {
        std::cout << "Error - unable to open input file" << std::endl;
        return 1;
    }

    std::cout << "Executing File: " << argv[1] << std::endl;

    ProcessQueue queue;

    inputs >> op;
    while(inputs)
    {
        switch(op)
        {
            case 'a':
                {
                    int prio;
                    inputs >> prio;
                    if(prio > 10)
                    {
                        std::cout << "INVALID PRIORITY CAUGHT" << std::endl;
                        return -1;
                    }
                    std::string processOutput = ReadName(inputs);
                    queue.PushProcess(processOutput, static_cast<Priority>(prio));
                    break;
                }

            case 'p':
                if(queue.IsEmpty())
                {
                    std::cout << "UNEXPECTED EMPTY QUEUE CAUGHT" << std::endl;
                    return -1;
                }
                queue.ExecuteNextProcess();
                break;

            default:
                std::cout << "UNEXPECTED INPUT CHAR CAUGHT: " << op << std::endl;
                return -1;
        }
        
        inputs >> op;
    }
}