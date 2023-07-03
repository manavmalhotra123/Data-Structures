#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = slow;

    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    ListNode* left = head;
    ListNode* right = prev;

    while (right) {
        if (left->val != right->val)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Check if the linked list is a palindrome
    cout << boolalpha << isPalindrome(node1) << endl;  // Output: true

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
