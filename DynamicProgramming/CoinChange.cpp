// Coin Change Problem 
// ek array de rkha jisme coins de rkhe hai jisse ek amount ko create krna 
// return the least number of coins that can be used to make that amount


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// inclusion exclusion 
int coinRecursion(vector<int> &v, int amount, int index)
{
    if(amount == 0){
        return 1; // completion of founding one way
    }
    
    if (amount < 0 || index < 0)
    {
        return 0; // gadbad hogi yha pr 
    }

    // include case 
    int include = coinRecursion(v, amount, index - 1);
    // exclude case
    int exclude = coinRecursion(v,amount - v[index], index);
    
    return include+exclude;
}

int coinchange(vector<int> &coins, int target)
{
    return coinRecursion(coins,target,coins.size()-1);
}


int main(int argc, char const *argv[])
{
    vector<int> v = {2,1,5};
    int target = 11;
    int ans = coinchange(v, target);
    cout<<ans<<endl;

    return 0;
}