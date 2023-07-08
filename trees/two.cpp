// Creating a tree
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
    // node constructor
    TreeNode(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

TreeNode *buildTree()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    // if data is -1 it means that you don't want to extend the tree
    if (data == -1)
    {
        return NULL;
    }

    // ab kro aage ka kaam
    // Step 1: create a node
    TreeNode *root = new TreeNode(data);
    cout << "Enter data for left node of " << data << endl;
    // Step 2: create a node at left
    root->left = buildTree();
    // Step 3: create a node at right
    cout << "Enter data for right node of " << data << endl;
    root->right = buildTree();

    return root;
}

void ShowTreeUsingLevelOrderTraversal(TreeNode *root)
{

    cout << "Tree using level order traversal: ";

    // initially ek queue li
    queue<TreeNode *> Q;
    // queue mai humne root daal di tree ki
    Q.push(root);

    // till the queue is not empty
    while (!Q.empty())
    {

        // Step 1: take the first element of the queue
        TreeNode *temp = Q.front();
        // Step 2: take out that bloody element
        Q.pop();
        // Step 3: temp mai jo node aaya uske data ko print maaro
        cout << temp->data << " ";
        // Step 4: check for children at left and right if exist then push them to queue
        if (temp->left)

        {
            Q.push(temp->left);
        }
        if (temp->right)
        {
            Q.push(temp->right);
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{

    TreeNode *root = buildTree();
    ShowTreeUsingLevelOrderTraversal(root);
    return 0;
}