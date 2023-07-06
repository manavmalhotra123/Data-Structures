class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // Stack to store the indices of opening parentheses
        st.push(-1); // Push -1 as the initial index to handle the case where the first character is a closing parenthesis
        int len = 0; // Variable to store the length of the longest valid parentheses substring

        // Iterate through each character of the input string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i); // Push the index of the opening parenthesis onto the stack
            }
            else {
                st.pop(); // Pop the top index from the stack as a matching closing parenthesis is found

                if (st.empty()) {
                    st.push(i); // If the stack becomes empty, push the current index to mark the start of a new potential valid parentheses substring
                }
                else {
                    len = max(len, i - st.top()); // Calculate the length of the current valid parentheses substring and update the maximum length if necessary
                }
            }
        }

        return len; // Return the length of the longest valid parentheses substring
    }
};
