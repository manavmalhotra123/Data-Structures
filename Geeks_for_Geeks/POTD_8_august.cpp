#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class solution
{
    public:
        int countfractions(int n, int numerator[], int denominator[])
        {
            const int MAX_DENOMINATOR = 10000;
            int fractionCount[MAX_DENOMINATOR][2] = {0};
            int answer = 0;

            for (int i = 0; i < n; i++)
            {
                int x = numerator[i];
                int y = denominator[i];
                int gcdValue = __gcd(x, y);
                x /= gcdValue;
                y /= gcdValue;
                int want_x = y - x;
                int want_y = y;

                if (want_y < MAX_DENOMINATOR)
                {
                    answer += fractionCount[want_y][want_x];
                }
                
                fractionCount[y][x]++;
            }
            
            return answer;
        }
};




int main(int argc, char const *argv[])
{
    solution sol;
    int n = 4;
    int numerator[] = {1, 2, 3, 4};
    int denominator[] = {6, 3, 4, 12};
    int result = sol.countfractions(n, numerator, denominator);
    cout << "Count of pairs: " << result << endl;

    return 0;

    return 0;
}