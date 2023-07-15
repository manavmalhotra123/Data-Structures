// delete the middle element of the stack in O(N) 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

// function to print the stack 
void Show(stack<int> input)
{
    while (!input.empty())
    {
        cout<<input.top()<<endl;
        input.pop();
    }    
}

// delete the middle element of the stack in O(N)
void DeleteMiddleNode(stack<int> &input, int size)
{
    stack<int> support;
    int count = 0;
    int middle;
    if (size % 2 == 0)
    {
       middle = size / 2;
    }
    else
    {
        middle = (size / 2)+1;
    }
    while (count+1 < middle)
    {
        count++;
        support.push(input.top());
        input.pop();
    }
    input.pop();
    while(!support.empty()){
        input.push(support.top());
        support.pop();
    }   
}



int main(int argc, char const *argv[])
{
    stack<int> input;
    input.push(10);
    input.push(20);
    input.push(30);
    input.push(40);
    input.push(50);


    // funcion to delete the middle node 
    DeleteMiddleNode(input,5);

    // display
    Show(input);
    return 0;
}