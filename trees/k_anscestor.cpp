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
int kthAncestor(TreeNode *root, TreeNode *target, int k)
{
    stack<TreeNode *> ancestors;
    bool found = false;

    // Perform DFS to find the target node
    TreeNode *current = root;
    while (current || !ancestors.empty())
    {
        while (current)
        {
            ancestors.push(current);
            if (current == target)
            {
                found = true;
                break;
            }
            current = current->left;
        }

        if (found)
            break;

        current = ancestors.top();
        if (current->right)
        {
            current = current->right;
        }
        else
        {
            ancestors.pop();
            while (!ancestors.empty() && ancestors.top()->right == current)
            {
                current = ancestors.top();
                ancestors.pop();
            }
            current = ancestors.empty() ? nullptr : ancestors.top()->right;
        }
    }

    // Check if enough ancestors are present
    if (ancestors.size() < k)
        return -1;

    // Pop the top k-1 elements from the stack to get the kth ancestor
    for (int i = 0; i < k - 1; i++)
    {
        ancestors.pop();
    }

    // Return the value of the kth ancestor
    return ancestors.top()->data;
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

    int kthAncestorValue = kthAncestor(root, target, k);

    if (kthAncestorValue != -1)
        cout << "The " << k << "th ancestor of node " << target->data << " is " << kthAncestorValue << endl;
    else
        cout << "There is no " << k << "th ancestor of node " << target->data << endl;

    return 0;
}
