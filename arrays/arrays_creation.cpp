#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin >> n;
    // arrays syntax 
    int a[n]; // array of size n is created
    // entering the values in an array 
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    


    return 0;
}
