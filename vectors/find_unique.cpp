#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1,2,4,2,1,3,6,5,5,6,4};

    // printing the an array
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    

    int unique = v[0];

    // finding the unique element in an array
    for (int i = 1; i < v.size(); i++)
    {
        // finding the unique element using XOR operator
        unique = unique ^ v[i];
    }
    
    cout << unique << endl;

    return 0;
}