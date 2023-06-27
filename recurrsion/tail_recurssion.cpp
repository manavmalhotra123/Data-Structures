#include <iostream>


void tailRecursion(int n) {
    // Base case: when n reaches 0, stop recursion
    if (n == 0) {
        return;
    }


   
    // Processing step (printing the current value)
    std::cout << n << " ";

    // Recursive call before the processing step
    tailRecursion(n - 1);
}

int main() {
    int num = 5;
    tailRecursion(num);
    std::cout << std::endl;

    return 0;
}
