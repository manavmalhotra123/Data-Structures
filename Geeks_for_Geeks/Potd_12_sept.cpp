class Solution {
public:
    int isPerfectNumber(long long N) {
        if (N <= 1) {
            return 0; // Perfect numbers are greater than 1
        }

        long long sum = 1; // Start with 1 as a divisor (every number is divisible by 1)

        for (long long i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                sum += i;
                if (i != N / i) {
                    sum += N / i; // Add the other divisor if it's not the same as i
                }
            }
        }

        return sum == N ? 1 : 0;
    }
};
