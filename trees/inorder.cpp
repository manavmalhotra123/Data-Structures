// LNR - Left Node Right

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
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *BuildTree()
{
    int data;
    cout << "Enter Data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "At left of node " << root->data << " " << endl;
    root->left = BuildTree();

    cout << "At right of node " << root->data << " " << endl;
    root->right = BuildTree();


    return root;
}


// recursive function with LNR (Left Node right approach)
void InorderTraversal(Node* root){
    cout<<"InorderTraversal ";
    // base Case : if root null hogi toh traverse krna bnd krdo 
    if (root == NULL)
    {
        return;
    }

    // LNR - left node right
    InorderTraversal(root->left);
    cout<<root->data << " ";
    InorderTraversal(root->right);
    
}

int main(int argc, char const *argv[])
{
    Node* root = BuildTree();
    InorderTraversal(root);
    return 0;
}