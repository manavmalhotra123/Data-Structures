// find Kth Smallest number
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

void kth_smallest(vector<int> input, int k)
{
    if (k < 1 || k >= input.size())
    {
        return;
    }
    priority_queue<int> Supporter;
    for (int i = 0; i < input.size(); i++)
    {
        Supporter.push(input[i]);
    }
    for (int i = 1; i < k; i++)
    {
        Supporter.pop();
    }
    cout << Supporter.top() << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {890, 10, 22, 33, 4, 5, 6};
    kth_smallest(input, 4);
    return 0;
}