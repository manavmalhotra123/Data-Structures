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


// end te start de elements nu swap krna te start nu age lyi jaana te end nu piche until unless start < end haiga
void reverse_string(vector<char> &v){
    int start = 0;
    int end = v.size()-1;
    while (start < end)
    {
        swap(v[start], v[end]);
        start ++;
        end --;
    }
    
}

int main()
{

    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    print_vector(arr);
    reverse(arr.begin(), arr.end());
    print_vector(arr);
    reverse_string(arr);
    print_vector(arr);

    return 0;
}