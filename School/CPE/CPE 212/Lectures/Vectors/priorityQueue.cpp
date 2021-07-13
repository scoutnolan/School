#include <iostream>
#include <vector>
using namespace std;

// uses a vector to create a Binary Heap
class BinHeap{

private:
    vector<int> heapvector;
    int currentSize;

public:
    // initializes the vector and an attribute currentSize
    // as 0 to allow for interger division.
    BinHeap(vector<int> heapvector){
        this->heapvector = heapvector;
        this->currentSize = 0;
    }

    // prelocates and item as far up in the
    // tree as possible to maintain
    // the Heap property
    void reheapUp(int i){
        while ((i / 2) > 0){
            if (this->heapvector[i] > this->heapvector[i/2]){
                int tmp = this->heapvector[i/2];
                this->heapvector[i/2] = this->heapvector[i];
                this->heapvector[i] = tmp;
            }
            i = i/2;
        }

    }
    
    void insert(int value)
    {
        heapvector.push_back(value);
        int current = heapvector.size()-1;
        while(current != 1)
        {
            if(heapvector[current] > heapvector[current >> 1])
            {
                std::swap(heapvector[current], heapvector[current >> 1]);
                current >>= 1;
            }
            else break;
        }
    }

    // prelocates and item as far up in the
    // tree as possible to maintain
    // the Heap property
    void reheapDown(int i){
        while ((i*2) <= this->currentSize){
            int mc = this->maxChild(i);
            if (this->heapvector[i] > this->heapvector[mc]){
                int tmp = this->heapvector[i];
                this->heapvector[i] = this->heapvector[mc];
                this->heapvector[mc] = tmp;
            }
            i = mc;
        }
    }

    int maxChild(int i){
        if (((i*2)+1) > this->currentSize){
            return i * 2;
        }
        else{
            if (this->heapvector[i*2] > this->heapvector[(i*2)+1]){
                return i * 2 ;
            }
            else{
                return (i * 2) + 1;
            }
        }
    }

    // restores full complince with the heap structure
    // and heap order properties after the root is removed
    // by  taking the last item and moving it to the root position
    // and pushing the new root node down the tree to its proper postion.
    int delMin(){
        int retval = this->heapvector[1];
        this->heapvector[1] = this->heapvector[this->currentSize];
        this->currentSize = this->currentSize - 1;
        this->heapvector.pop_back();
        this->max_heapify(1);
        return retval;
    }

    void buildheap(vector<int> avector){
        int i = avector.size() / 2;
        this->currentSize = avector.size();
        this->heapvector.insert(this->heapvector.end(), avector.begin(), avector.end());
        while (i > 0){
            this->max_heapify(i);
            i = i - 1;
        }
    }
    

    bool isEmpty(){
        return heapvector.size() <= 1;
    }

    int findMin(){
        return this->heapvector[1];
    }


    void max_heapify(int index)
    {
        int largest = index;
        if((index << 1) < heapvector.size() && heapvector[largest] < heapvector[index << 1])
        {
            largest = index << 1;
        }
        if((index << 1) + 1 < heapvector.size() && heapvector[largest] < heapvector[(index << 1) + 1])
        {
            largest = (index << 1) + 1;
        }
        if(index != largest)
        {
            std::swap(heapvector[index], heapvector[largest]);
            max_heapify(largest);
        }
    }
    
};


int main(){
    // //int arr[] = {9, 5, 6, 2, 3};
    // int arr[] = {5, 56, 22, 67, 1, 6, 12};
    // vector<int> a(arr,arr+(sizeof(arr)/ sizeof(arr[0])));

    // vector<int> vec;
    // vec.push_back(0);

    // BinHeap *bh = new BinHeap(vec);
    // bh->buildheap(a);

    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;
    // cout << bh->delMax() << endl;

    // return 0;
    




    int arr[] = {25,14,16,13,10,8,12};

    vector<int> a(arr,arr+(sizeof(arr)/ sizeof(arr[0])));

    vector<int> vec;
    vec.push_back(0);

    BinHeap *bh = new BinHeap(vec);
    bh->buildheap(a);


    cout << bh->delMin() << endl;
    cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;
    // cout << bh->delMin() << endl;

    return 0;
}

