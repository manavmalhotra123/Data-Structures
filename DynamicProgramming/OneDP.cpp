// Recursion aana chahiye bs isse pehle

/*
DYNAMIC PROGRAMMING
- those who forget the past are condemned to repeat it
- never calculate the already calculated thing
- code optimize krwa dungi
- time compplexity bdia krwa dungi

Approaches;
1. Top Down (Recursion and memoisation)
2. Bottom Up (tabulation mehtod and iterative method)
3. space optimization (space ko km krna)

Overlapping Sub Problem -- same problem ko bar bar solve krna
optimal sub solution -- optimal solution of the small problem
*/
#include <iostream>
#include <vector>

using namespace std;
// Fibonacci series Function F(n) = F(n-1) + F(n-2)

// Using Recursion
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

/*
Dynamic programming problem identification
example: find the Fib(5)
        Tree
          F(5)
    F(4)       F(3)
F(3)   F(2)  F(2)  F(1)
.
.
here we can see that we have to find F(3) two times
making it overlapping sub problem
so, here we can apply DP
*/

// Top-down approach using memoization
int TopDownSolve(int n, vector<int> &dp)
{
    // base Case
    if (n == 0 || n == 1)
    {
        return n;
    }
    // check kro ki array mai answer hai if hai toh kaam bn gya time bch gya 
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        // nya ans bnaalo pichle do use krke jo already pde hai 
        dp[n] = TopDownSolve(n - 1, dp) + TopDownSolve(n - 2, dp);
    }
    // ans ko return maar diya 
    return dp[n];
}

int FibDP(int n)
{
    // making Dp array here
    vector<int> Dparray(n+1,-1);
    return TopDownSolve(n, Dparray);
} 

int main(int argc, char const *argv[])
{
    int n = 9;

    // Using recursion (original function)
    int ansRecursion = fib(n);
    cout << "Using Recursion: " << ansRecursion << endl;

    // Using top-down approach (with memoization)
    int DPResult = FibDP(n);
    cout << "Using top-down approach: " <<DPResult<<endl;
    return 0;
}
