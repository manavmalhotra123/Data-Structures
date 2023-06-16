// linear search

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> vals = {0,1,2,23,4,50,6,7};

    int index = -1;

    int key = 23;

    for (int i = 0; i < vals.size(); i++)
    {
        if (vals[i] == key)
        {
            index = i;
            break;
        }
        
    }

    if (index == -1)
    {
       cout<<"ERROR:Element not found in vector!!"<<endl;
    }
    else
    {
        cout<<"found at index "<<index<<endl;
    }
    
    
       
}