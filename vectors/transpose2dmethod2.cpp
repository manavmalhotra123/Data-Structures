#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void transposeMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Finding transpose using std::swap
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Displaying transpose
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;

    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix);

    return 0;
}
