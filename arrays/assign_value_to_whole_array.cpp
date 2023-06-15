// change all the values of an array to 1

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
 
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // changing the values
    for (int i = 0; i < 5; i++)
    {
        a[i] = 1;
    }
    // print the array with new values
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
