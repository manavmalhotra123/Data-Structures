// NLR Node Left Right

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildtree()
{
    int data;
    cout << "Enter value: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Currently at left of node " << root->data << endl;
    root->left = buildtree();

    cout << "Now at right of node " << root->data << endl;
    root->right = buildtree();

    return root;
}

// preorder traversal - Node Left Right
void PreOrderTraversal(Node *root)
{
    cout<< "Pre-Order Traversal"<< endl;
    if (root == NULL) 
    {
        return;
    }
    cout<<root->data<<" ";
    
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    
}

int main(int argc, char const *argv[])
{
    Node *root = buildtree();

    // Node Left Right
    cout<<root->data<<" ";

    // PreOrderTraversal
    PreOrderTraversal(root);

    return 0;
}