#include<iostream>
#include<vector>

using namespace std;
 
int main(){
    vector<int> v = {1,3,4,7};

    int sum = 10;
    
    int count = 0;

    // finding triplet sum 
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                if (v[i] + v[j] + v[k]  == sum)
                {
                    count = count + 1;
                    cout<<"Triplet  "<<count<<endl;
                    cout<<v[i]<<","<<v[j]<<" and "<<v[k]<<endl;
                }
                
            }
            
        }
        
    }
    

    return 0;
}