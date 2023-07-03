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

bool detectAndRemoveLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    bool hasLoop = false;

    // Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasLoop = true;
            break;
        }
    }

    if (hasLoop) {
        // Move slow pointer to the head and move both pointers at the same speed until they meet again
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Set the next pointer of the last node in the loop to NULL to remove the loop
        fast->next = NULL;
        return true;
    }

    return false;
}

// print the linked list 
void print(Node *head){
    Node* current = head;
    while (current->next != NULL){
        cout<<current->data<<"-->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
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

    bool loopDetected = detectAndRemoveLoop(one);
    if (loopDetected) {
        cout << "Loop detected and removed successfully." << endl;
    } else {
        cout << "No loop found." << endl;
    }

    print(one);

    return 0;
}
