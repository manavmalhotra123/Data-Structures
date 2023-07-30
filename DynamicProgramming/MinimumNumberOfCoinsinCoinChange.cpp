#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int Solve(vector<int> coins, int amount)
{
    // base case solve kro ab
    if (amount == 0)
    {
        return 0;
    }
    // invalid amount ka case
    if (amount < 0)
    {
        return INT16_MAX;
    }

    // loop lgane ke liye limit
    int number_of_coins = coins.size();
    // dummy solution
    int mini = INT16_MAX;

    // check for each case
    for (int i = 0; i < number_of_coins; i++)
    {
        // ans = amount - coin used
        int ans = Solve(coins, amount - coins[i]);
        // if the coin is accepted then add the solution
        if (ans != INT16_MAX)
        {
            // keep tracking the minimum number coins were accepted
            mini = min(mini, ans + 1);
        }
    }
    // return the minimum number of coins used
    return mini;
}

int CoinChangeRecursion(vector<int> coins, int amount)
{
    int answer = Solve(coins, amount);
    if (answer == INT16_MAX)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}

/*
It is the problem of Dynamic programming as we are facing the issue of overlapping
subproblems
--> because we need to find the sum every time we using some same order of coins
*/
// Dynamic programming se krte hai ab isko
int CoinChangeDP(vector<int> &coins, int amount)
{
        vector<int> dp(amount+1,INT16_MAX);
        dp[0]=0;
        for(int target=1;target<=amount;target++){
            int mini=INT16_MAX;
            for(int i=0;i<coins.size();i++){
                if(target-coins[i]>=0){
                    int ans=dp[target-coins[i]];
                    if(ans!=INT16_MAX)
                        mini=min(mini,1+ans);
                }
            }
            dp[target]=mini;
        } 
        return dp[amount];
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int target = 11;

    int ans = CoinChangeRecursion(coins, target);
    cout << ans << endl;


    int dpans = CoinChangeDP(coins, target);
    cout << dpans << endl;
    return 0;
}