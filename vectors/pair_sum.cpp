#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v)
{
    cout << "Your vector is " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 3, 5, 7,0,9};
    vector<int> v1 = {2, 4, 6,9,0};
    print_vector(v1);
    print_vector(v);

    int sum = 9;

    int count = 0;

    // find a pair that will form 9 as it's sum
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v1.size(); j++)
        {
            if (v[i] + v1[j] == sum)
            {
                count++;
                cout << "Pair " << count << " : " << v[i] << " and " << v1[j] << endl;
            }
        }

    return 0;
}
