#include<iostream>
#include<algorithm>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Printing the list 
void Display(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// inserting the new node in the position
void Inbew(Node* &head, int position, int data) {
    Node* temp = head;
    Node* newnode = new Node(data);
    int count = 0;

    if (position == 1) {
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
    } else {
        while (temp != NULL && count < position - 1) {
            count++;
            temp = temp->next;
        }

        if (temp == NULL) {
            return;
        }

        newnode->prev = temp;
        newnode->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }

        temp->next = newnode;
    }
}

//  Delete the node by it's value
void DeleteNode(Node* &head, int target){
    // temp node for tracking the position
    Node* temp = head;
    // Find the node to delete
    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }
    // if the node is foiund 
    if (temp != NULL)
    {
        // update the prevous reference
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

// length of the doubly linked list 
void LenghtList(Node* &head){
    Node* temp = head;
    int length = 0;
    while (temp != NULL) 
    {
        length++;
        temp = temp->next;
    }
    cout<<"length of the doubly linked list is "<<length<<endl;   
}

// Linear Search in doubly linked list 
void LinearSearch(Node* &head,int target){
    int position = 0;
    Node* temp = head;
    while (temp != NULL){

        if (temp->data == target)
        {
            cout<<"Position at which the element found is "<<position<<endl;
        }
        position++;
        temp = temp->next;        
    }
}


int main(int argc, char const *argv[])
{
    Node* head = new Node(5);
    Inbew(head,1,34);
    Inbew(head,2,4);
    Inbew(head,3,30);
    Inbew(head,4,340);
    Display(head);

    LenghtList(head);

    LinearSearch(head,4);


    DeleteNode(head,4);
    Display(head);
    return 0;
}
