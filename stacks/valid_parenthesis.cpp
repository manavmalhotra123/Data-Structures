#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isvalid(string input) {
    stack<char> checker;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
            checker.push(input[i]);
        } else if (
            input[i] == '}' && !checker.empty() && checker.top() == '{' ||
            input[i] == ')' && !checker.empty() && checker.top() == '(' ||
            input[i] == ']' && !checker.empty() && checker.top() == '['
        ) {
            checker.pop();
        } else {
            return false;
        }
    }

    return checker.empty();
}

int main() {
    string input = "({})";
    if (isvalid(input))
        cout << "Yes, the brackets are correct!" << endl;
    else
        cout << "No, the brackets are not correct!" << endl;

    return 0;
}
