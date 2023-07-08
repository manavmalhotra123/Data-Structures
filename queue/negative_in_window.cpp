#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void Show(queue<int> input){
    while (!input.empty())
    {
        cout<<input.front()<<" ";
        input.pop();
    }
    cout<<endl;
}


void Window(queue<int> input, int windowSize){
    stack<int> s;
    while (!input.empty())
    {
        
    }
    
}

int main(int argc, char const *argv[])
{
    queue<int> Q;
    Q.push(12);
    Q.push(-1);
    Q.push(-7);
    Q.push(8);
    Q.push(-15);
    Q.push(30);
    Q.push(16);
    Q.push(18);
    return 0;
}
