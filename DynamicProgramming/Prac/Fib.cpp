// Fibonacci Series using dynamic programming

#include <iostream>
#include <vector>

using namespace std;

int TopDown(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = TopDown(n - 1, dp) + TopDown(n - 2, dp);
    return dp[n];
}

int Fib(int n)
{
    vector<int> DP(n + 1, -1);
    int ans = TopDown(n, DP);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 9;
    int result = Fib(n);
    cout << result << endl;

    return 0;
}