// backtracking is the special case of the case of recurssion 


#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>

using namespace std;

void print_permutation(string &str, int index)
{
    // base case : jab chek string se bhar nikal jayega
    if (index >= str.length())
    {
        cout << str << endl;
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        // swap str[i] and str[j] to make all possible permutation
        swap(str[index], str[j]);

        // recursive call
        print_permutation(str, index + 1);

        // backtracking -- why ????    
        /* reason : as we passed the string by reference 
        here so after each call the string will get 
        changed hence we need to reserve the original 
        string in order to get all the possible
        combinations without any duplication so we 
        are just reversing the previous swap to 
        maintain the original string */
        swap(str[index], str[j]);
    }
}

int main(int argc, char const *argv[])
{
    string input = "abc";
    int index = 0;
    print_permutation(input, index);
    return 0;
}
