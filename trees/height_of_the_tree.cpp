// height of the tree

#include <iostream>
#include <queue>
#include <algorithm>

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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree()
{
    int data;
    cout << "Building tree..." << endl;
    cout << "Enter data : ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "At Left of Node " << root->data << endl;
    root->left = buildTree();

    cout << "At Right of Node " << root->data << endl;
    root->right = buildTree();

    return root;
}


// finding the height of the tree 
// Approach : find the height to left and right of the root of the tree , evaluate the maximum one and add one to it 
int HeightoftheTree(Node *root)
{
    // Base Condition -- if root mai null hai toh khaali hai tree it means height zero hogi 
    if (root == nullptr)
    {
        return 0;
    }
    int leftheight = HeightoftheTree(root->left);
    int rightheight = HeightoftheTree(root->right);

    int height = max(leftheight, rightheight) + 1;
    
    return height;
}


int main(int argc, char const *argv[])
{
    Node* root = buildTree();

    cout<<"Height of the tree is "<<HeightoftheTree(root)<<endl;
    return 0;
}