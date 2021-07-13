#include <deque>
#include <string>

#include <iostream>

int main()
{
    std::deque<std::string> myDeque;
    myDeque.push_back("world");
    myDeque.push_back("hello");
    for(const auto & s : myDeque)
    {
        std::cout << s << " ";
    }

    std::cout << std::endl;
    
    myDeque.push_back("Rear");
    myDeque.push_front("Front");
    
    for(const auto & s : myDeque)
    {
        std::cout << s << " ";
    }

    std::cout << std::endl;


    std::deque<int> myQueue;
    for(int i = 0; i < 10; i++)
    {
        myQueue.push_front(i);
    }
    auto v = myQueue.back();
    myQueue.pop_back();
    std::cout << v << " popped from the queue" << std::endl;
    std::cout << "printing rest of queue: " << std::endl;

    for(const auto & v : myQueue)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;


    std::deque<int> myCopy;
    myCopy = myQueue;

    for(const auto & v : myCopy)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;



    myCopy.pop_front();


    std::cout << "printing out myCopy" << std::endl;

    for(const auto & v : myCopy)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;

    std::cout << "printing out myQueue: " << std::endl;

    for(const auto & v : myQueue)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;



}