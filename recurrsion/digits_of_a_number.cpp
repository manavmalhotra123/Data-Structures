#include <iostream>

using namespace std;

void all_digit_using_recursive(int n) {
    if (n == 0) {
        return;  // Base case: If n becomes 0, all digits have been processed, so return
    }

    int digit = n % 10;  // Extract the last digit of n
    cout << digit << endl;  // Print the extracted digit

    return all_digit_using_recursive(n / 10);  // Make a recursive call with the remaining digits
}

int main(int argc, char const *argv[]) {
    int n = 988;

    all_digit_using_recursive(n);  // Call the recursive function to print all digits of n
    return 0;
}
