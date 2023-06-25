#include <iostream>

// Function to find the HCF of two numbers using the Euclidean algorithm
int findHCF(int a, int b) {
    if (b == 0)
        return a;

    return findHCF(b, a % b);
}

// Function to find the LCM of two numbers
int findLCM(int a, int b) {
    // Calculate the product of the two numbers
    int product = a * b;

    // Calculate the HCF of the two numbers
    int hcf = findHCF(a, b);

    // Calculate the LCM using the formula (a * b) / HCF(a, b)
    int lcm = product / hcf;

    return lcm;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Call the findLCM function to get the LCM of num1 and num2
    int lcm = findLCM(num1, num2);

    std::cout << "The LCM of " << num1 << " and " << num2 << " is " << lcm << std::endl;

    return 0;
}
