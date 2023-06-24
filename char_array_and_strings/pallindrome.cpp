#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<char> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Pallindrome : Algorithm yeh hai ki start ko end se match krte jaayo jab center tk phunchne pr sab match hore ho toh srting pallindrome mai hai 
bool Pallindrome(vector<char> v)
{
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        if (v[start] != v[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void check_and_tell(bool check)
{
    if (check == true)
    {
        cout << "The given string is in Pallindrome" << endl;
    }
    else
    {
        cout << "The given string is not in Pallindrome" << endl;
    }
}

int main()
{

    vector<char> arr = {'n', 'o', 'o', 'o', 'n'};
    print_vector(arr);
    bool check = Pallindrome(arr);
    check_and_tell(check);
    return 0;
}