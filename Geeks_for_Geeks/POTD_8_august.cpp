#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int countFractions(int n, int numerator[], int denominator[]) {
        const int MAX_DENOMINATOR = 10000;
        int fractionCount[MAX_DENOMINATOR][2] = {0}; // Stores counts of unique fraction pairs
        int answer = 0; // The final count of pairs whose sum equals 1

        for (int i = 0; i < n; i++) {
            int x = numerator[i];
            int y = denominator[i];
            int gcdValue = __gcd(x, y); // Calculate the greatest common divisor
            x /= gcdValue;
            y /= gcdValue;
            int want_x = y - x; // The complement numerator
            int want_y = y; // The complement denominator

            if (want_y < MAX_DENOMINATOR) {
                // If the complement denominator is within the bounds of MAX_DENOMINATOR
                // Add the count of pairs with the complement fraction to the answer
                answer += fractionCount[want_y][want_x];
            }

            fractionCount[y][x]++; // Increment the count for the current fraction
        }

        return answer; // Return the total count of pairs
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    int n = 4;
    int numerator[] = {1, 2, 3, 4};
    int denominator[] = {6, 3, 4, 12};
    int result = sol.countFractions(n, numerator, denominator);
    cout << "Count of pairs: " << result << endl;

    return 0; // Exit the program
}
