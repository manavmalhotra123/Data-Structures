#include <vector>
#include <algorithm>

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        // Step 1: Sort the array in ascending order
        sort(a.begin(), a.end());
        
        long long left = 0, right = m - 1;
        long long minDifference = LLONG_MAX; // Initialize with the maximum possible value for long long

        // Step 4: Use sliding window approach to find the minimum difference
        while (right < n) {
            long long difference = a[right] - a[left]; // Step 4a
            minDifference = min(minDifference, difference); // Step 4b
            left++; // Step 4c
            right++; // Step 4d
        }

        return minDifference;
    }
};
