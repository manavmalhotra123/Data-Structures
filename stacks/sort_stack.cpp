#include <string>
#include <stack>
#include <iostream>
#include <iomanip>

using namespace std;

void Show(stack <int> st){
    cout<<"Stack: "<<endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void sortStack(stack<int>& original)
{
    stack<int> temporary;

    while (!original.empty())
    {
        int temp = original.top();
        original.pop();

        while (!temporary.empty() && temporary.top() > temp)
        {
            original.push(temporary.top());
            temporary.pop();
        }

        temporary.push(temp);  // Insert the 'temp' variable into the 'temporary' stack
    }

    // Copy elements from 'temporary' stack back to 'original' stack
    while (!temporary.empty())
    {
        original.push(temporary.top());
        temporary.pop();
    }
}

int main(int argc, char const *argv[])
{
    stack <int> st;
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(2);

    Show(st);  // Display the original stack

    sortStack(st);  // Sort the stack

    Show(st);  // Display the sorted stack

    return 0;
}
