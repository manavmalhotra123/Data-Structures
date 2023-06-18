// other method of binary search in 2-D matrix 

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<vector<int>> &v) {
    int rows = v.size();
    int cols = v[0].size();

    cout << "Vector: " << endl;

    for (size_t i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
}

void search_target(vector<vector<int>> &v, int target) {
    int rows = v.size();
    int cols = v[0].size();

    int start = 0;
    int end = rows * cols - 1;

    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;

    while (start <= end) {
        int mid = (start + end) / 2;
        int i = mid / cols;
        int j = mid % cols;
        if (v[i][j] == target) {
            cout << "Found it" << endl;
            cout<<"row :"<<i<<" col :"<<j<<endl;
            break;
        } else if (v[i][j] > target) {
            cout << "Bete piche chlo abhi mila nhi..........." << endl;
            end = mid - 1;
        } else {
            cout << "Bete aage dekho is part mai kuch nhi pda ............." << endl;
            start = mid + 1;
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {{1, 3, 4, 5, 6},
                                   {7, 8, 10, 11, 12}};

    search_target(matrix, 4);

    return 0;
}
