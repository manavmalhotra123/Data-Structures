#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // create vector
    vector <int> v;

    // initially the size of vector is zero 
    cout<<v.size()<<endl;
    // capacity of vector is zero if it is empty
    cout<<v.capacity()<<endl;

    v.push_back(3);
    // now it will print the size of the vector as 1
    cout<<v.size()<<endl;

    // finding the size of vector
    int ans = sizeof(v)/sizeof(int);
    cout <<  ans << endl; // it's coming out to be 6
    return 0;
}