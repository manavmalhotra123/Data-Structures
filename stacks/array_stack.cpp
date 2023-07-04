#include <iostream>

using namespace std;

// Class Stack
class Stack
{
// Inaccessible data members of the stack    
private:
    int *arr;
    int top;
    int size;

public:
    // intializes the stack of elements = SIZE
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1; // initally the toop of the stack is -1 
    }

    // function
    void push(int data)
    {
        // check whether the stack is full or not 
        if (top == size - 1)
        {
            cout << "STACK OVERFLOW!!" << endl;
            return;
        }
        // if not full,then shift to upper position
        top++;
        // insert data at upper position
        arr[top] = data;
    }

    void pop()
    {
        // check whether the stack is empty or not
        if (top == -1)
        {
            cout << "STACK UNDERFLOW!!, Nothing can be pop out..." << endl;
            return;
        }
        // top ko decrement krdo 
        top--;
    }

    // accessing the top element of the stack
    int Top()
    {
        // check for the empty values
        if (top == -1)
        {
            cout << "STACK IS EMPTY!!, Nothing is here.." << endl;
            return -1;
        }
        // returning the value at the top of the stack
        return arr[top];
    }

    int Size()
    {
        return (top + 1);
    }

    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "STACK IS EMPTY!!, Nothing is here.." << endl;
            return;
        }
        else
        {
            cout << "STACK" << endl;
            while (top != -1)
            {
                cout << arr[top] << endl;
                top--;
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
