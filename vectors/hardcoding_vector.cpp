#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5}; // Initial vector

    // Method 1: Using the assignment operator (=)
    myVector = {6, 7, 8}; // Assign a new set of values

    // Method 2: Using the assign function
    std::vector<int> newValues = {9, 10, 11, 12};
    myVector.assign(newValues.begin(), newValues.end()); // Assign values from another vector

    // Display the updated vector
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}