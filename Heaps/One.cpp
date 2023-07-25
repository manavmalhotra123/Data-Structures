/*
Heap
visualised as Complete Binary Tree with Heap Property

Types of Heap;
1. Minimum heap
2. Maximum heap
*/

// Heap using Arrays
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// array ko level store krne ke liye use krenge
/*example:
        Maximum Heap
          100
          / \
        50   60
       / \   / \
      20 40 45 55
     / \
    5  10

---if array 1 based indexing ka huya toh---
root node ka index hoga i
left node ka index hoga 2*i
right node ka index hoga 2*i + 1

---if array 0 based indexing ka huya toh---
root node ka index hoga i
left node ka index hoga 2*i + 1
right node ka index hoga 2*i + 2


Using arrays (level Order kr liya ek trh se)
-1 100 50 60 20 40 45 55 5 10

----- Insertion in heap -----
suppose 57 insert krna hai heap mai
        Maximum Heap
            100
           /   \
        57      60
       /   \    /  \
     20    50  45  55
    / \   /
   5  10 40

*/

using namespace std;

class Heap
{
public:
  // to do array based implementation
  int array[101];
  int size;

  Heap()
  {
    size = 0;
  }

  void Insert(int value)
  {
    // value ko insert kro end mai
    size = size + 1;
    int index = size;
    array[index] = value;

    // is value ko ab uski shi position pr leke jaana hai
    // abhi toh yeh ek trah se last mai hai array ke
    while (index > 1)
    {
      // parent se compare krte krte upr jana hai
      int ParentIndex = index / 2;

      if (array[index] > array[ParentIndex])
      {
        swap(array[ParentIndex], array[index]);
        index = ParentIndex;
      }
      else
      {
        // loop se bhaar aaja bhai ab
        break;
      }
    }
  }

  // show heap function
  void ShowHeap()
  {
    cout<<"Heap:"<<endl;
    for (int i = 0; i < size; i++)
    {
      cout<<array[i]<<" ";
    }
    cout<<endl;
  }
};

int main()
{
  Heap h;
  h.array[0] = -1;
  h.array[1] = 100;
  h.array[2] = 50;
  h.array[3] = 60;
  h.array[4] = 40;
  h.array[5] = 45;
  h.size = 5;

  h.ShowHeap();

  // inserting the value in heap
  h.Insert(110);

  h.ShowHeap();

  h.Insert(57);
  h.ShowHeap();
  return 0;
}