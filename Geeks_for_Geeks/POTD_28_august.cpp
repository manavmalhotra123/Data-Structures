#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node* insert(Node* head, int data)
{
    if(head == nullptr)
    {
        return new Node(data);
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(data);
        return head;
    }
}

void print(Node* head)
{
    while(head!= nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Function to delete duplicates from a linked list
void deleteDuplicates(Node* head) {
    if (!head)
        return;  // If the list is empty, return

    Node* slow = head;  // Slow pointer starts at the head
    Node* fast = head->next;  // Fast pointer starts one node ahead of the slow pointer

    while (fast) {
        if (slow->data == fast->data) {  // If duplicate node is found
            Node* temp = fast;  // Store the duplicate node in a temporary variable
            fast = fast->next;  // Move the fast pointer ahead
            slow->next = fast;  // Adjust the slow pointer's next to skip the duplicate node
            delete temp;  // Delete the duplicate node to free memory
        } else {
            slow = slow->next;  // Move the slow pointer ahead
            fast = fast->next;  // Move the fast pointer ahead
        }
    }
}

int main()
{
    Node* head = nullptr;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 5);
    print(head);

    deleteDuplicates(head);
    print(head);
    return 0;
}