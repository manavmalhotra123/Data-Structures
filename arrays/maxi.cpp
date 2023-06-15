// finding the maximum element in an array 

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,23,6,7};

    int len = sizeof(a)/sizeof(a[0]);

    int max_element = 0;
    int max_index = 0;
    // find the maximum element in an array
    for (int i = 0; i < len; i++)
    {
        if (a[i] > max_element)
        {
            max_element = a[i];
            max_index = i;
        }
        
    }
    cout << max_element << endl;
    cout << max_index << endl;
    

    return 0;
}
