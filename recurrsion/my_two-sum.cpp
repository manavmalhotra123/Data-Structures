#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(vector<int>& input, int target) {
    // Base case: If the target sum is 0, it has been achieved with no elements
    if (target == 0) {
        return 0;
    }

    int mini = INT_MAX; // Initialize the minimum count to a large value
    for (int i = 0; i < input.size(); i++) {
        if (input[i] <= target) { // Check if the current element can be used to reach the target
            int ans = solve(input, target - input[i]); // Recursively call the function with the reduced target
            if (ans != INT_MAX) { // If a valid count is returned from the recursive call
                mini = min(mini, ans + 1); // Update the minimum count if the current combination has fewer elements
            }
        }
    }

    if (mini == INT_MAX) {
        return -1; // If the minimum count remains INT_MAX, return -1
    } else {
        return mini; // Otherwise, return the minimum count
    }
}

int main() {
    vector<int> input = {1, 2}; // Input vector
    int target = 5; // Target sum

    int mini = solve(input, target); // Call the solve function to find the minimum count
    cout << mini; // Print the result

    return 0;
}
