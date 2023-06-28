#include <iostream>
#include <vector>

using namespace std;

bool is_sorted(const vector<int>& v, int index) {
    // if shi jaara kaam toh true return kri ja
    if (index >= v.size() - 1) {
        return true;
    }
 
    // if glt hogya toh false return kri ja
    if (v[index] > v[index + 1]) {
        return false;
    }

    // baaki sab elements pr dekhne ke liye apna function baitha hai 
    return is_sorted(v, index + 1);
}

int main() {
    vector<int> v = {1, 2, 3, 40, 5, 6, 7, 8};

    if (is_sorted(v, 0)) {
        cout << "The vector is sorted." << endl;
    } else {
        cout << "The vector is not sorted." << endl;
    }

    return 0;
}
