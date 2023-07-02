#include <iostream>
#include <algorithm>
#include <vector>

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

// insert a node at the head of the circular linked list
void InsertAtHead(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head; // Make the only node point to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

// insert at the end of the circular linked list
void AtEnd(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head; // Make the only node point to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

// insert a node at a specific position in the circular linked list
void BetweenInsert(Node *head, int position, int value)
{
    Node *temp = head;
    Node *newnode = new Node(value);
    int count = 1;

    while (count < position - 1 && temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// delete a node by its value from the circular linked list
void DeleteByElement(Node *&head, int target)
{
    if (head == NULL)
        return;

    Node *temp = head;
    Node *prev = NULL;

    // If the head node itself contains the target value
    if (temp->data == target)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    // Search for the node with the target value
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        if (temp->data == target)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
    }
}

// print the circular linked list
void print(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << "-->";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    InsertAtHead(head, 10);
    InsertAtHead(head, 20);
    InsertAtHead(head, 30);
    print(head);

    AtEnd(head, 56);
    print(head);

    int val = 90;
    int position = 3;
    BetweenInsert(head, position, val);
    print(head);

    DeleteByElement(head, val);
    print(head);

    return 0;
}
