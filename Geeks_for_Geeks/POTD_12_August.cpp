// longest increasing subsequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubsequence(int n, int arr[]) {
    vector<int> dp(n, 1);  // Initialize DP array with 1, as each element is a valid subsequence of length 1
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = longestSubsequence(n, arr);
    cout << ans << endl;
}
