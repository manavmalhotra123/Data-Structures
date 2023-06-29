#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<int> &v, int target)
{
    // base case jb rod khtm ho jayegi
    if (target == 0)
    {
        return 0;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= target)
        {
            int ans = solve(v, target - v[i]);
            if (ans != INT_MIN)
            {
                maxi = max(maxi, ans + 1);
            }
        }
    }

    if (maxi == INT_MIN)
    {
        return -1;
    }
    else
    {
        return maxi;
    }
}

int main()
{
    int length = 7;
    vector<int> possible_lenghts = {5,2,2};

    cout<<solve(possible_lenghts,length)<<endl;

    return 0;
}