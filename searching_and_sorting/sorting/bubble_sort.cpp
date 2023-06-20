// BUBBLE SORT

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

void bubble_sort(vector<int> &v)
{
    int round = 1;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"Round "<<round<<endl;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                cout<<"Swap needed between "<<v[i]<<" and "<<v[j]<<endl;
                swap(v[i], v[j]);
            }
            print_vector(v);
        }
        round ++;
        cout<<endl;
    }
}

int main() 
{
    vector<int> v = {5, 4, 3, 2, 1};
    print_vector(v);
    bubble_sort(v);
    print_vector(v);
    return 0;
}