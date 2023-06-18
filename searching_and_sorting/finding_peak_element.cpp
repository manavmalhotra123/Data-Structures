#include <iostream>
#include <vector>

using namespace std;

void findPeakElement(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < nums[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    cout<<"Peak: "<<end<<endl;
}


void find_peak(vector<int> &v){
    int maxi = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (maxi < v[i])
        {
            maxi = v[i];
        }
        
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == maxi)
        {
            cout<<"location of peak element "<<i<<endl;
        }
        
    }
    
}
 

int main() {

    vector<int> mountain = {0, 10, 5, 2};

    findPeakElement(mountain);

    find_peak(mountain);

    return 0;
}
