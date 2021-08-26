#include <vector>
#include <iostream>
#include <future>

template<typename Sortable>
std::vector<Sortable> Merge(const std::vector<Sortable> & left, const std::vector<Sortable> & right)
{
    size_t l = 0, r = 0;
	std::vector<Sortable> result;
	while (l < left.size() && r < right.size())
	    if (left[l] < right[r])
	        result.push_back(left[l++]);
	    else
	        result.push_back(right[r++]);
    
	while (l  < left.size()) 
        result.push_back(left [l++ ]);
    
	while (r < right.size()) 
        result.push_back(right[r++]);
	return result;
}


template<typename Sortable>
std::vector<Sortable> MergeSort_Linear(const std::vector<Sortable> &input)
{
    if(input.size() > 1)
    {
        auto left = MergeSort_Linear(std::vector<Sortable>(input.begin(), input.begin() + input.size() / 2));
        auto right = MergeSort_Linear(std::vector<Sortable>(input.begin() + (input.size() / 2), input.end()));
        return Merge(left, right);
    }
    return input;
}

template<typename Sortable>
std::vector<Sortable> MergeSort_Parallel(const std::vector<Sortable> &input, uint32_t Threshold)
{
    if(input.size() > Threshold)
    {
        auto left = std::async(std::launch::async, MergeSort_Parallel<Sortable>, std::vector<Sortable>(input.begin(), input.begin() + input.size() / 2), Threshold);
        auto right = std::async(std::launch::async, MergeSort_Parallel<Sortable>, std::vector<Sortable>(input.begin() + (input.size() / 2), input.end()), Threshold);
        return Merge(left.get(), right.get());
    }
    else if(input.size() > 1)
    {
        auto left = MergeSort_Linear(std::vector<Sortable>(input.begin(), input.begin() + input.size() / 2));
        auto right = MergeSort_Linear(std::vector<Sortable>(input.begin() + (input.size() / 2), input.end()));
        return Merge(left, right);
    }
    return input;
}




// std::vector<Sortable> result;
//     while (left.size() > 0 || right.size() > 0) {
//         if (left.size() > 0 && right.size() > 0) {
//             if (left.front() <= right.front()) {
//                 result.push_back(left.front());
//                 //left.clear();
//             } 
//     else {
//                 result.push_back(right.front());
//                 //right.clear();
//             }
//         }  else if (left.size() > 0) {
//                 for (int i = 0; i < left.size(); i++)
//                 result.push_back(left[i]);
//                 break;
//         }  else if (right.size() > 0) {
//                 for (int i = 0; i < right.size(); i++)
//                 result.push_back(right[i]);
//                 break;
//         }
//     }

//     return result;