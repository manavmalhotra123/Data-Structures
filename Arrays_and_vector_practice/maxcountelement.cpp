#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void majority_element(vector<int> v)
{
    int n = v.size();
    int check = n/2;
    cout<<check<<endl;
    int majority_index = 0;

    vector<int> candidate;
    vector<int> count;

    int c = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (v[i] == v[j])
            {
                c = c + 1;
            }
            
        }
        candidate.push_back(v[i]);
        count.push_back(c);
        c = 1;
    }
    for (int i = 0; i < count.size(); i++)
    {
        if(count[i] > check){
            majority_index = i;
        }
    }
    
    cout<<"The majority element is "<<v[majority_index]<<endl;
}


int main(int argc, char const *argv[])
{
    vector<int> numbers = {1,2,3,2,2,4,2};
    majority_element(numbers);    

    return 0;
}
