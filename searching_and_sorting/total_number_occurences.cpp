#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;
using namespace std::chrono;

// finding the total occurrences using linear search
void find_total_occurrences_using_linear_search(const vector<int>& v, int key)
{
    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            count++;
        }
    }

    cout << "Total occurrences: " << count << endl;
}

// finding the total occurrences using binary search
void find_total_occurrences_using_binary_search(const vector<int>& v, int key)
{
    int start = 0;
    int end = v.size() - 1;
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    // Find the first occurrence
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == key)
        {
            firstOccurrence = mid;
            end = mid - 1;
        }
        else if (key < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // Find the last occurrence
    start = 0;
    end = v.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == key)
        {
            lastOccurrence = mid;
            start = mid + 1;
        }
        else if (key < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    int count = lastOccurrence - firstOccurrence + 1;

    cout << "Total occurrences: " << count << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 4, 4, 4, 4, 4, 6, 8, 10};

    // Measure time taken by find_total_occurrences_using_linear_search
    auto startLinear = high_resolution_clock::now();
    find_total_occurrences_using_linear_search(v, 4);
    auto endLinear = high_resolution_clock::now();
    auto durationLinear = duration_cast<microseconds>(endLinear - startLinear);

    // Measure time taken by find_total_occurrences_using_binary_search
    auto startBinary = high_resolution_clock::now();
    find_total_occurrences_using_binary_search(v, 4);
    auto endBinary = high_resolution_clock::now();
    auto durationBinary = duration_cast<microseconds>(endBinary - startBinary);

    cout << "Time taken by linear search: " << durationLinear.count() << " microseconds" << endl;
    cout << "Time taken by binary search: " << durationBinary.count() << " microseconds" << endl;

    return 0;
}
