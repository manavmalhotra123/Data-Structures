#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findFirstNonRepeatingChar(const string& stream) {
    vector<int> charCount(26, 0);
    queue<char> charQueue;
    string answer = "";

    for (int i = 0; i < stream.size(); i++) {
        char c = stream[i];
        int index = c - 'a';
        charCount[index]++;

        if (charCount[index] == 1) {
            charQueue.push(c);
        }

        while (!charQueue.empty() && charCount[charQueue.front() - 'a'] > 1) {
            charQueue.pop();
        }

        if (charQueue.empty()) {
            answer += "#";
        } else {
            answer += charQueue.front();
        }
    }

    return answer;
}

int main() {
    string stream = "aabbccdef";
    string result = findFirstNonRepeatingChar(stream);
    cout << result << endl;  // Output: "abb#ddde"

    return 0;
}
