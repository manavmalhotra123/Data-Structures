#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>

using namespace std;

int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case -> only 1 item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int Memo(vector<vector<int>> &dp, int weight[], int value[], int capacity, int index)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    if(dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if(weight[index] <= capacity)
    {
        include = value[index] + Memo(dp, weight, value, capacity - weight[index], index - 1);
    }
    int exclude = 0 + Memo(dp, weight, value, capacity, index - 1);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int DpSolver(int weight[], int values[], int capacity, int index)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    int answer = Memo(dp, weight, values, capacity, index);
    return answer;
}

int main()
{
    int n = 3;
    int weight[] = {4, 5, 1};
    int profits[] = {1, 2, 3};
    int capacity = 4;

    int answer = solveUsingRecursion(weight, profits, n, capacity);
    cout << answer << endl;

    int dp = DpSolver(weights,values, capacity,n);

    return 0;
}
