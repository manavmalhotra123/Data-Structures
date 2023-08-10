#include <iostream>
#include <vector>

using namespace std;

void subsequence(string input, int n, string current, int index)
{
    if (index == n)
    {
        cout << current << endl;
        return;
    }

    // Include the current character and move to the next index
    subsequence(input, n, current + input[index], index + 1);

    // Exclude the current character and move to the next index
    subsequence(input, n, current, index + 1);
}

int main(int argc, char const *argv[])
{
    string Input = "ABCFE";
    int n = Input.length();

    subsequence(Input, n, "", 0);

    return 0;
}
