#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
// Navie approach - time complexity O(N)
bool NavieMethod(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}


// square root approach - time complexity Optimized Approach (O(sqrt(n))):
bool squareroot_approach_isPrime(int number) {
    if (number < 2)
        return false;

    int sqrtNum = sqrt(number);
    for (int i = 2; i <= sqrtNum; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

// sieve of eratosthenes - Time complexity Optimized O(n log(log(n)))
bool sieve(int n) {
    if (n <= 1)
        return false;

    // Create a vector to mark numbers as composite (not prime)
    vector<bool> isComposite(n + 1, false);

    for (int p = 2; p * p <= n; p++) {
        if (!isComposite[p]) {
            for (int i = p * p; i <= n; i += p)
                isComposite[i] = true;
        }
    }

    return !isComposite[n];
}



int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (NavieMethod(number))
        std::cout << number << " is prime." << std::endl;
    else
        std::cout << number << " is not prime." << std::endl;

    

    return 0;
}
