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
void AtEnd(Node* &head, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
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
void LinearSearch(Node* head, int target){
    Node* temp = head;
    int position = 0;
    while (temp != NULL)
    {
        position ++;
        if (temp->data == target)
        {
            cout<<"Element found at position "<<position<<endl;
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
    LinearSearch(head,20);


    return 0;
}
