
class Solution
{
public:
    // Function to find minimum number of operations that are required 
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> sumRow(n, 0);
        vector<int> sumCol(n, 0);

        // Calculating sumRow[] and sumCol[] array.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sumRow[i] += matrix[i][j];
                sumCol[j] += matrix[i][j];
            }
        }

        // Finding maximum sum value in either row or column.
        int maxSum = 0;
        for (int i = 0; i < n; ++i)
        {
            maxSum = max(maxSum, sumRow[i]);
            maxSum = max(maxSum, sumCol[i]);
        }

        int count = 0;
        for (int i = 0, j = 0; i < n && j < n;)
        {
            // Finding minimum increment required in either row or column.
            int diff = min(maxSum - sumRow[i], maxSum - sumCol[j]);

            // Adding difference in corresponding cell, sumRow[] and sumCol[] array.
            matrix[i][j] += diff;
            sumRow[i] += diff;
            sumCol[j] += diff;

            // Updating the result.
            count += diff;

            // If ith row is satisfied, incrementing i for next iteration.
            if (sumRow[i] == maxSum)
                ++i;

            // If jth column is satisfied, incrementing j for next iteration.
            if (sumCol[j] == maxSum)
                ++j;
        }
        // Returning the result.
        return count;
    }
};

