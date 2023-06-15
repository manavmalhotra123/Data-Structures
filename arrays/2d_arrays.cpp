#include <iostream>

using namespace std;

void print_array(int arr[][3], int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    print_array(arr, 3, 3);

    return 0;
}
