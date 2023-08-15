#include <iostream>
using namespace std;

class Solution{
public:
    // Function to calculate the maximum subarray sum
    int maxSubArraySum(int a[], int n) {
        int max_so_far = a[0];      // Initialize max_so_far and curr_max to the first element
        int curr_max = a[0];
    
        for(int i = 1; i < n; i++) {
            // Calculate the maximum of the current element and the current element + curr_max
            curr_max = max(a[i], curr_max + a[i]);
            // Update max_so_far with the maximum of max_so_far and curr_max
            max_so_far = max(max_so_far, curr_max);
        }
        
        // Return the maximum subarray sum
        return max_so_far;
    }
    
    // Function to calculate the maximum count of 0s (minimum count of 1s) in a subarray
    int maxOnes(int a[], int n) {
        int cnt = 0;  // Initialize a counter for the number of 1s
        
        for(int i = 0; i < n; i++) {
            if(a[i] == 0)
                a[i] = 1;   // Convert 0 to 1
            else {
                cnt++;      // Increment the counter for each 1 encountered
                a[i] = -1;  // Convert 1 to -1
            }
        }
        
        // Return the sum of 1s and the maximum subarray sum considering -1s
        return (cnt + maxSubArraySum(a, n));
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.maxOnes(arr, n);
    cout << "Maximum count of 0s (minimum count of 1s) in a subarray: " << result << endl;

    return 0;
}
