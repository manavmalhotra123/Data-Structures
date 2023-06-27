#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5; // a is the actual variable storing the value 5
    int &b = a; // b is the reference variable
    cout<<a<<" "<<b<<endl;
    return 0;
}
