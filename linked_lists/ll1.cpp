// Linked Lists --  two solve the problem of internal fragmentation linked lists are introduced
// non continous space allocation bhi ho skti hai isme 
// vector waala double krke space waste krne ka koi dikkat hi nhi hoga yha

/*
- a single part of linked list is known as node.. 
- insertion and deletion easy hai kaafi as yha pr direct pointers se hum deal krte hai O(1).
- dynamically shrink and grow ho skti hai 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// A node 
class Node
{
    public:

    int data; // data in the node 
    Node* next; // pointer to next node

    // for creating a node with zero value as data
    Node(){
        this->data = 0;
        this->next = NULL;
    } 
    // for creating a node with the user defined value as data 
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// print function 
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// driver function 
int main(int argc, char const *argv[])
{
    Node* head = new Node(); // node with the value 0 
    Node* first = new Node(5); // node with the value 5
    Node* second = new Node(4); // node with the value 4

    head->next = first;
    first->next = second;

    // printing the linked lists 
    cout<<"Linked list"<<endl;
    print(head);

    return 0;
}
