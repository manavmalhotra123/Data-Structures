#include <iostream>
#include <stack>

using namespace std;

void Show(stack<int> s)
{
    if (s.empty())
    {
        cout<<"UNDERFLOW ERROR"<<endl;
    }
    
    cout<<"Stack: "<<endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void BottomPush(stack<int> &s, int data){
    // Base Case
    if (s.empty())
    {
        s.push(data);
        return;
    }

    // nhi toh pop krte rho
    int temp = s.top();
    s.pop();

    // recursive call 
    BottomPush(s, data);

    // Backtrack
    s.push(temp);

}

int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(20);
    st.push(25);


    Show(st);
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    BottomPush(st, 5);
    BottomPush(st, 15);
    BottomPush(st, 20);
    BottomPush(st, 25);

    Show(st);

    return 0;
}
