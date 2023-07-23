#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *L;
    Node *R;
    Node(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

Node* InsertIntoBST(Node* root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->L = InsertIntoBST(root->L, data);
    }
    else if (data > root->data)
    {
        root->R = InsertIntoBST(root->R, data);
    }

    return root;
}

void TakeInput(Node*& root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node* root){
    if (root == nullptr)
    {
        return;
    }
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node* temp = Q.front();
        cout << temp->data <<" ";
        Q.pop();
        if (temp->L)
        {
            Q.push(temp->L);
        }
        if (temp->R)
        {
            Q.push(temp->R);
        }
    }
}

int main()
{
    cout << "Enter the values of nodes of BST(Enter -1 to stop)..." << endl;
    Node* root = nullptr;
    TakeInput(root);
    LevelOrderTraversal(root);

    return 0;
}
