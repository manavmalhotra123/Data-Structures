#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void ShowVector(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
         cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

// time complexity here is O(N^2)
vector<int> next_mini(vector<int> &v){
    vector<int> track;
    int mini = INT16_MAX; // element to keep the track of the mini number
    // starting from right of an array
    for (int i = 0; i < v.size(); i++)
    {
        // taking minimum number as current index element
        mini = v[i];
        for (int j = i+1; j < v.size() ; j++)
        {
            // if the the numbers next to the current index are smaller then update the mini number
            if (v[j] < mini)
            {
                mini = v[j];
            }
        }
        // if the number remains same means there is no number that is less than the current element
        if (mini == v[i])
        {
            // so push the number -1 as indicator of not found
            track.push_back(-1);
        }
        // otherwise push the closest mini number
        else
        {
            track.push_back(mini);
        }
    }
    // return the number
    return track;
}


// time complexity O(N)

vector<int> solve(vector<int>& input) {
    vector<int> track;
    stack<int> finder;

    for (int i = input.size() - 1; i >= 0; i--) {
        while (!finder.empty() && input[i] < finder.top()) {
            finder.pop();
        }
        if (finder.empty()) {
            track.push_back(-1); // Indicator for not finding a next minimum element
        } else {
            track.push_back(finder.top()); // Add the next minimum element to the track vector
        }
        finder.push(input[i]);
    }

    // Reverse the track vector to match the original order
    reverse(track.begin(), track.end());

    return track;
}


int main(int argc, char const *argv[])
{
    vector<int> v = {2,1,4,3};
    vector<int> result = next_mini(v);
    ShowVector(result);

    return 0;
}
