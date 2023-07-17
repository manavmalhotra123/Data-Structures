#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findFirstNonRepeatingChar(const string& stream) {
    // Initialize a vector to store the count of each character encountered
    vector<int> charCount(26, 0);

    // Initialize a queue to maintain the order of characters
    queue<char> charQueue;

    // Initialize an empty string to store the answer
    string answer = "";

    // Iterate over each character in the stream
    for (int i = 0; i < stream.size(); i++) {
        char c = stream[i];

        // Calculate the index of the character in the charCount vector
        int index = c - 'a';

        // Increment the count of the character at the calculated index
        charCount[index]++;

        // If the count of the character is 1, add it to the charQueue
        if (charCount[index] == 1) {
            charQueue.push(c);
        }

        // Check the front of the charQueue until it becomes empty or
        // the count of the front character becomes more than 1
        while (!charQueue.empty() && charCount[charQueue.front() - 'a'] > 1) {
            charQueue.pop();
        }

        // Append the first character in the charQueue to the answer
        // If the charQueue is empty, append '#' to the answer
        if (charQueue.empty()) {
            answer += "#";
        } else {
            answer += charQueue.front();
        }
    }

    // Return the final answer
    return answer;
}

int main() {
    string stream = "aabbccdef";
    string result = findFirstNonRepeatingChar(stream);
    cout << result << endl;  // Output: "abb#ddde"

    return 0;
}
