#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool enable = true;


class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Show(Node *head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    Node *temp = head;
    cout << temp->data << "-->";
    Show(temp->next);
    
}void Sort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return; // No need to sort empty or single-node lists

    Node *zeroHead = new Node(0);
    Node *oneHead = new Node(0);
    Node *twoHead = new Node(0);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *current = head;

    while (current != NULL)
    {
        if (current->data == 0)
        {
            zeroTail->next = current;
            zeroTail = current;
        }
        else if (current->data == 1)
        {
            oneTail->next = current;
            oneTail = current;
        }
        else // Assuming data can only be 0, 1, or 2
        {
            twoTail->next = current;
            twoTail = current;
        }

        current = current->next;
    }

    // Connect the three lists
    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // Set the head of the sorted list
    head = zeroHead->next;

    // Free the dummy nodes used for merging
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}
int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(0);
    Node *four = new Node(1);
    Node *five = new Node(2);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    cout << "Original Linked List: ";
    Show(head);

    Sort(head);

    cout << "Sorted Linked List: ";
    Show(head);

    // Don't forget to free the memory allocated for the linked list
    Node *current = head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
