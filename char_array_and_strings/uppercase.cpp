#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<char> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// using ASCII Values conversion of lowercase to upper case
void uppercase(vector<char> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 'a' && v[i] <= 'z') {
            v[i] = v[i] - 'a' + 'A';  // Convert lowercase to uppercase
        }
    }
}


int main()
{

    vector<char> arr = {'n', 'o', 'o', 'o', 'n'};
    uppercase(arr);
    print_vector(arr);
    
    return 0;
}