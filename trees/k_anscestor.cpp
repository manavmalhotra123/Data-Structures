#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};



// Function to find the kth ancestor of a node in a binary tree
bool KthAncestor(TreeNode* root, int k, TreeNode* p)
{
    // base case
    if (root == nullptr)
    {
        return false;
    }

    if (root == p || KthAncestor(root->left, k, p) || KthAncestor(root->right, k, p))
    {
        if (k == 0)
        {
            cout << "Kth ancestor is " << root->data << endl;
        }
        k--;
        return true;
    }

    return false;
}




int main()
{
    // Build the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Find the kth ancestor of a node
    TreeNode *target = root->left->right; // Node with value 5
    int k = 2;

    bool result = KthAncestor(root,k,target);

    return 0;
}
