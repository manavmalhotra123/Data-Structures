#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Print the linked list
void ShowList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Length(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

// Reversing the K-Groups
Node *reverseKNodes(Node *head, int k)
{
    // if the list is empty
    if (head == nullptr)
    {
        return nullptr;
    }
    int length = Length(head);
    // if the demand of reversing is more than K
    if (k > length)
    {
        cout << "Invalid Demand" << endl;
        return head;
    }

    // Step 1: reverse the first k nodes of the linked list
    Node *prev = nullptr;
    Node *current = head;
    Node *forward = nullptr;

    // reversing the first k nodes
    // to track the node counts
    int count = 0;
    while (count < k)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;

        count++;
    }

    // Recursive Call
    if (forward != nullptr)
    {
        // now we still have nodes of reverse
        head->next = reverseKNodes(forward, k); // update next pointer of the original head
    }

    // Step 3: return the new head of the reversed group
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *one = new Node(20);
    Node *two = new Node(30);
    Node *three = new Node(40);
    Node *fourth = new Node(50);
    Node *fifth = new Node(60);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = fourth;
    fourth->next = fifth;

    // print the linked list
    ShowList(head);

    // reversing the k groups
    head = reverseKNodes(head, 3);

    // print the reversed linked list
    ShowList(head);

    return 0;
}
