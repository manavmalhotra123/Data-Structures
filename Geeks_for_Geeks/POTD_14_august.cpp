#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int> nums) {
        std::vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            bool found = false;
            
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                result.push_back(nums[i]);
            }
        }
        
        if (result[0] > result[1]) {
            std::swap(result[0], result[1]);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {1, 2, 3, 2, 1, 4};
    std::vector<int> result = solution.singleNumber(arr);
    
    std::cout << "The two distinct numbers are: " << result[0] << " and " << result[1] << std::endl;
    
    return 0;
}
