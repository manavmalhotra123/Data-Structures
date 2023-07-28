#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kth_smallest(vector<int> input, int k)
{
    if (k < 1 || k > input.size())
        return -1;

    priority_queue<int, vector<int>, greater<int>> minHeap; // Create a min heap

    // Push the first k elements into the min heap
    for (int i = 0; i < k; i++)
    {
        minHeap.push(input[i]);
    }

    // For the remaining elements, if an element is smaller than the top of the min heap,
    // replace the top element with the current element and adjust the heap.
    for (int i = k; i < input.size(); i++)
    {
        if (input[i] < minHeap.top())
        {
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }

    return minHeap.top(); // The top of the min heap is the kth smallest element
}

int main()
{
    vector<int> input = {890, 10, 22, 33, 4, 5, 6};
    int k = 4;
    int kth_smallest_element = kth_smallest(input, k);

    return 0;
}
