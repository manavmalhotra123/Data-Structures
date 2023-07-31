#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// fences ko paint krna hai bs yeh dhyaan rkhna ki same paint do baar se zyada nah ho continously

/*
suppose you are having three colours
1. Red
2. Blue
3. Green

if you solving for two fences
choices you have
if using same colours then k = 3
RR
GG
BB
if you are using combination of different colours K = 6
RB
RG
BR
BG
GR
GB

if you are solving for three fences
RBB
RGG
BRR
BGG
GBB
GRR
other option can be
RRB RRG BBR BBG GGR GGB RBR RBG RGR
RGB BRB BRG BGR BGB GRB GRG GBR GBG

if you are using 4 fences
RRBB   GRGG
RRGG   GBRR
BBRR   GBGG
BBGG   RBGG
RGRR   BGRR
RGBB
BGBB
BRBB
GRBB
GGBB
GGRR
RBRR

F(4) = F(2)*(k-1) + F(3)*(k-1) = (F(2) + F(3))*(k-1)
F(N) = [F(n-2) + F(n-1)]*(k-1)
*/

/*
This is the problem of Dynamic programming because in it's
recursive function we are able to detect overlapping subproblem
*/

// Recursive function
int solveusingrecursion(int n, int k)
{
    // if ek fence hai
    if (n == 1)
    {
        // then we will return every choice
        return k;
    }
    // if number of fences are two
    if (n == 2)
    {
        // calculated using table
        return k + k * (k - 1);
    }

    int ans = ((solveusingrecursion(n - 2, k) + solveusingrecursion(n - 1, k)) * (k - 1));

    return ans;
}

// Time for top down approach - memosization
// 1-D Dp ka question hai
int PaintMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k * k;
    }

    // check kro agr pehle se pda hai to avoid overlapping
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // dp of n ki value ko find kro aur store kraate jayo
    dp[n] = (PaintMemo(n - 2, k, dp) + PaintMemo(n - 1, k, dp)) * (k - 1);

    return dp[n];
}

int topDownDP(int n, int k)
{
    // dp vector bnaalo
    vector<int> dp(n + 1, -1);
    int answer = PaintMemo(n, k, dp);

    return answer;
}

// Bottom up approach
int bottomupDP(int n, int k)
{
    // dp vector bnaale
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    return dp[n];
}

// most optimized version of the this solution
int opt(int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k * k;
    }

    int oneless = k * k;
    int twoless = k;
    int ans = 0;

    for (int i = 3; i <= n; i++)
    {
        ans = (oneless + twoless) * (k - 1);
        twoless = oneless;
        oneless = ans;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 4; // number of fences
    int k = 3; // choices

    int ans = solveusingrecursion(n, k);
    cout << ans << endl;

    int memo = topDownDP(n, k);
    cout << memo << endl;

    int bottom = topDownDP(n, k);
    cout << bottom << endl;

    int optimized = opt(n, k);
    cout << optimized << endl;
    return 0;
}