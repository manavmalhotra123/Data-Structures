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

// Function to delete duplicates from a linked list
void deleteDuplicates(ListNode* head) {
    if (!head)
        return;  // If the list is empty, return

    ListNode* slow = head;  // Slow pointer starts at the head
    ListNode* fast = head->next;  // Fast pointer starts one node ahead of the slow pointer

    while (fast) {
        if (slow->val == fast->val) {  // If duplicate node is found
            ListNode* temp = fast;  // Store the duplicate node in a temporary variable
            fast = fast->next;  // Move the fast pointer ahead
            slow->next = fast;  // Adjust the slow pointer's next to skip the duplicate node
            delete temp;  // Delete the duplicate node to free memory
        } else {
            slow = slow->next;  // Move the slow pointer ahead
            fast = fast->next;  // Move the fast pointer ahead
        }
    }
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create the linked list: 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 4
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(3);
    ListNode* node7 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    cout << "Original Linked List: ";
    printList(node1);

    deleteDuplicates(node1);

    cout << "Linked List after removing duplicates: ";
    printList(node1);

    // Clean up memory
    ListNode* current = node1;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
