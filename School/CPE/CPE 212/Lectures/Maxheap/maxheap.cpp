#include "maxheap.hpp"
// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - heap_size + 1;
    harr[i] = k;

    // Fix the max heap property if it is violated
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
        HeapSort(i);
    }
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MaxHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        // Swapping the current value at index i with its parent which is at (i-1)/2
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
        HeapSort(harr[parent(i)]);
    }
}

// Method to remove minimum element (or root) from min heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    HeapSort(0);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MaxHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMax();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int greatest = i;
    if (l < heap_size && harr[l] > harr[i])
        greatest = 1;
    if (r < heap_size && harr[r] > harr[greatest])
        greatest = r;
    if (greatest != i)
    {
        swap(&harr[i], &harr[greatest]);
        MaxHeapify(greatest);
    }
}

void MaxHeap::HeapSort(int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; i--)
        ReheapDown(i, n - 1);
    for(i = n - 1; i >= 1; i--)
    {
        swap(harr[0], harr[i]);
        ReheapDown( 0, i - 1);
    }
        
}

void MaxHeap::ReheapDown(int root, int bottom)
{
    int l = root*2+1;
    int r = root*2+2;
    int greatest;
    if(l <= bottom)
    {
        if(l == bottom)
            greatest = l;
        else
        {
            if(harr[l] <= harr[r])
                greatest = r;
            else
                greatest = l;
        }
        if(harr[root] < harr[greatest])
        {
            swap(harr[root], harr[greatest]);
            ReheapDown(greatest, bottom);
        }
    }
}

//Method to print out the contents of the heap
void MaxHeap::print() const {
    cout << "Printing the contents of the heap...\n";
    for (int i = 0; i < heap_size; i++)
    {
        cout << harr[i] << " ";
    }
    cout << "\n";
}


// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}