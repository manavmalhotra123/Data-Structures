// Find the minimum missing positive value in the array


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) {
        // Segregate positive and non-positive numbers
        int shift = segregate(arr, n);
        
        // Iterate over the positive numbers and mark visited indices
        for (int i = shift; i < n; i++) {
            int num = abs(arr[i]);
            if (num + shift <= n)
                arr[num + shift - 1] = -abs(arr[num + shift - 1]);
        }
        
        // Find the first positive element indicating the missing number
        for (int i = shift; i < n; i++) {
            if (arr[i] > 0)
                return i - shift + 1;
        }
        
        // If all positive numbers from 1 to (n - shift + 1) are present, the answer is (n - shift + 1)
        return n - shift + 1;
    }
    
private:
    // Helper function to segregate positive and non-positive numbers
    int segregate(int arr[], int n) {
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] <= 0) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        return i;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends