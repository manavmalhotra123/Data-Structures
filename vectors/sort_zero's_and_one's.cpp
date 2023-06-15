#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& v) {
    cout << "vector: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sort_zeros_ones(vector<int>& v) {
    int start = 0;
    int end = v.size() - 1;

    while (start < end) {
        while (v[start] == 0 && start < end) {
            start++;
        }

        while (v[end] == 1 && start < end) {
            end--;
        }

        if (start < end) {
            swap(v[start], v[end]);
            start++;
            end--;
        }
    }
}

int main() {
    vector<int> v = {1, 0, 1, 0, 1, 0, 1, 0, 0};
    print_vector(v);

    sort_zeros_ones(v);

    print_vector(v);

    return 0;
}
