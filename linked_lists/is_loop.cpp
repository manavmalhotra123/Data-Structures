#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool hasLoop(Node* head) {
    if (head == NULL) {
        return false;  // Empty list, no loop
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;  // Found a loop
        }
    }

    return false;  // No loop found
}

int main() {
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    // Uncomment the following line to create a loop in the linked list
    five->next = two;

    if (hasLoop(one)) {
        cout << "The linked list has a loop." << endl;
    } else {
        cout << "The linked list does not have a loop." << endl;
    }

    return 0;
}
