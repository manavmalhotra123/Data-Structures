
class Solution {
public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        vector<int> dp(n, 0);

        // Base case: each individual character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        // Fill the dp array in a bottom-up manner
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;  // stores the value of dp[i+1][j-1] (previous diagonal element)
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];  // stores the value of dp[i][j-1] before it gets updated
                if (A[i] == A[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        return dp[n - 1];
    }
};
