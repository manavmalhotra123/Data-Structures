#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<int> &v, int target)
{
    // base case when the target length is achieved
    if (target == 0)
    {
        return 0;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        // if the current length is less than or equal to the target
        if (v[i] <= target)
        {
            // recursively solve for the remaining length
            int ans = solve(v, target - v[i]);
            if (ans != INT_MIN)
            {
                // update the maximum length by adding the current length
                maxi = max(maxi, ans + 1);
            }
        }
    }

    if (maxi == INT_MIN)
    {
        // if no valid subsequence is found
        return -1;
    }
    else
    {
        // return the maximum length
        return maxi;
    }
}

int main()
{
    int length = 7;
    vector<int> possible_lengths = {5, 2, 2};

    cout << solve(possible_lengths, length) << endl;

    return 0;
}
