#include <iostream>

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


// print the linked list 
void print(Node* &head){
    Node* current = head;
    while (current != NULL)
    {
        cout<<current->data<<"-->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
    
}

// Length fuction 
int GetLength(Node* &head){
    int length = 0;
    Node* current = head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}


// reverse k nodes 
Node* ReverseKNodes(Node* head, int k){
    
    
    // agar list khaali hai toh kuch bhi nhi return kr skte bhai
    if (head == NULL) 
    {
        return NULL;
    }
    // if ek hi node hai toh whi return maardo 
    if (head->next == NULL)
    {
        return head;
    }
    // check whether the demand is valid or not 
    int length = GetLength(head); 
    if (k > length)
    {
        cout<<"Invalid"<<endl;
        return head;
    }
    
    // reversing the k nodes now 
    // if your code have reached till this point it means demand valid hai 

    // step 1: initialize the pointer you need to reverse the nodes
    Node* previous = NULL;
    Node* current = head;
    Node* forward = NULL;

    // Step 2: initialize the integer to keep the track of number of nodes 
    int count = 0;

    // Step 3: start the reversing loop 
    while(count < k){
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;

        count++;
    }    

    // Till now we have handled the case of k nodes 
    // Baaki recursion ko krne dete hai ab 
    // but before applying the recursion we need to check ki nodes hai bhi aage ya nhi 
    if (forward != NULL)
    {
     head->next =   ReverseKNodes(forward,k);
    }

    // Step 4: return the new head of the reversed group
    return previous;
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

    print(head);

    head = ReverseKNodes(head,2);

print(head);
    return 0;
}
