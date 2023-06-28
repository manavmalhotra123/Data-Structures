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
void print_vector_recursive(const vector<int>& vec, int index) {
    // base condition 
    if (index >= vec.size()) {
        return;
    }
    
    cout << vec[index] << " ";
    // process each element
    print_vector_recursive(vec, index + 1);
}

// Function to print the number in ascending order till number n using recursion
// tail recursion
void print_using_recursion_in_ascending(int n) {
    if (n == 0) {
        return;
    }
    
    print_using_recursion_in_ascending(n - 1);
    cout << n << " ";
}

// Function to print the number in descending order
// Head recursion
void print_using_recursion_in_descending(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    print_using_recursion_in_descending(n - 1);
    
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6,7,8};

    // print the vector using loop
    print_vector_using_loop(v);

    // printing vector using recursion
    print_vector_recursive(v, 1);
    cout<<endl;
    
    // n variable
    int n = 8;
    
    // print the number in ascending order
    print_using_recursion_in_ascending(n);
    return 0;
}
