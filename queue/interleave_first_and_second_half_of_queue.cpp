#include<queue>
#include<iostream>

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

void interleave(queue<int> &input)
{
    queue<int> first;
    queue<int> second;
    int size = input.size();
    int count = 0;

    while (count < size/2)
    {
        first.push(input.front());
        input.pop();
        count++;
    }
    while (!input.empty())
    {
        second.push(input.front());
        input.pop();
    }
    
    
    while (!first.empty() && !second.empty())
    {
        input.push(second.front());
        second.pop();
        input.push(first.front());
        first.pop();
    }

    Show(input);
    
}


int main(int argc, char const *argv[])
{
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);

    Show(Q);

    cout<<endl;
    interleave(Q);
    return 0;
}
