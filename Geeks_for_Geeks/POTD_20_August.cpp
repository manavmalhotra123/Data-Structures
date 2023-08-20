#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int Solve(vector<int>& input, int target)
    {
        int firstOccurrence = findFirstOccurrence(input, target);
        if (firstOccurrence == -1) {
            return -1;
        }
        
        int lastOccurrence = findLastOccurrence(input, target);

        return lastOccurrence - firstOccurrence + 1;
    }

private:
    int findFirstOccurrence(vector<int>& input, int target)
    {
        int left = 0;
        int right = input.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (input[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

            if (input[mid] == target) {
                result = mid;
            }
        }

        return result;
    }

    int findLastOccurrence(vector<int>& input, int target)
    {
        int left = 0;
        int right = input.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (input[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            if (input[mid] == target) {
                result = mid;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> input = {1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
    int target = 2;

    Solution solution;
    int result = solution.Solve(input, target);
    if (result == -1)
    {
        cout<<"Not Found!!"<<endl;
    }
    else
    {
        cout<<"Number of times "<<target<<" occured in vector is "<<result<<endl;
    }
    
    return 0;
}
