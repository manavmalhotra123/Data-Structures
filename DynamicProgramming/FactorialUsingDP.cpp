#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// nhi lgegi dp isme 

// factorial recursion 
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

int factorialDynamics(int n) // Time Complexity O(2n)r
{
    vector<int> Dp(n + 1, -1);
    Dp[0] = 1;
    Dp[1] = 1;
    int ans = DPSolve(n, Dp);
    return ans;
}



// optimized version of factorial using Dp and constant space 
int factorialOptimized(int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}


// factorial using Bottom Up DP - O(N) time
int factorialDownUpDP(int n)
{
    vector<int> Dp(n + 1, -1);
    Dp[0] = 1;
    Dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        Dp[i] = i*Dp[i-1];
    }
    return Dp[n];
}




int main(int argc, char const *argv[])
{
    int n = 5;
    int ans = factorialrecurssion(n);
    cout << "result using recursion of factorial " << ans << endl;

    int dp = factorialDynamics(n);
    cout << "factorial using Dynamic Programming " << dp << endl;

    int bottomup = factorialDownUpDP(n);
    cout << "bottomup using Dynamic Programming " << bottomup << endl;
 
 
    int factopt = factorialOptimized(n);
    cout << "factorial using Dynamic Programming " << factopt << endl;
    return 0;
}