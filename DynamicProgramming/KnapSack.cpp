#include <iostream>
#include <vector>
using namespace std;

// index = index  of last element
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

  // include and excludeS
  int include = 0;
  if (weight[index] <= capacity)
    include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);

  int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

  int ans = max(include, exclude);
  return ans;
}

// knapsack function using top down approach in DP
int topDownDP(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
  // Base case
  if (index == 0)
  {
    if (weight[0] <= capacity)
    {
      dp[index][capacity] = value[0]; // Store the result in the memoization table
      return value[0];
    }
    else
    {
      dp[index][capacity] = 0; // Store the result in the memoization table
      return 0;
    }
  }

  // Check if it already exists in the memoization table
  if (dp[index][capacity] != -1)
  {
    return dp[index][capacity];
  }

  int include = 0;
  if (weight[index] <= capacity)
  {
    include = value[index] + topDownDP(weight, value, index - 1, capacity - weight[index], dp);
  }

  int exclude = topDownDP(weight, value, index - 1, capacity, dp);

  dp[index][capacity] = max(include, exclude); // Store the result in the memoization table
  return dp[index][capacity];
}

int topDownDP(int wt[], int val[], int n, int cap)
{
  // create a dp array
  // 2-D dp array bna liya jisko -1 se initiate kr diya
  vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));

  int answer = topDownDP(wt, val, n - 1, cap, dp);
  return answer;
}

// Using Bottom Up Approach - tabulation method
int knapsackTabular(int weight[], int value[], int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{

  int weight[] = {4, 5, 1};
  int value[] = {1, 2, 3};
  int n = 3;
  int capacity = 4;

  // int ans = solveUsingRecursion(weight, value, n-1, capacity);

  // vector<vector<int> > dp(n, vector<int>(capacity+1 , -1));
  // int ans = solveUsingMem(weight, value, n-1, capacity, dp);

  int ans = topDownDP(weight, value, n, capacity); // Corrected the function call here
  cout << "Ans using top-down DP: " << ans << endl;

  int a = knapsackTabular(weight, value, n, capacity); // Corrected the function call here
  cout << "Ans using tabular method: " << a << endl;

  return 0;
}
