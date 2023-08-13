// Fibonacci series

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// pure recusion function
int recursion(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    else
    {
        return recursion(n - 1) + recursion(n - 1);
    }
}

// tabular dynamic programming
int solve(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    const int mod = 1000000007;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    int answer = recursion(3);
    cout << answer << endl;

    int dpans = solve(3);
    cout << dpans << endl;

    return 0;
}