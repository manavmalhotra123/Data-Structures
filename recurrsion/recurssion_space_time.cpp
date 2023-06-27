// when the function calls itslef then it is known as recurssion..
// jab ek bigger problem ka solution depend krta hu choti and same type ki problem pr tab recurssion use hoga 

// Example problem statement : input mai n milega and output 2^n

// Solution do honge either loop lgaado jisme saara kaam ho jaaye 
#include <iostream>
#include <cmath>

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

int main() {
    int n = 4;
    power_n(n);



    int val = power(n);
    cout<<val<<endl;

    return 0;
}
