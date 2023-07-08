#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    // constructor to make the node
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* BuildTree()
{
    int data;
    cout << "Enter Data: ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(data);


    cout << "Currently at node " << root->data <<"choose for left "<< endl;
    root->left = BuildTree();
    


    cout << "Currently at node " << root->data <<" choose for right "<< endl;
    root->right = BuildTree();


    return root;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = BuildTree();
    return 0;
}