
#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> intersection;

    // Traverse the first vector
    for (const auto& num1 : vec1) {
        // Traverse the second vector for each element of the first vector
        for (const auto& num2 : vec2) {
            // If there is a match, add the common element to the intersection vector
            if (num1 == num2) {
                intersection.push_back(num1);
                break; // Move to the next element in the first vector
            }
        }
    }

    return intersection;
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {4, 5, 6, 7, 8};

    vector<int> intersection = findIntersection(vec1, vec2);

    cout << "Intersection of the two vectors: ";
    for (const auto& num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}