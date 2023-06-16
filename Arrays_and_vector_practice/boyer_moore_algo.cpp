#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void majority(vector<int> v)
{
    // Finding the size of vector
    int n = size(v);
    int majority = v[0]; // assuming that first element is majority
    int count = 1; // intitial count of each element is 1

    // finding the majority element
    for (int i = 0; i < n; i++)
    {
        if (v[i] == majority)
        {
            count = count + 1;
        }
        else
        {
            count --;
            if (count == 0)
            {
                majority = v[i];
                count ++;
            }            
        }   
    }

    // checking that the potential element is actual majority
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == majority)
        {
            count = count + 1;
        }
        
    }

    if (count > n/2)
    {
        cout<<"majority element is "<<majority<<endl;
    }
    
    

}



int main(int argc, char const *argv[])
{
    
    vector<int> numbers = {1,2,3,2,2,4,2};
    majority(numbers);    

    return 0;
}
