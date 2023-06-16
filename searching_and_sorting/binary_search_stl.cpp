#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vals = {0, 1, 2, 23, 4, 50, 6, 7};

    if (binary_search(vals.begin(),vals.end(),1))
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    
    return 0;
}
