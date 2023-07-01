// taking the linked as input

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

// insert a node at the head the of linked list
void InsertAtHead(Node *&head, int data)
{
    // Step 1
    Node *newnode = new Node(data); // inserting the data in the node
    // Step 2
    newnode->next = head;
    // Step 3
    head = newnode;
}

// insert at tail or you can say at the end of the list
// step 1: create a new node with the data - int data
// step 2: join that new node with the last node of the linked list
// insert the node at end of the linked list
void AtEnd(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}

// insert the value at some position in linked list
// Step 1: reach to the before position element
// Step 2: update the pointer to the inserting node
// Step 3: update the pointer of the inserted node to the next position node
void BetweenInsert(Node *head, int position, int value)
{
    Node *temp = head;
    Node *newnode = new Node(value);
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        // Position exceeds the length of the list
        delete newnode; // Clean up memory allocated for newnode
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// print function
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Linear search function in linked list
void LinearSearch(Node *head, int target)
{
    Node *temp = head;
    int position = 0;
    while (temp != NULL)
    {
        position++;
        if (temp->data == target)
        {
            cout << "Element found at position " << position << endl;
        }
        temp = temp->next;
    }
}

// finding the length of the linked list
void FindLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    cout << "Length " << length << endl;
}

// deletion function likhna hai ab yha pr merko linked lists ka
// Step 1: element ki position dhundo jo delete krna hai
// Step 2: us node ko uda do
// Step 3: pichle node to next te next se attach krdo simple
void DeleteByElement(Node*& head, int target)
{
    Node* temp = head;

    // Handle the case where the target value is at the beginning of the list
    if (temp != nullptr && temp->data == target)
    {
        head = temp->next;
        delete temp;
        return;
    }

    // Search for the target value in the rest of the list
    while (temp != nullptr)
    {
        if (temp->next != nullptr && temp->next->data == target)
        {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
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

    // search function in linked list
    LinearSearch(head, 20);

    // inserting the node in betweeen the linked list
    int val = 90;
    int position = 3;
    BetweenInsert(head, position, val);

    print(head);

    // finding the length
    FindLength(head);

    // deleting the node by value
    DeleteByElement(head, val);

    print(head);

    return 0;
}
