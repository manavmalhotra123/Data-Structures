#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string input = "manav malhotra";

    stack<char> st;

    for (int i = 0; i < input.length(); i++)
    {
        st.push(input[i]);
    }

    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    
    return 0;
}
