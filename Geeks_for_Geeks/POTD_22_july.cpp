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
        this->next = nullptr;
    }
};

Node *InsertInLinkedLists(Node *head, int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        return head;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new Node(data);
    return head;
}

void Show(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void Remove(Node *head, int n)
{
    if (head == nullptr || n <= 0)
    {
        return;
    }

    if (n == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int count = 0;
    Node *temp = head;
    while (count < n - 1 && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        // n is greater than the number of nodes in the list
        return;
    }

    Node *nodeToRemove = temp->next;
    temp->next = temp->next->next;
    delete nodeToRemove;
}

int main(int argc, char const *argv[])
{
    Node *Head = nullptr;

    Head = InsertInLinkedLists(Head, 1);
    Head = InsertInLinkedLists(Head, 2);
    Head = InsertInLinkedLists(Head, 3);
    Head = InsertInLinkedLists(Head, 4);
    Head = InsertInLinkedLists(Head, 1);
    Head = InsertInLinkedLists(Head, 2);
    Head = InsertInLinkedLists(Head, 3);

    Show(Head);

    
    return 0;
}
