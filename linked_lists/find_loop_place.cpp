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

Node* findNode(Node* &head) {
    Node* tortoise = head;
    Node* hare = head;
    bool isloop = false;

    if (head == NULL) {
        cout << "No loop found!" << endl;
        return NULL;
    }
    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            isloop = true;
            break;
        }
    }

    // Loop found
    if (isloop) {
        hare = head;
        while (hare != tortoise) {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return hare;
    }

    return NULL;
}

int main(int argc, char const* argv[]) {
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

    Node* loopStartNode = findNode(one);
    if (loopStartNode != NULL) {
        cout << "Loop found. The loop starts at node with data: " << loopStartNode->data << endl;
    } else {
        cout << "No loop found!" << endl;
    }

    return 0;
}
