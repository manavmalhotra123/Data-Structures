#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>

using namespace std;

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		if(matrix[i][j]){
        			int cnt = 0;
        			if(i - 1 >= 0)
        				cnt += matrix[i-1][j] == 0;
        			if(i + 1 < n)
        				cnt += matrix[i+1][j] == 0;
        			if(j - 1 >= 0)
        				cnt += matrix[i][j-1] == 0;
        			if(j + 1 < m)
        				cnt += matrix[i][j+1] == 0;
        			if(i - 1 >= 0 and j - 1 >= 0)
        				cnt += matrix[i-1][j-1] == 0;
        			if(i - 1 >= 0 and j + 1 < m)
        				cnt += matrix[i-1][j+1] == 0;
        			if(i + 1 < n and j - 1 >= 0)
        				cnt += matrix[i+1][j-1] == 0;
        			if(i + 1 < n and j + 1 < m)
        				cnt += matrix[i+1][j+1] == 0;
        			if(!(cnt & 1) and cnt)
        				ans++;
        		}
        	}
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> input = {{1,0,0},{1,1,0},{0,1,0}};
    Solution s;
    int answer = s.Count(input);
    cout << answer << endl;
    return 0;
}
