// Merge sort 
/*
--------------- Divide krke sort kra fir ikatha kr diya ---------------
Ek array hai hmaare pass  jisko hmne pehle break kr diya chote parts mai sort krte krte
fir un chote chote sorted parts ko milaake ek bdia sa sorted array bna liya
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> merge_sorted_array(vector<int> left, vector<int> right){
    vector<int> result;
    
    int length_of_right = right.size();
    int length_of_left = left.size();

    int left_array_index = 0;
    int right_array_index = 0;

    // Merge the arrays until one of them is exhausted
    while (left_array_index < length_of_left && right_array_index < length_of_right) 
    {
        if (left[left_array_index] < right[right_array_index])
        {
            result.push_back(left[left_array_index]);
            left_array_index++;
        }
        else
        {
            result.push_back(right[right_array_index]);
            right_array_index++;
        }        
    }

    while (right_array_index < length_of_right)
    {
        result.push_back(right[right_array_index]);
        right_array_index++;
    }
    while (left_array_index < length_of_left)
    {
        result.push_back(left[left_array_index]);
        left_array_index++;
    }
    
    return result;
}

int main(){
    vector<int> array = {1,2,4,5,7,8};
    vector<int> arr = {3,6};
    vector<int> result = merge_sorted_array(array, arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
