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

// finding first occurrence using linear search
void find_first_occurrence(const vector<int>& vals, int key)
{
    int step = 0;
    int index;
    for (int i = 0; i < vals.size(); i++) {
        step++;
        if (vals[i] == key) {
            index = i;
            break;
        }
    }
    cout << "Number of steps taken are " << step << endl;
    cout << "Element found at index " << index << endl;
}

// finding first occurrence using binary search
void finding_first_occurrence_using_binary_search(const vector<int>& v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    int mid;
    int ans = -1;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (v[mid] == key) {
            ans = mid;
            end = mid - 1;  // Update start instead of end to find first occurrence
        }
        else if (key > v[mid]) {
            start = mid + 1;
        }
        else if (key < v[mid]) {
            end = mid - 1;
        }
    }

    if (ans != -1) {
        cout << "Element found at index " << ans << endl;
    }
    else {
        cout << "Element not found in the vector" << endl;
    }
}

int main()
{
    vector<int> v = {1, 3, 4, 4, 4, 4, 6, 7, 9};
    print_vector(v);

    // Measure time taken by find_first_occurrence
    auto startLinear = high_resolution_clock::now();
    find_first_occurrence(v, 4);
    auto endLinear = high_resolution_clock::now();
    auto durationLinear = duration_cast<microseconds>(endLinear - startLinear);

    // Measure time taken by finding_first_occurrence_using_binary_search
    auto startBinary = high_resolution_clock::now();
    finding_first_occurrence_using_binary_search(v, 4);
    auto endBinary = high_resolution_clock::now();
    auto durationBinary = duration_cast<microseconds>(endBinary - startBinary);

    cout << "Time taken by linear search: " << durationLinear.count() << " microseconds" << endl;
    cout << "Time taken by binary search: " << durationBinary.count() << " microseconds" << endl;

    return 0;
}
