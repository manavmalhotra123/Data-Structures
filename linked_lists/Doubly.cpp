#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Printing the doubly linked list
void Display(Node* &head){
    Node* temp = head;

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

    Display(head);


    return 0;
}
