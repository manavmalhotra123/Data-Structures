#include<iostream>
#include<vector>

using namespace std;

void find_odd(vector<int> v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans ^= v[i];
    }
    cout<<ans<<endl;
} // using XOR Gate


int solve(vector<int> arr) {
  int s = 0; // Start index
  int e = arr.size() - 1; // End index
  int mid = s + (e - s) / 2; // Midpoint index

  while (s <= e) { // Binary search loop
    if (s == e) {
      // Single element
      return s; // Return index
    }

    // Two cases -> mid is even or odd
    if (mid % 2 == 0) { // Midpoint is even
      if (arr[mid] == arr[mid + 1]) {
        // Pair is the same number, desired number is on the right side
        s = mid + 2; // Update start index
      } else {
        // Desired number is on the left side
        e = mid; // Update end index
      }
    } else { // Midpoint is odd
      if (arr[mid] == arr[mid - 1]) {
        // Pair is the same number, desired number is on the left side
        s = mid + 1; // Update start index
      } else {
        // Desired number is on the right side
        e = mid - 1; // Update end index
      }
    }
    mid = s + (e - s) / 2; // Recalculate midpoint
  }

  return -1; // Number not found, should not reach here
}

int main() {
  vector<int> arr{1, 1, 2, 2, 1}; // Input vector
  int ans = solve(arr); // Call solve function
  cout << "index is " << ans << endl; // Print index
  cout << "value is " << arr[ans] << endl; // Print value
  find_odd(arr); // Find

  return 0;
}
