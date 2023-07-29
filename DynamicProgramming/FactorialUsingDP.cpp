#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int factorialrecurssion(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorialrecurssion(n - 1);
}

// factorial using top down DP
int DPSolve(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    else
    {
        dp[n] = n * DPSolve(n-1,dp);
        return dp[n];
    }
}

int factorialDynamics(int n)
{
    vector<int> Dp(n + 1, -1);
    Dp[0] = 1;
    Dp[1] = 1;
    int ans = DPSolve(n, Dp);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int ans = factorialrecurssion(n);
    cout << "result using recursion of factorial " << ans << endl;

    int dp = factorialDynamics(n);
    cout << "factorial using Dynamic Programming " << dp << endl;

    return 0;
}