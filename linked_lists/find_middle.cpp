#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void Show(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


void MidNode(Node* &head){
    int length = 0;
    int mid = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (length%2 == 0)
    {
        mid = length/2;
    }
    else
    {
        mid = (length/2) + 1;
    }
    cout<<"Middle node is "<<mid<<endl;
    
    
}



int main(int argc, char const *argv[])
{
    
    Node* head = new Node(10);
    Node* one = new Node(20);
    Node* two = new Node(30);
    Node* three = new Node(40);
    Node* four = new Node(50);
    Node* five = new Node(60);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    Show(head);


    MidNode(head);
    return 0;
}
