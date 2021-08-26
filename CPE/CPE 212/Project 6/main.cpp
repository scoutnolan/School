#include "merge_sort.hpp"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <random>

template<typename Type>
std::vector<Type> Generate(int size)
{
    std::vector<Type> val;
    val.reserve(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size * 5);

    for(int i = 0; i < size; i ++)
    {
        val.push_back(dist(gen));
    }

    return val;
}



template<typename Sortable>
bool CheckOrdering(const std::vector<Sortable> &input)
{
    if(input.size() == 1)
    {
        return true;
    }
    for(int i = 1; i < input.size() ; i ++)
    {
        if(input[i-1] > input[i])
        {
            return false;
        }
    }
    return true;
}

void OutputTime(std::chrono::steady_clock::duration time)
{
    using namespace std::chrono;
    using clock = std::chrono::steady_clock;
    if(time > seconds(100))
    {
        std::cout << duration_cast<seconds>(time).count() << "s" << std::endl;
    }
    else if(time > milliseconds(100))
    {
        std::cout << duration_cast<milliseconds>(time).count() << "ms" << std::endl;
    }
    else if(time > microseconds(100))
    {
        std::cout << duration_cast<microseconds>(time).count() << "us" << std::endl;
    }
    else
    {
        std::cout << duration_cast<nanoseconds>(time).count() << "ns" << std::endl;
    }
}


bool RunTest(int size, int count, int threshold)
{
    using namespace std::chrono;
    using clock = std::chrono::steady_clock;
    // int count = size / 4;

    std::vector<clock::duration> timingSequential, timingParallel;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Beginning size: " << size << std::endl;

    std::cout << "Running Sequential" << std::endl;
    for(int i = 0; i < count; i ++)
    {
        std::vector<int> val = Generate<int>(size);

        auto startS = clock::now();
        auto sortedS = MergeSort_Linear(val);
        auto endS = clock::now();



        timingSequential.push_back(endS - startS);

        if(!CheckOrdering(sortedS))
        {
            std::cout << "Error with sort: Sequential" << std::endl;
            return false;
        }
    }

    std::cout << "Running parallel" << std::endl;
    for(int i = 0; i < count; i ++)
    {
        std::vector<int> val = Generate<int>(size);
        auto startA = clock::now();
        auto sortedA = MergeSort_Parallel(val, threshold);
        auto endA = clock::now();

        timingParallel.push_back(endA - startA);

        if(!CheckOrdering(sortedA))
        {
            std::cout << "Error with sort: Parallel" << std::endl;
            return false;
        }
    }
    auto sequential = std::accumulate(timingSequential.begin(), timingSequential.end(), clock::duration()) / timingSequential.size();
    auto parallel = std::accumulate(timingParallel.begin(), timingParallel.end(), clock::duration()) / timingParallel.size();

    std::cout << "Sequential Time: ";
    OutputTime(sequential);
    std::cout << "Parallel Time: ";
    OutputTime(parallel);
}

int main(int args, char** argc)
{
    if(args < 2)
    {
        std::cout << "Must use a threshold" << std::endl;
        return -1;
    }
    int threshold = atoi(argc[1]);
    std::cout << "Running with threshold of: " << threshold << std::endl;
    RunTest(100, 1000, threshold);
    RunTest(500, 500, threshold);
    RunTest(1000, 500, threshold);
    RunTest(10000, 250, threshold);
    RunTest(25000, 250, threshold);
    RunTest(50000, 250, threshold);
    RunTest(100000, 125, threshold);
    RunTest(250000, 100, threshold);
    RunTest(500000, 50, threshold);
    RunTest(1000000, 25, threshold);
    RunTest(2500000, 15, threshold);
    RunTest(5000000, 10, threshold);


    return 0;
}