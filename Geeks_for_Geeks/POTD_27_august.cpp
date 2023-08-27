class Solution
{
public:
    string reverseWord(string str)
    {
        int j = str.size() - 1;
        for (int i = 0; i < str.size() / 2; i++)
        {
            swap(str[i], str[j]);
            j--;
        }
        return str; // Return the reversed string
    }
};


