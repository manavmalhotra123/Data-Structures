// BUBBLE SORT 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void print_vector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void bubble_sort(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            
        }
        
    }
    
}

int main(){
    vector<int> v = {5,4,3,2,1};
    print_vector(v);
    bubble_sort(v);
    print_vector(v);
    return 0;
}