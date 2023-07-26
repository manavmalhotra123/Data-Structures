// heap

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Heap
{
    public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
    }

    void InsertValue(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parentindex = index / 2;

            if (arr[parentindex] < arr[index])
            {
                swap(arr[parentindex], arr[index]);
            }
            else
            {
                break;
            }
        }
    }

    void Show()
    {
        cout<<"Heap"<<endl;
        for (int i = 0; i <= size; i++)
        {
            cout << " " << arr[i] << " ";
        }
    }
};

int main(int argc, char const *argv[])
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;
    h.Show();

    h.InsertValue(110);
    h.Show();

    return 0;
}