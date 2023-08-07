//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution {
public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N]) {
        int row, col;
        // Find an empty cell in the grid (marked by 0)
        if (!find_empty_cell(grid, row, col)) {
            return true; // If there are no empty cells, the Sudoku is solved
        }

        // Try filling the empty cell with numbers 1 to 9
        for (int num = 1; num <= 9; num++) {
            if (is_safe_to_place_number(grid, row, col, num)) {
                // If the number is safe, place it in the cell
                grid[row][col] = num;

                // Recursively try to solve the remaining Sudoku
                if (SolveSudoku(grid)) {
                    return true;
                }

                // If the current placement leads to an invalid solution, backtrack and try other numbers
                grid[row][col] = 0;
            }
        }

        // If no number can be placed in the current cell, return false and backtrack
        return false;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << grid[i][j] << " ";
            }
        }
    }

private:
    bool is_safe_to_place_number(int grid[N][N], int row, int col, int num) {
        // Check if the number is not in the current row or column
        for (int i = 0; i < N; i++) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }

        // Check if the number is not in the current 3x3 sub-box
        int start_row = 3 * (row / 3);
        int start_col = 3 * (col / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[start_row + i][start_col + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool find_empty_cell(int grid[N][N], int& row, int& col) {
        // Find an empty cell in the grid (marked by 0)
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends