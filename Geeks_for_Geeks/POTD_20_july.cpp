

class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S) {
        int charOccurrences[26] = {0};  // Array to store character occurrences (assuming lowercase Latin letters)

        // Count the occurrences of each character
        for (char ch : S) {
            charOccurrences[ch - 'a']++;
        }

        char nonRepeatingChar = '$';  // Default value if no non-repeating character is found

        // Iterate through the string to find the first non-repeating character
        for (char ch : S) {
            if (charOccurrences[ch - 'a'] == 1) {
                nonRepeatingChar = ch;
                break;
            }
        }

        return nonRepeatingChar;
    }
};