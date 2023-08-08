// BUBBLE SORT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        cout << "Round " << i + 1 << endl;
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                cout << "Swap needed between " << v[j] << " and " << v[j + 1] << endl;
                swap(v[j], v[j + 1]);
            }
        }
        print_vector(v);
        cout << endl;
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    print_vector(v);
    bubble_sort(v);
    print_vector(v);
    return 0;
}
