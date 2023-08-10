#include <iostream>
#include <vector>

using namespace std;

string CommonLargestSub(string a, string b, int alen, int blen)
{
    // base case 
    if (alen == 0 || blen == 0)
    {
        // if any of string is empty return ""
        return "";
    }

    if (a[alen - 1] == b[blen - 1])
    {
        // add krke aage bdo 
        return CommonLargestSub(a, b, alen - 1, blen - 1) + a[alen - 1];
    }
    else
    {
        // handling situations
        // when using character of string a
        string case1 = CommonLargestSub(a, b, alen - 1, blen);         // Exclude from a
        // when using character of string b
        string case2 = CommonLargestSub(a, b, alen, blen - 1); 
        // using both        // Exclude from b
        string case3 = CommonLargestSub(a, b, alen - 1, blen - 1) + a[alen - 1]; // Include from both
        // leaving both of them
        string case4 = ""; // Exclude from both

        if (case1.length() >= case2.length() && case1.length() >= case3.length() && case1.length() >= case4.length())
        {
            return case1;
        }
        else if (case2.length() >= case1.length() && case2.length() >= case3.length() && case2.length() >= case4.length())
        {
            return case2;
        }
        else if (case3.length() >= case1.length() && case3.length() >= case2.length() && case3.length() >= case4.length())
        {
            return case3;
        }
        else
        {
            return case4;
        }
    }
}

int main(int argc, char const *argv[])
{
    string Input1 = "ABCFE";
    string Input2 = "ACDFE";
    int n = Input1.length();
    int m = Input2.length();

    string commonLargestSub = CommonLargestSub(Input1, Input2, n, m);
    cout << "Common Largest Subsequence: " << commonLargestSub << endl;

    return 0;
}
