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

// using slow fast approach 
bool isCircular(Node* &head){
    if (head == NULL) 
    {
        cout<<"Not"<<endl;
        return false;
    }
    
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout<<"Not"<<endl;
            return false;
        }        
    }
    cout<<"yes"<<endl;
    return true;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
} 

int main(int argc, char const *argv[])
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = one;

    

    isCircular(one);
    return 0;
}
