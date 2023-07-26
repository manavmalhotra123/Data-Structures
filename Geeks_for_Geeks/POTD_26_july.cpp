#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

bool KthAnscestor(TreeNode* root, int &k, TreeNode* node)
{
    if (root == NULL)
    {
        return false;
    }

    if (root == node || KthAnscestor(root->left,k,node) || KthAnscestor(root->right,k,node))
    {
        if (k == 0)
        {
            cout<<"KthAnscestor is "<<root->data<<endl;
        }
        k--;
        return true;
    }
    return false;
    
}

int main(int argc, char const *argv[])
{

    // Build the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);    

    TreeNode *target = root->left->right; // Node with value 5
    int k = 2;

    bool result = KthAnscestor(root,k,target);


    return 0;
}