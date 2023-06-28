// finding the maximum element of the array

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

// using recursive function
void maxi_using_recursive(vector<int> &v,int i,int &maxi){
    
    // jaise hi array khtm ho jayega uth ke bhaar aaja 
    if (i >= v.size()) 
    {
        return;
    }
    
    // ek case solve krna hai bs : ki current element maximum hai ya nhi 
    if (v[i] > maxi)
    {
        maxi = v[i];
    }
    
    // baaki recurssion smbhaal lega tune kyu tension li hai bro 
    maxi_using_recursive(v,i+1,maxi);
}

// using loop iteration function
void maxi_using_loop(vector<int> &v){
    int maxi = INT16_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > maxi)
        {
            maxi = v[i];
        }
    }
    cout<<"maximum element is "<<maxi<<endl;
    
}

int main(int argc, char const *argv[])
{
    vector<int> v = {0,23,43,23,1,12,32};

    int maxi = INT16_MIN;

    maxi_using_recursive(v,0,maxi);

    cout<<"Maximum element maximum hai "<<maxi<<endl;

    maxi_using_loop(v);
    return 0;
}
