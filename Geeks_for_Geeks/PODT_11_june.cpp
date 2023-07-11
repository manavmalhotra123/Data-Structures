#include <iostream>
#include <vector>

using namespace std;

int find(vector<vector<int>> &arr, int n, int m, int k) {
    int top = 0;        // Topmost row
    int bottom = n - 1; // Bottommost row
    int left = 0;       // Leftmost column
    int right = m - 1;  // Rightmost column

    int direction = 0;
    int count = 0;
    int result;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        if (direction == 0) {
            for (int i = left; i <= right; ++i) {
                count++;
                if (count == k) {
                    result = arr[top][i];
                    return result;
                }
            }
            top++;  // Move to the next row
        }
        // Traverse from top to bottom
        else if (direction == 1) {
            for (int i = top; i <= bottom; ++i) {
                count++;
                if (count == k) {
                    result = arr[i][right];
                    return result;
                }
            }
            right--;  // Move to the previous column
        }
        // Traverse from right to left
        else if (direction == 2) {
            for (int i = right; i >= left; --i) {
                count++;
                if (count == k) {
                    result = arr[bottom][i];
                    return result;
                }
            }
            bottom--;  // Move to the previous row
        }
        // Traverse from bottom to top
        else if (direction == 3) {
            for (int i = bottom; i >= top; --i) {
                count++;
                if (count == k) {
                    result = arr[i][left];
                    return result;
                }
            }
            left++;  // Move to the next column
        }

        direction = (direction + 1) % 4;  // Update the direction of traversal
    }

    return -1;  // Return -1 if k is not found
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {6, 7, 8, 9}, {10, 11, 12, 13}};
    int n = arr.size();
    int m = arr[0].size();
    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    int kthElement = find(arr, n, m, k);

    if (kthElement != -1) {
        cout << "The kth element obtained while traversing the matrix spirally: " << kthElement << endl;
    } else {
        cout << "Invalid k value!" << endl;
    }

    return 0;
}
