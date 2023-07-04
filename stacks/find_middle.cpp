#include<iostream>
#include<stack>

using namespace std;

void printMiddle(stack<int> &st, int &totalsize){
    // base case
    if (st.size() == totalsize/2) 
    {
        cout<<"Middle element is "<<st.top()<<endl;
        return;
    }
    
    // current element ko bhaar nikaal lo 
    int temp = st.top();
    st.pop();

    // recursive call 
    printMiddle(st,totalsize);

    // back track 
    st.push(temp);
}


int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int size = st.size();

    printMiddle(st,size);
    return 0;
}
