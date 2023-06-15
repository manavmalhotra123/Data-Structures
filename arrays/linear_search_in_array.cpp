
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize
    int a[5] = {0,1,2,3,4};

    // search key
    int key = 4;


    // searching algorithm
    int index = 0;
    // we will traverse the array and store the key index in variable index
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == key)
        {
            index = i;
            cout << "Value find index "<<index << endl;
        }
        
    }
    return 0;
}
