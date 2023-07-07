#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void Show(queue<int> input){
    cout<<"Queue: ";
    while (!input.empty())
    {
        cout<<input.front()<<" ";
        input.pop();
    }
    cout<<endl;
}

// reverse function using stack 
void Reverse(queue<int> &input){
    stack<int> gamechanger;
    while (!input.empty())
    {
        gamechanger.push(input.front());
        input.pop();
    }
    while (!gamechanger.empty())
    {
        input.push(gamechanger.top());
        gamechanger.pop();
    }
}


int main(int argc, char const *argv[])
{
    queue<int> Q;
    Q.push(1);    
    Q.push(2);    
    Q.push(3);    
    Q.push(4);
    Show(Q);   
    cout<<"reverse ";
    Reverse(Q);
    Show(Q); 
    return 0;
}
