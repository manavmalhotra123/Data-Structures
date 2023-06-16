#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to rotate the matrix by the given angle (in degrees)
vector<vector<int>> rotateMatrix(const vector<vector<int>>& matrix, double angle) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Convert the angle from degrees to radians
    double radians = angle * M_PI / 180.0;

    // Calculate the center point of the original matrix
    double centerX = cols / 2.0;
    double centerY = rows / 2.0;

    // Create a new matrix to store the rotated elements
    vector<vector<int>> rotatedMatrix(rows, vector<int>(cols));

    // Iterate over each element of the original matrix
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Calculate the coordinates of the current element relative to the center point
            double relativeX = col - centerX;
            double relativeY = row - centerY;

            // Apply the rotation transformation to the coordinates
            double rotatedX = relativeX * cos(radians) - relativeY * sin(radians);
            double rotatedY = relativeX * sin(radians) + relativeY * cos(radians);

            // Translate the coordinates back to the original coordinate system
            double originalX = rotatedX + centerX;
            double originalY = rotatedY + centerY;

            // Round the coordinates to the nearest integer to get the indices of the nearest element in the original matrix
            int nearestX = round(originalX);
            int nearestY = round(originalY);

            // Check if the indices are within the valid range
            if (nearestX >= 0 && nearestX < cols && nearestY >= 0 && nearestY < rows) {
                // Assign the element from the original matrix to the corresponding position in the rotated matrix
                rotatedMatrix[row][col] = matrix[nearestY][nearestX];
            }
        }
    }

    return rotatedMatrix;
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    double angle;
    cout << "Enter the angle (in degrees) to rotate the matrix: ";
    cin >> angle;

    vector<vector<int>> rotatedMatrix = rotateMatrix(matrix, angle);

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    cout << "Rotated matrix:" << endl;
    printMatrix(rotatedMatrix);

    return 0;
}
