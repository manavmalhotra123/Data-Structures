#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Show(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Normal approach with O(N) time complexity
void MidNode(Node *&head)
{
    int length = 0;
    int mid = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (length % 2 == 0)
    {
        mid = length / 2;
    }
    else
    {
        mid = (length / 2) + 1;
    }
    cout << "Middle node is " << mid << endl;
}
Node* FindMiddleNode(Node* head) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is empty" << endl;
        return NULL;
    }

    // If the list has only one node
    if (head->next == NULL) {
        return head;
    }

    // Initialize the tortoise and hare pointers
    Node* tortoise = head;
    Node* hare = head;

    while (hare != NULL && hare->next != NULL) {
        // Move the hare two steps
        hare = hare->next->next;
        // Move the tortoise one step
        tortoise = tortoise->next;
    }

    return tortoise;
}

int main(int argc, char const *argv[])
{

    Node *head = new Node(10);
    Node *one = new Node(20);
    Node *two = new Node(30);
    Node *three = new Node(40);
    Node *four = new Node(50);
    Node *five = new Node(60);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    Show(head);

    MidNode(head);


    cout<<FindMiddleNode(head)->data<<endl;
    return 0;
}
