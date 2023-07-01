// taking the linked as input 

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// insert a node at the head the of linked list 
void InsertAtHead(Node* &head,int data){
    // Step 1
    Node* newnode = new Node(data); // inserting the data in the node 
    // Step 2
    newnode->next = head;
    // Step 3
    head = newnode;
}

// print function 
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main(int argc, char const *argv[])
{
    Node* head = NULL;
    InsertAtHead(head,10);    
    InsertAtHead(head,20);    
    InsertAtHead(head,30);    
    print(head);

    
    return 0;
}
