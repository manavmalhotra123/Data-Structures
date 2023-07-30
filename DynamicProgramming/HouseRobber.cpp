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

// Memosiation ka concept lgake krte hai try
int RobMemo(vector<int> Houses, int index, vector<int> &dp)
{
    // Base Case ko handle kre
    if (index > Houses.size())
    {
        return 0;
    }
    // dekho ki pehle value pdi hai kya
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // ya toh chori krlo same ghr pr aur ek ghr chod do
    int choiceOne = Houses[index] + RobMemo(Houses, index + 2, dp);
    int choiceTwo = RobMemo(Houses, index + 1, dp);

    // nya answer
    dp[index] = max(choiceOne, choiceTwo);
    return dp[index];
}

int RobByMemo(vector<int> Houses)
{
    // dp array ko bnaaya jaaye
    vector<int> dp(Houses.size() + 1, -1);
    int answer = RobMemo(Houses, 1, dp);
    return answer;
}


// Bottom Up Approach use krke dekhte hai 
int RobBottomUp(vector<int> Houses)
{
    // n ki value nikaal li 
    int n = Houses.size();

    // dp vector bna liya
    vector<int> dp(n + 1, -1);

    // ek case mai value apni aa jayegi
    dp[0] = 0;
    dp[1] = Houses[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(Houses[i - 1] + dp[i - 2], dp[i - 1]);
    }

    return dp[n];
}


// best solution of the problem 
int Robopt(vector<int> Houses)
{
    int n = Houses.size();

    // Queue to store the last three values of dp
    std::queue<int> dpQueue;

    // Initializing the queue with the first two values of dp
    dpQueue.push(0);
    dpQueue.push(Houses[0]);

    for (int i = 2; i <= n; i++)
    {
        int dp_i = max(Houses[i - 1] + dpQueue.front(), dpQueue.back());
        dpQueue.pop();
        dpQueue.push(dp_i);
    }

    return dpQueue.back();
}

// robber have to rob the houses but he cannot rob two consecutive houses as they are connected to each other
// find the maximum amount he can rob from the houses
int main(int argc, char const *argv[])
{
    vector<int> House = {100, 223, 323, 1200};
    int ans = rob(House);
    cout << "Maximum amount of money he can rob is $" << ans << endl;

    int memoans = RobByMemo(House);
    cout << memoans << endl;

    int bottomUp = RobBottomUp(House);
    cout << bottomUp << endl;

    int robopt = Robopt(House);
    cout << robopt << endl;
    return 0;
}