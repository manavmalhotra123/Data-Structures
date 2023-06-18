// Binary search in 2-D Matrix

/*
To perform a binary search in 2-D Matrix we need to flatten the matrix
then follow the normal binary search algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

bool search(const vector<vector<int>> &v, int target){

    int rows = v.size();
    int columns = v[0].size();

    int start = 0;
    int end = rows * columns - 1;

    while (start < end)
    {
        int mid = start + (end - start)/2;
        int i = mid / columns;
        int j = mid % columns;

        if (v[i][j] == target)
        {
            return true;
        }
        else if (v[i][j] < target){
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    
    vector<vector<int>> matrix = {{1,3,5,7},
                                {10,11,12,13},
                                {13,14,25,16}};

    int target = 5;
    bool mila = search(matrix,target);

    if (mila == true)
    {
        cout<<"Mil gya bhai"<<endl;
    }
    else
    {
        cout<<"Nhi mila"<<endl;
    }
    
    

    return 0;
}
