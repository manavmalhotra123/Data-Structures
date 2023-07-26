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

---- Deletion in heap is always done from top ---
Step 1: delete krdo 
Step 2: replace last value with root node
Step 3: ab sabhi values ko uski shi jgh pr rkhdo 
*/
using namespace std;

class Heap
{
public:
  int array[101];
  int size;

  Heap()
  {
    size = 0;
  }

  void Insert(int value)
  {
    size = size + 1;
    int index = size;
    array[index] = value;

    while (index > 1)
    {
      int ParentIndex = index / 2;

      if (array[index] > array[ParentIndex])
      {
        swap(array[ParentIndex], array[index]);
        index = ParentIndex;
      }
      else
      {
        break;
      }
    }
  }

  void Delete()
  {
    // Replace the first value with the last value
    swap(array[1], array[size]);
    // Decrease the size
    size--;

    // Correct the positions of each element
    int index = 1;

    while (index <= size)
    {
      int leftChildIndex = 2 * index;
      int rightChildIndex = 2 * index + 1;
      int largest = index; // Initialize the index of the largest element as the root (current index)

      // Compare the left child with the current index
      if (leftChildIndex <= size && array[leftChildIndex] > array[largest])
      {
        largest = leftChildIndex;
      }

      // Compare the right child with the current largest index
      if (rightChildIndex <= size && array[rightChildIndex] > array[largest])
      {
        largest = rightChildIndex;
      }

      // If the largest element is not the root, then swap it with the correct child
      if (largest != index)
      {
        swap(array[largest], array[index]);
        index = largest;
      }
      else
      {
        // If the largest element is already the root, we're done
        break;
      }
    }
  }

  void ShowHeap()
  {
    cout << "Heap: ";
    for (int i = 1; i <= size; i++)
    {
      cout << array[i] << " ";
    }
    cout << endl;
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

  h.Insert(110);

  h.ShowHeap();

  h.Insert(57);
  h.ShowHeap();

  cout << "deletion ko dekhte huye..." << endl;
  h.Delete();
  h.ShowHeap();

  return 0;
}
