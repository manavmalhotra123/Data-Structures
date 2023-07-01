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
