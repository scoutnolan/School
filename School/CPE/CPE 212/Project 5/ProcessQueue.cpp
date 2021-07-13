#include "ProcessQueue.hpp"

/// TODO
void ProcessQueue::PushProcess(const std::string & output, Priority p)
{
    Process process_new(output, p, _nextPID++);
    for(auto & proc : _data)
    {
        if(_data.empty()) 
            break;
        if(proc == process_new)
        {
            proc.Push(process_new);
            return;
        }
    }
    PriorityList new_item(process_new,p);
    _data.push_back(new_item);
    ReheapUpList(_data.size()-1);
}

/// TODO
void ProcessQueue::ExecuteNextProcess()
{
    Process process = _data.front().Pop();
    process.ExecuteProcess(std::cout);

    if(_data.front().IsEmpty())
    {
        _data.front().SwapList(_data.back());
        _data.pop_back();
        ReheapDownList(0);
    }
}

/// TODO
void ProcessQueue::ReheapUpList(int currentIndex)
{
    if(currentIndex == 0) return;
    int parent = (currentIndex - 1) / 2;
    if(_data[parent] > _data[currentIndex]) return;
    _data[parent].SwapList(_data[currentIndex]);
    ReheapUpList(parent);
}

/// TODO
void ProcessQueue::ReheapDownList(int currentIndex)
{
    int lastnumber = _data.size() -1;
    if(currentIndex > lastnumber) return;
    int leftchild = (currentIndex * 2) + 1;
    int rightchild = (currentIndex * 2) + 2;
    if(rightchild > lastnumber || leftchild > lastnumber) return;
    int high = leftchild;
    if(_data[rightchild] > _data[leftchild]) high = rightchild;
    if(_data[high] < _data[currentIndex]) return;
    _data[high].SwapList(_data[currentIndex]);
    ReheapDownList(high);
}

/// TODO
bool ProcessQueue::IsEmpty() const
{
    return _data.size() == 0;
}