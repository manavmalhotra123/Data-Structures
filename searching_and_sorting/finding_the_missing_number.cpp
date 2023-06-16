#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void finding_sum_till_largest_number_then_subtract_from_sum_of_actual_number(vector<int>& v){

int maxi = -1;
for (int i = 0; i < v.size(); i++)
{
    if (v[i] > maxi)
    {
        maxi = v[i];
    }
}

int sum = 0;
for (int i = 0; i <= maxi; i++)
{
    sum = sum + i;
}

int real_sum = 0;
for (int i = 0; i < v.size(); i++)
{
    real_sum += v[i];
}

int missing_element = sum - real_sum;

cout << "The missing element is "<<missing_element << endl;

}





int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,11};
    finding_sum_till_largest_number_then_subtract_from_sum_of_actual_number(v);
    return 0;
}
