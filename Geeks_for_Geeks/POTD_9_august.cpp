#include <iostream>

using namespace std;

class Solution {
public:
    long long int largestPrimeFactor(int N) {
        long long int largest_prime = -1;
        int i = 2;
        while (i * i <= N) {
            while (N % i == 0) {
                largest_prime = i;
                N /= i;
            }
            i++;
        }
        if (N > 1) {
            largest_prime = N;
        }
        return largest_prime;
    }
};

int main() {
    int N;
    cin >> N;
    Solution solution;
    long long int largest_prime = solution.largestPrimeFactor(N);
    cout << largest_prime << endl;
    return 0;
}
