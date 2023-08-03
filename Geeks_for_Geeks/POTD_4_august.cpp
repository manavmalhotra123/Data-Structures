#include <stack>

class Solution {
public:
    void Reverse(stack<int> &St) {
        if (St.empty())
            return;

        // Get the top element of the stack
        int topElement = St.top();
        St.pop();

        // Reverse the remaining stack
        Reverse(St);

        // Insert the top element at the bottom of the reversed stack
        insertAtBottom(St, topElement);
    }

private:
    void insertAtBottom(stack<int> &St, int element) {
        if (St.empty()) {
            St.push(element);
            return;
        }

        // Get the top element of the stack
        int topElement = St.top();
        St.pop();

        // Recursively insert the element at the bottom of the remaining stack
        insertAtBottom(St, element);

        // Push the top element back to the stack
        St.push(topElement);
    }
};
