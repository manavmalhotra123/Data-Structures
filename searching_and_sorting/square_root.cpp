// Finding the square root of number using binary search

// Example : square root of 10 lies between 0 and 10 
// search space : 0 1 2 3 4 5 6 7 8 9 10

#include <iostream>

using namespace std;

int main() {
    double number = 9;

    double start = 0.0;
    double end = number;
    double precision = 0.00001; // Precision threshold

    double mid = (start + end) / 2;

    while (end - start > precision) {
        if (mid * mid == number) {
            cout << "The square root of the number is " << mid << std::endl;
            break;
        } else if (mid * mid < number) {
            start = mid;
        } else {
            end = mid;
        }
        mid = (start + end) / 2;
    }

    cout << "The approximate square root of the number is " << mid << std::endl;

    return 0;
}
