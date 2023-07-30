// Coin Change Problem
// ek array de rkha jisme coins de rkhe hai jisse ek amount ko create krna
// return the ways in which the coin change can be given

/*
It is a DP Problem as here we are facing overlapping sub problem
example available coins are 1,2,5
target = 11

possible  1,1,2,2,5
          1,1,2,5,2
          here we are doing the calculation of 1,1,2
          which is overlapping sub problem
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// inclusion exclusion
int coinRecursion(vector<int> &v, int amount, int index)
{
    if (amount == 0)
    {
        return 1; // completion of founding one way
    }

    if (amount < 0 || index < 0)
    {
        return 0; // gadbad hogi yha pr
    }

    // include case
    int include = coinRecursion(v, amount, index - 1);
    // exclude case
    int exclude = coinRecursion(v, amount - v[index], index);

    return include + exclude;
}

int coinchange(vector<int> &coins, int target)
{
    return coinRecursion(coins, target, coins.size() - 1);
}

int coinChangeDP(vector<int> &coins, int target)
{
    int number_of_coins = coins.size();
    // Dp array bna lo ab
    // as initially there is no ways
    vector<int> dp(target + 1, 0);

    // ek base case ko bnado that will be if the amount is zero jiska sirf ek hi case hoga
    dp[0] = 1;

    // considering rest of the cases
    for (int i = 0; i < number_of_coins; i++)
    {
        for (int j = coins[i]; j <= target; ++j)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[target];
}

int main(int argc, char const *argv[])
{
    vector<int> v = {2, 1, 5};
    int target = 11;
    int ans = coinchange(v, target);
    cout << ans << endl;

    int dp = coinChangeDP(v, target);
    cout << dp << endl;
    return 0;
}