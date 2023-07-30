#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive Approach
// Recursive function for the algorithm
int RecursiveRob(vector<int>& nums, int start, int end) {
    // Base case
    if (start > end) {
        return 0;
    }

    // Rob the current house (nums[start]) and continue to the next unrobbed house
    int choice1 = RecursiveRob(nums, start + 1, end);

    // Skip the current house and rob the one after the next
    int choice2 = nums[start] + RecursiveRob(nums, start + 2, end);

    return max(choice1, choice2);
}

// Recursive solution for the circular House Robber problem
int Rob(vector<int>& nums) {
    int n = nums.size();
    int case1 = RecursiveRob(nums, 0, n - 2); // Rob from the first house to the second-to-last house
    int case2 = RecursiveRob(nums, 1, n - 1); // Rob from the second house to the last house

    int answer = max(case1, case2);

    return answer;
}


// Top Down Approach for the code
int RobMemo(vector<int>& nums, int start, int end, vector<int>& dp) {
    // Base case
    if (start > end) {
        return 0;
    }

    // If the result is already computed and memoized, return it
    if (dp[start] != -1) {
        return dp[start];
    }

    // Rob the current house (nums[start]) and continue to the next unrobbed house
    int choice1 = RobMemo(nums, start + 1, end, dp);

    // Skip the current house and rob the one after the next
    int choice2 = nums[start] + RobMemo(nums, start + 2, end, dp);

    // Memoize the result for the current position
    return dp[start] = max(choice1, choice2);
}

// Top-down solution for the circular House Robber problem using memoization
int RobTopDown(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case: No houses to rob

        vector<int> dp(n, -1);

        // Rob from the first house to the second-to-last house
        int case1 = RobMemo(nums, 0, n - 2, dp);

        // Rob from the second house to the last house
        int case2 = RobMemo(nums, 1, n - 1, dp);

        // Consider the circular arrangement by choosing the maximum between case1 and case2
        return max(case1, case2);
}


int RobSmarter(vector<int>& nums) {
    int n = nums.size();

    // Base cases for n = 0 and n = 1
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // dp vectors to store the maximum loot for the two cases
    vector<int> dp1(n, 0); // Rob the first house but not the last
    vector<int> dp2(n, 0); // Rob the last house but not the first

    // Calculate the maximum loot when robbing the first house but not the last
    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    }

    // Calculate the maximum loot when robbing the last house but not the first
    dp2[1] = nums[1];
    dp2[2] = max(nums[1], nums[2]);
    for (int i = 3; i < n; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }

    // Take the maximum between the last elements of the two DP arrays to find the optimal solution for circular arrangement
    return max(dp1[n - 2], dp2[n - 1]);
}

int main() {
    vector<int> Houses = {1, 2, 3, 1};
    int answer = RobSmarter(Houses);
    cout << answer << endl;
    return 0;
}
