// when the function calls itslef then it is known as recurssion..
// jab ek bigger problem ka solution depend krta hu choti and same type ki problem pr tab recurssion use hoga 

// Example problem statement : input mai n milega and output 2^n

// Solution do honge either loop lgaado jisme saara kaam ho jaaye 
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


// norma approach loop lgaado jisme saara kaam ho jaye 
void power_n(int n) {
    int val = 2;
    for (int i = 1; i < n; i++) {
        val = val * 2;
    }

    cout << val << endl;
}


// recurrsion lgaake dekhte hai ab hum log
int power(int n){
    if (n == 0) 
    {
        return 1;
    }
    else return 2*power(n-1);
}

// Problem Statement 2 -- factorial of a number

// approach 1 loop se krte hai try 
int fact_loop(int n){
    int val = 1;
    while(n > 0){
        val = n*val;
        n --;
    }
    return val;
}

// approach 2: recurssion
int fact_rec(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n*fact_rec(n-1);
}

// problem statement 3 : ek number input lo aur uske piche tk waale saare number print krdo in reverse

// printing vector
void print_vector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

// approach 1 : using for loop
void reverse_print(int n){
    vector<int> rev;
    rev.push_back(n);
    for (int i = 0; i <= n; i++)
    {
        n = n-1;
        rev.push_back(n);        
    }
    
   print_vector(rev);
    
}

// approach 2 : using recurssion 

std::vector<int> reverse_rec(int n) {
    std::vector<int> rev;

    if (n <= 0) {
        return rev;  // Base case: return an empty vector
    }

    rev.push_back(n);
    std::vector<int> rest = reverse_rec(n - 1);

    rev.insert(rev.end(), rest.begin(), rest.end());

    return rev;
}



int main() {
    int n = 4;
    power_n(n);



    int val = power(n);
    cout<<val<<endl;

    // problem statement 2
    int v = fact_loop(n);
    cout<<v<<endl;

    int r = fact_rec(n);
    cout<<r<<endl;

    // problem statement 3
    reverse_print(n);

    return 0;
}
