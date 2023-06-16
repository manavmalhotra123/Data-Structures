#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


void making_monotonic(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size() - 1; j++)
        {
            if (v[i] > v[j])
            {
                cout << "Swapping " << v[i] << " with " << v[j] << endl;
                swap(v[i], v[j]);
                print_vector(v);
            }
        }
    }
}

void binary_search(vector<int> &v, int value)
{
    int start = 0;
    int end = v.size() - 1;

    cout << "starting index " << start << endl;
    cout << "ending index " << end << endl;
    cout<<endl;
    cout<<"sorting begin"<<endl;

    while (start <= end)
    {
        //int mid = (start + end) / 2;
        
        int mid = start + (end - start)/2; 

        if (value > v[mid])
        {
            cout<<"shifting start to ";
            start = mid + 1;
            cout<<start<<endl;
        }
        else if (value < v[mid])
        {
            cout<<"shifting end to ";
            end = mid - 1;
            cout<<end<<endl;
        }
        else if (value == v[mid])
        {
            cout << "element found at index " << mid << endl;
            return;
        }
    }
    cout << "element not found" << endl;
}


int main()
{
    vector<int> vals = {0, 1, 2, 23, 4, 50, 6, 7};
    print_vector(vals);
    cout << endl;
    making_monotonic(vals);
    cout << endl;
    print_vector(vals);

    binary_search(vals, 0);
    cout<<endl;
    binary_search(vals, 50);

    return 0;
}
