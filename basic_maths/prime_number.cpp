#include <iostream>
#include <cmath>

bool NavieMethod(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}


// square root approach
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
