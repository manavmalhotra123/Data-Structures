// coin exchange problem

// using 1-D Dp array
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {
        vector<long long int> dp(sum + 1, 0);

        // Base case: There's one way to make a sum of 0 using no coins.
        dp[0] = 1;

        for (int i = 0; i < N; ++i)
        {
            for (int s = coins[i]; s <= sum; ++s)
            {
                dp[s] += dp[s - coins[i]];
            }
        }

        return dp[sum];
    }
};

// using recursive function
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {
        if(N == 0)
        {
            return 0;
        }
        if (N<=0 || sum < 0)
        {
            return 0;
        }

        long long int include = count(coins,N-1,sum-coins[N]);
        long long int exclude = count(coins,N-1,sum);
    }
};