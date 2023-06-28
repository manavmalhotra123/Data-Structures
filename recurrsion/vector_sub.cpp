// inclusion - exclusion in vector

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_vector(vector<int> &input){
    for (int i = 0; i < input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}


void sub(vector<int> &input, vector<int> &output,int iterator){
    if (iterator == input.size())
    {
        print_vector(output);
        return;
    }
    
    // exclude case
    sub(input, output, iterator + 1);

    // include case 
    output.push_back(input[iterator]);
    sub(input, output, iterator + 1);

    
}


int main(int argc, char const *argv[])
{
    vector<int> input = {1,0};
    vector<int> output;
    int iterator = 0;

    sub(input, output, iterator);
    
    return 0;
}
