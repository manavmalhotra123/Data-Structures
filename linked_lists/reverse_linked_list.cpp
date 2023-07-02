#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// print in reverse -- using recursive function
// Tail recursive function
void Reverse_print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Reverse_print(head->next);

    cout << head->data << "-->";
}

// Reverse the Linked list - reversing linked list in actual
void Link_reverse(Node *&head)
{
    // check if the linked list is empty or having single element
    if (head == NULL || head->next == NULL)
    {
        return;
        // As linked list with single element or no element cannot be reversed
    }

    // Nodes needed to reverse the list
    Node *previous = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous; // update the pointer
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(5);
    Node *first = new Node(6);
    Node *second = new Node(7);
    Node *third = new Node(8);
    Node *forth = new Node(9);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;

    Display(head);

    // print the linked list in reverse order
    Reverse_print(head);
    cout << endl;
    // reversing the list
    Link_reverse(head);

    Display(head);

    return 0;
}
