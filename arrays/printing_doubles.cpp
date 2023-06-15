#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[5];

    // Taking input
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }

    // printing doubles
    for (int i = 0; i < 5; i++)
    {
        cout<<2*a[i]<<endl;
    }
    
    return 0;
}
