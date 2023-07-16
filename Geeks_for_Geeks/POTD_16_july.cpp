// reversal of the queue 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

void Show(queue<int> input)
{
    cout<<"Queue: ";
    while (!input.empty())
    {
        cout<<input.front()<<" ";
        input.pop();
    }
    cout<<endl;
}


void Reversal(queue<int> &input)
{
    stack<int> supporter;
    while (!input.empty())
    {
        supporter.push(input.front());
        input.pop();
    }
    while (!supporter.empty())
    {
        input.push(supporter.top());
        supporter.pop();
    }   
}

int main(int argc, char const *argv[])
{

    queue<int> Q;
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);

    Show(Q);
 
    Reversal(Q);

    Show(Q);
    return 0;
}