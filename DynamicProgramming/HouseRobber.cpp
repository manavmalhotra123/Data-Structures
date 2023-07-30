#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int RobRecursive(vector<int> &Houses, int index)
{
    // jab houses hi khtm ho jaaye
    if (index > Houses.size())
    {
        return 0;
    }

    // Two Choices
    // ek use krke dusra skip krdo
    // amount add krenge yha pr
    int option1 = Houses[index] + RobRecursive(Houses, index + 2);

    // ya pehle ko skip krke dusre ko rob krlo
    int option2 = RobRecursive(Houses, index + 1);

    return max(option1, option2);
}

int rob(vector<int> v)
{
    int ans = RobRecursive(v, 0);

    if (v.size() == 0)
    {
        return 0;
    }

    return ans;
}

// robber have to rob the houses but he cannot rob two consecutive houses as they are connected to each other
// find the maximum amount he can rob from the houses
int main(int argc, char const *argv[])
{
    vector<int> House = {100, 223, 323, 1200};
    int ans = rob(House);
    cout <<"Maximum amount of money he can rob is $" << ans<<endl;

    return 0;
}