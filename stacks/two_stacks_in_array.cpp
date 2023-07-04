// applying two stack in one single array

#include <iostream>

using namespace std;

class TwoStacks
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if ((top2 - top1) >= 1 && arr != NULL)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack 1 is in OVERFLOW condition.." << endl;
            return;
        }
    }
    void push2(int data)
    {
        if ((top2 - top1) >= 1 && arr != NULL)
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop1()
    {
        if (top1 >= 0)
        {
            int element = arr[top1];
            top1--;
            cout << "Element popped out is " << element << endl;
        }
        else
        {
            cout << "STACK 1 is Empty!!" << endl;
        }
    }

    void pop2()
    {
        if (top2 < size)
        {
            int element = arr[top2];
            top2++;
            cout << "Element popped out is " << element << endl;
        }
        else
        {
            cout << "STACK 2 is empty!!" << endl;
        }
    }


    void Show(){
        cout<<"Stack 1:"<<endl;
        for (int i = top1; i >= 0; i--)
        {
            cout<<arr[i]<<endl;
        }

        cout<<endl;

        cout<<"Stack 2:"<<endl;
        for (int j = top2; j < size; j++)
        {
            cout<<arr[j]<<endl;
        }
        
        
    }
};

int main(int argc, char const *argv[])
{
    TwoStacks stacks(6);

    stacks.push1(1);
    stacks.push1(2);
    stacks.push2(3);
    stacks.push2(4);

    stacks.Show();

    stacks.pop1();
    stacks.pop2();
    return 0;
}
