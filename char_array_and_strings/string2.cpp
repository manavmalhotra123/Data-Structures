#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> name;

    cout << "Enter your name: ";

    // Read characters until newline is encountered
    char ch;
    while ((ch = cin.get()) != '\n') {
        name.push_back(ch);
    }

    // Convert character vector to string
    string nameStr(name.begin(), name.end());

    // Print the name
    cout << "Hello, " << nameStr << "!" << endl;

    return 0;
}
