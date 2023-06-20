// INSERTION SORT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &v){

    for (int round = 0; round < v.size(); round++)
    {
        // Step 1: Fetch
        int key = v[round];
        int j = round - 1;

        // step 2: compare and shift values
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j --;
        }


    // Step 3: Insert or copy value at correct position
    v [ j + 1] = key;
    }

}



int main(int argc, char const *argv[])
{
    vector<int> values = {12, 11, 13, 5, 6};
    insertionSort(values);
    print_vector(values);
    return 0;
}
