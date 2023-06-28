#include<vector>
#include<iostream>

using namespace std;


// Approach 1: using Loop 
void print_vector_using_loop(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Approach 2: using recursion
void print_vector_using_recursion(int n) {
    if (n == 0) {
        return;
    }
    
    print_vector_using_recursion(n - 1);
    cout << n << " ";
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    print_vector_using_loop(v);


    int n = 8;
    print_vector_using_recursion(n);
    return 0;
}
