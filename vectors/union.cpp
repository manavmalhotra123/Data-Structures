#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findUnion(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    vector<int> unionArray = arr1;

    for (int i = 0; i < arr2.size(); i++) {
        bool found = false;

        // Check if the element from arr2 is already present in unionArray
        for (int j = 0; j < unionArray.size(); j++) {
            if (arr2[i] == unionArray[j]) {
                found = true;
                break;
            }
        }

        // If the element is not found, add it to unionArray
        if (!found) {
            unionArray.push_back(arr2[i]);
        }
    }

    return unionArray;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};

    vector<int> unionArray = findUnion(arr1, arr2);

    cout << "Union of the arrays: ";
    for (int i = 0; i < unionArray.size(); i++) {
        cout << unionArray[i] << " ";
    }
    cout << endl;

    return 0;
}