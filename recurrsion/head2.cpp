#include <iostream>


/*
Head recursion is a type of recursion in which the recursive call is placed before any other processing in a recursive function. 
In other words, the function performs some preliminary work before making the recursive call.
*/

void headRecursion(int n) {
    // Base case: when n reaches 0, stop recursion
    if (n == 0) {
        return;
    }

    // Recursive call before the processing step
    headRecursion(n - 1);

    // Processing step (printing the current value)
    std::cout << n << " ";
}

int main() {
    int num = 5;
    headRecursion(num);
    std::cout << std::endl;

    return 0;
}
