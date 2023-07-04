#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
    vector<int> data;

    void push(int value)
    {
        data.push_back(value);
    }

    void pop()
    {
        if (!data.empty())
        {
            data.pop_back();
        }
        else
        {
            cout << "ERROR: Stack is empty!" << endl;
        }
    }

    int peek()
    {
        if (!data.empty())
        {
            return data.back();
        }
    }

    bool isEmpty()
    {
        return data.empty();
    }


    void printStack(){
        cout<<"Stack: "<< endl;
        for (int i = data.size() -1 ; i > -1; i--)
        {
            cout<<data[i]<<endl;
        }
        cout<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Stack mystack;
    mystack.push(50);
    mystack.push(60);
    mystack.push(70);
    mystack.push(80);
    mystack.printStack();

    mystack.pop();

    mystack.printStack();
    return 0;
}
