// find the length of the longes subsequence of an array 
#include <iostream>
#include <vector>

using namespace std;

int longest(vector<int> input)
{
    
    int maxlength = -1;
    for (int i = 0; i < input.size(); i++)
    {
        int count = 1;
        for (int j = i+1; j < input.size(); j++)
        {
            if (input[i] == input[j])
            {
                count++;
            }
            
        }
        if (count > maxlength)
        {
            maxlength = count;
        }
    }
    return maxlength;
}



int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,5,1,2,2};

    cout<<longest(v);

    return 0;
}