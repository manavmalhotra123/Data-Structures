// count zeros and ones in an array

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1,1,1,0,0,0,0,1,0,0,1};

    int length = sizeof(a) / sizeof(a[0]);

    cout << "The length of the array is " << length << endl;

    int count_one = 0;
    int count_zeros = 0; 

    // loop for counting the zeros and ones in an array
    for (int i = 0; i < length; i++)
    {
        // if element is zero then increment the count of zero
        if (a[i] == 0)
        {
            count_zeros++;
        }
        else
        {
            count_one++;
        }
    }
    cout<<"number of zeros are "<<count_zeros<<endl;
    cout<<"number of one's are "<<count_one<<endl;

    return 0;
}
