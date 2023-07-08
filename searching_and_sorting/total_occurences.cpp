#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// printing the vector
void print_vector(const vector<int>& vals){
    cout << "vector" << endl;
    for (int i = 0; i < vals.size(); i++) {
        cout << vals[i] << " ";
    }
    cout << endl;
}

// finding the number of occurrences using linear search
int find_number_of_occurrences(const vector<int>& vals, int key)
{
    int step = 0;
    int count = 0;
    for (int i = 0; i < vals.size(); i++) {
        step++;
        if (vals[i] == key) {
            count++;
        }
    }
    cout << "Number of steps taken: " << step << endl;
    return count;
}

// finding the number of occurrences using binary search
int find_number_of_occurrences_using_binary_search(const vector<int>& v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    int mid;
    int count = 0;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (v[mid] == key) {
            count++;
            end = mid - 1;  // Update start instead of end to find first occurrence
        }
        else if (key > v[mid]) {
            start = mid + 1;
        }
        else if (key < v[mid]) {
            end = mid - 1;
        }
    }

    return count;
}

int main()
{
    vector<int> v = {1, 3, 4, 4, 4, 4, 6, 7, 9};
    print_vector(v);

    int key = 4;

    // Measure time taken by find_number_of_occurrences_using_binary_search
    int countBinary = find_number_of_occurrences_using_binary_search(v, key);


    return 0;
}
