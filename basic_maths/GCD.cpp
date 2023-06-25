#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void GCD(int a,int b)
{
    cout<<a<<" "<<b<<endl;

    // ensure that the a is greater than or equal to b
    if (b > a)
    {
        swap(a,b);
    }
    
    cout<<a<<" "<<b<<endl;

    // Iterate until b becomes 0
    while (b != 0)
    {
        int remainder = a % b;

        // update a with remainder when a is divided ny b
        a = b;
        b = remainder;

        cout<<a<<endl;
    }
    
    cout<<"HCF = "<<a<<endl;
}

int main(int argc, char const *argv[])
{
    int a = 6;
    int b = 48;
    GCD(a,b);
    return 0;
}
