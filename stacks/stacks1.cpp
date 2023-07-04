// Stack is the type of Data Structure 
// Items are stored in LIFO order (Last In First Out)

#include <iostream>
#include <stack>

using namespace std;

// print function for stack 
void PrintStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}



int main(int argc, char const *argv[])
{
    // declaring the stack using STL
    stack<int> s;

    // Push Operation on stack to enter the value 
    s.push(10);
    s.push(20);    
    s.push(30);    
    s.push(40);

    // s.top() - used to check the value at top of the stack 
    cout<<s.top()<<endl;    
    s.pop();
    cout<<s.top()<<endl;


    // checking the size of the stack
    cout<<"The size of the stack is "<<s.size()<<endl;
    

    stack <int> st;
    // checking whether the stack is empty or not 
    cout<<st.empty()<<endl; // output 1 for empty stack and 0 for non empty stack

    // printing the stack 
    PrintStack(s);
    
    cout<<"Top Element of the stack is "<<s.top()<<endl;


    return 0;
}
