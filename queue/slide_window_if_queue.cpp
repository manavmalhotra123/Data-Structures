#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> findFirstNegativeInWindow(const vector<int>& nums, int windowSize)
{
    vector<int> output;
    queue<int> window;

    for (int i = 0; i < nums.size(); i++)
    {
        window.push(nums[i]); // Add the current element to the window

        if (window.size() > windowSize)
            window.pop(); // Remove the oldest element if the window size exceeds the specified size

        // Check if the window contains a negative number
        bool foundNegative = false;
        for (int j = 0; j < window.size(); j++)
        {
            if (window.front() < 0)
            {
                foundNegative = true;
                break;
            }
            window.push(window.front());
            window.pop();
        }

        // Add the negative number to the output vector
        if (foundNegative)
        {
            int negative = window.front();
            output.push_back(negative);
        }
    }

    return output;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {12, -1, -7, 8, -15, 30, 16, 18};
    int windowSize = 3;

    vector<int> output = findFirstNegativeInWindow(v, windowSize);

    // printing the output vector
    cout << "Solution: ";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
