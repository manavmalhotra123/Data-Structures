#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> V = {{1,2,8},{3,4,5}};

    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    

    // finding the maximum element in the vector
    int maxi = -1;
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            if (V[i][j] > maxi)
            {
                maxi = V[i][j];
            }
            
        }
    }
    cout<<"Maximum element in the matrix is "<<maxi<<endl;
    



    return 0;
}
