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

// finding the first and last occurrences using lower_bound and upper_bound
pair<int, int> find_occurrences(const vector<int>& v, int key)
{
    auto first = lower_bound(v.begin(), v.end(), key);
    auto last = upper_bound(v.begin(), v.end(), key);
    int count = last - first;
    if (count > 0) {
        int firstIndex = first - v.begin();
        int lastIndex = last - v.begin() - 1;
        return make_pair(firstIndex, lastIndex);
    }
    return make_pair(-1, -1);
}

int main()
{
    vector<int> v = {1, 3, 4, 4, 4, 4, 6, 7, 9};
    print_vector(v);

    int key = 4;

    pair<int, int> occurrences = find_occurrences(v, key);

    int count = occurrences.second - occurrences.first + 1;

    cout << "Number of occurrences: " << count << endl;

    return 0;
}
