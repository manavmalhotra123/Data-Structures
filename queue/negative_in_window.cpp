// sliding window question 
// Find the first negative integer in the window of size k 

/*
    Test Case 1:
    Given Queue;  12 -1 -7 8 -15 30 16 18
          Window Size : 3

    Solution: 
    Window 1: 12 -1 -7       --  (-1)
    Window 2: -1 -7 8        --  (-1)
    Window 3: -7 8 -15       --  (-7)
    Window 4: 8 -15 30       --  (-15)
    Window 5: -15 30 16      --  (-15)
    Window 6: 30 16 18       --  (0)
*/



// if the given data structure is vector
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    std::vector<int> v = {12,-1,-7,8,-15,30,16,18};
    vector<int> output;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < i+4; j++)
        {
            if (v[j] < 0)
            {
                
                output.push_back(v[j]);
                break;
            }
            
        }
        
    }
    
    // printing the output vector
    cout<<"Solution: "; 
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    
    

    return 0;
}
