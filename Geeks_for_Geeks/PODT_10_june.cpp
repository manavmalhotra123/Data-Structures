// 10 June,2023 - Tranpose of the square matrix with order n with time complexity O(n^2) and space O(1).

#include <iostream>
#include <vector>

using namespace std;

void Show(vector<vector<int>>& input)
{
    int rows = input.size();
    int cols = input[0].size();

    cout << "Matrix" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

void Transpose(vector<vector<int>>& input) {
 
    for (int i = 0; i < input.size(); i++) {
        for (int j = i + 1; j < input[0].size(); j++) {
            swap(input[i][j], input[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> input = { {0, 1}, {4, 5} };
    Show(input);
    Transpose(input);
    Show(input);
    return 0;
}
