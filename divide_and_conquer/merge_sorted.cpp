#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// printing the vector
void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// merge function
void merge(vector<int> &v, int start, int end)
{
    // mid jha pr center point rkhna merge krte time
    int mid = (start + end) / 2;

    int array_1_length = mid - start + 1;

    int array_2_length = end - mid;

    vector<int> left(array_1_length);
    vector<int> right(array_2_length);

    int k = start;
    // copy the values in left array
    for (int i = 0; i < array_1_length; i++)
    {
        left[i] = v[k];
        k++;
    }

    k = mid + 1;
    // copy the values in right array
    for (int i = 0; i < array_2_length; i++)
    {
        right[i] = v[k];
        k++;
    }

    // MERGE KRTE HAI AB HUM ARAAM SE
    int left_array_index = 0;
    int right_array_index = 0;
    int main_array_index = start;

    while (left_array_index < array_1_length && right_array_index < array_2_length)
    {
        // when there are values present in the any of array
        if (left[left_array_index] < right[right_array_index])
        {
            v[main_array_index] = left[left_array_index];
            main_array_index++;
            left_array_index++;
        }
        else
        {
            v[main_array_index] = right[right_array_index];
            main_array_index++;
            right_array_index++;
        }
    }

    // agar kisi array mai values pehle khtm hogi toh dusre ke saare element direct copy krde bhai
    while (left_array_index < array_1_length)
    {
        v[main_array_index] = left[left_array_index];
        main_array_index++;
        left_array_index++;
    }
    while (right_array_index < array_2_length)
    {
        v[main_array_index] = right[right_array_index];
        main_array_index++;
        right_array_index++;
    }
}

// merge sort function
void merge_sort(vector<int> &v, int start, int end)
{
    // base case - agr element single hai toh abhi ke liye kuch nhi krna kyuki woh already sort hoga
    if (start == end)
    {
        return; // todna bnd krdo bs
    }
    // base case - invalid array
    if (start > end)
    {
        return; // todna bnd krna pda kyuki ab invalid hogya todna
    }

    int mid = (start + end) / 2;
    // sorting of right array
    merge_sort(v, start, mid);

    // sorting of left recurssion
    merge_sort(v, mid + 1, end);

    // Now merging
    merge(v, start, end);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {4, 5, 13, 2, 12};
    print_vector(v);
    int e = v.size();

    merge_sort(v, 0, e);
    print_vector(v);
    return 0;
}
