#include <iostream>

using namespace std;


// Node class
class Node
{
    public:
        int data;   // data in the node
        Node* next; // pointer to previous node
        Node* prev; // pointer to next node

        // constructor to initialize the node with 0 value
        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        
        // constructor initialize the node with some value by user
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Printing the doubly linked list
void Display(Node* &head){
    Node* temp = head;
    
    // traversing the whole list 
    while (temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

int main()
{
    Node* head = new Node(4);
    Node* first = new Node(5);    
    Node* second = new Node(6);    
    Node* third = new Node(7); 

    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;

    // function to display the doubly linked lists
    Display(head);


    return 0;
}
