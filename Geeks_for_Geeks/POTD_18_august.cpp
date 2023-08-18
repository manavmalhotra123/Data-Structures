#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(vector<int> input)
{
    vector<int> output;
    output.push_back(input[input.size() - 1]);

    for (int i = input.size() - 2; i >= 0; i--)
    {
        if (input[i] > output.back())
        {
            output.push_back(input[i]);
        }
    }
    reverse(output.begin(), output.end());

    return output;
}

void solve(vector<int> input)
{
    vector<int> result = leaders(input);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> input1 = {16, 17, 4, 3, 5, 2};
    cout<<"leaders of input1"<<endl;
    solve(input1);  // Output: 17 5 2


    vector<int> input2 = {1, 2, 3, 4, 0};
    cout<<"leaders of input2"<<endl;
    solve(input2);  // Output: 4 0

    return 0;
}
