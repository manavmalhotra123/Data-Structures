#include<iostream>


using namespace std;



// fibonacci series function using recursive function
int fibo(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // Recursive calls
    return fibo(n - 1) + fibo(n - 2);
}


int main(int argc, char const *argv[])
{
    int n = 4;
    int f = fibo(n);
    cout<<f<<endl;
    return 0;
}
