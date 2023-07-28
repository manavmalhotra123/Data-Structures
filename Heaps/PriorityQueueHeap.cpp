// Heap using priority queue
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    // priority queue initialization

    // By default max heap create hoga isme
    priority_queue<int> pq;
    // Max Heap : Parent greater than child node
    // Min Heap : Parent less than child

    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // Min Heap : using priority queue
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    MinHeap.push(3);
    MinHeap.push(6);
    MinHeap.push(8);
    MinHeap.push(9);
    MinHeap.push(10);

    cout << "Printing the Min Heap....." << endl;
    while (!MinHeap.empty())
    {
        cout << MinHeap.top() << " ";
        MinHeap.pop();
    }

    return 0;
}