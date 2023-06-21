#include <iostream>
#include <vector>

using namespace std;

// function to print the values of vector
void print_char(const vector<char>& c)
{
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

// function to input the character vector
void input_char(vector<char>& c)
{
    int n;
    cout << "Enter the number of characters you want to add to the vector: ";
    cin >> n;
    
    cout << "n = " << n << endl;
    
    c.resize(n); // Resize the vector to accommodate 'n' elements
    
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
}

int main()
{
    // hardcoding the value of character array
    vector<char> v = {'a', 'b', 'c', 'd'};
    print_char(v);

    vector<char> d;
    // input the values of character array
    input_char(d);
    print_char(d);

    return 0;
}
