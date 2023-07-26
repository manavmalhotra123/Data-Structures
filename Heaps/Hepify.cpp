#include <iostream>
#include <algorithm>

using namespace std;

void Heapify(int arr[], int size, int Index)
{
    int LeftChildIndex = 2 * Index;
    int RightChildIndex = 2 * Index + 1;
    int Largest = Index;

    if (LeftChildIndex <= size && arr[Largest] < arr[LeftChildIndex])
    {
        Largest = LeftChildIndex;
    }

    if (RightChildIndex <= size && arr[Largest] < arr[RightChildIndex])
    {
        Largest = RightChildIndex;
    }

    if (Largest != Index)
    {
        swap(arr[Index], arr[Largest]);
        Heapify(arr, size, Largest);
    }
}

void ConvertToHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        Heapify(arr, size, i);
    }
}

void Show(int arr[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6];
    arr[1] = 40;
    arr[2] = 45;
    arr[3] = 50;
    arr[4] = 60;
    arr[5] = 100;

    Show(arr, 5);
    ConvertToHeap(arr, 5);
    Show(arr, 5);

    return 0;
}
