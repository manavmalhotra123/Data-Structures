// BST Binary Search Tree
/*
Tree whose node's left node data is smaller than the root node
and the root node's right node data is greater than the root node
data.

Example a sorted array is given;
10 20 30 40 50 60 70

         40
    20        60
10     30  50     70


*/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *InsertIntoBST(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else if (data < root->data)
    {
        root->left = InsertIntoBST(root->left, data);
    }
    else
    {
        root->right = InsertIntoBST(root->right, data);
    }

    return root;
}

void TakeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

// Level Order Traversal
void LevelOrderTraversal(Node *root)
{
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp == nullptr)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
        if (temp->left)
        {
            Q.push(temp->left);
        }
        if (temp->right)
        {
            Q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = nullptr;
    cout << "Enter the data for the nodes (enter -1 to stop): ";
    TakeInput(root);
    LevelOrderTraversal(root);

    cout << endl;

    return 0;
}
