#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// complexity - nlog(n)
// recursive function - to put the element in right position in heap
void Heapify(int arr[], int size, int i)
{
        // current element
        int index = i;
        // left child
        int left = 2 * i;
        // right child
        int right = 2 * i + 1;
        // to track the right position
        // assuming the element is at right position
        int largest = index;

        // if the element at left child is greater
        if (left <= size && arr[left] > arr[largest])
        {
                // update the correct position
                largest = left;
        }
        // if the element at right child is greater
        if (right <= size && arr[right] > arr[largest])
        {
                // update the correct position
                largest = right;
        }

        // if the correct position is not equal to current
        if (largest != index)
        {
                // swap the elements
                swap(arr[largest], arr[index]);
                index = largest;
                // krte rho jb tk shi jgh pr naah aa jaaye
                Heapify(arr, size, index);
        }
}

// using heapify function to build the heap
// no need to heapify leaf nodes
// leaf nodes - (n/2 + 1) to n nodes
void buildHeap(int arr[], int size)
{
        for (int i = size / 2; i > 0; i--)
        {
                Heapify(arr, size, i);
        }
}

// heap sort

// first element ko last se swap kro
// nye first element ko heapify krdo
void HeapSort(int arr[], int size)
{
        for (int i = size; i > 0; i--)
        {
                swap(arr[1], arr[i]);
                Heapify(arr, size, i);
        }
}

int main(int argc, char const *argv[])
{
        int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
        int n = 11;
        buildHeap(arr, n);

        cout << "printint the heap " << endl;
        for (int i = 1; i <= n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
}