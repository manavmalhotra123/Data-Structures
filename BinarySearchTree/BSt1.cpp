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

// Tree Node Class
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

// Condition to insert the node into the tree
Node *InsertIntoBST(Node *root, int data)
{
    // if root hi khaali hai toh whi node bnaade
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else if (data < root->data)
    {
        // agr data root ke data se chota toh left
        root->left = InsertIntoBST(root->left, data);
    }
    else
    {
        // otherwise right
        root->right = InsertIntoBST(root->right, data);
    }
    return root;
}

// Function to take simuntaneous inputs
void TakeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        // function to insert the value in the BST
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

void InorderTraversal(Node *root){

    if (root == nullptr)
    {
        return;
    }
    
    // LNR - left node right
    InorderTraversal(root->left);
    cout<<root->data << " ";
    InorderTraversal(root->right);
}


// LRN 
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void PreOrderTraversal(Node *root)
{
    
    if (root == NULL) 
    {
        return;
    }
    cout<<root->data<<" ";
    
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    
}


int main()
{
    Node *root = nullptr;
    cout << "Enter the data for the nodes (enter -1 to stop): ";
    TakeInput(root);
    cout<<"level Order Traversal"<< endl;
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<"Pre-Order Traversal"<<endl;
    PreOrderTraversal(root);
    cout<<"In-Order Traversal"<<endl;
    InorderTraversal(root);
    cout<<"Post-Order Traversal"<<endl;
    postOrderTraversal(root);

    cout << endl;

    return 0;
}
