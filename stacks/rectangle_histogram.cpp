#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& histogram) {
    stack<int> stk; // Stack to store the indices of histogram bars
    int maxArea = 0; // Variable to store the maximum area
    int n = histogram.size(); // Size of the histogram
    int i = 0; // Index variable for iteration

    // Iterate through each bar of the histogram
    while (i < n) {
        // If the stack is empty or current bar's height is greater than or equal to the bar at the top of the stack
        if (stk.empty() || histogram[i] >= histogram[stk.top()]) {
            stk.push(i); // Push the current index onto the stack
            i++; // Move to the next bar
        } else {
            int top = stk.top(); // Get the index of the top bar on the stack
            stk.pop(); // Pop the top bar from the stack
            // Calculate the area of the rectangle using the popped bar as the shortest bar
            int area = histogram[top] * ((stk.empty() ? i : i - stk.top() - 1));
            maxArea = max(maxArea, area); // Update maxArea if necessary
        }
    }

    // After iterating through all the bars, if there are any bars left in the stack
    while (!stk.empty()) {
        int top = stk.top(); // Get the index of the top bar on the stack
        stk.pop(); // Pop the top bar from the stack
        // Calculate the area of the rectangle using the popped bar as the shortest bar
        int area = histogram[top] * ((stk.empty() ? i : i - stk.top() - 1));
        maxArea = max(maxArea, area); // Update maxArea if necessary
    }

    return maxArea; // Return the maximum area
}

int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    int largestArea = largestRectangleArea(histogram);
    cout << "Largest area of the histogram: " << largestArea << endl;
    return 0;
}
