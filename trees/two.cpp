// Creating a tree 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TreeNode
{
        public:    
            int data;
            TreeNode* left;
            TreeNode* right;
            // node constructor
            TreeNode(int data)
            {
                this->data = data;
                right = NULL;
                left = NULL;
            }
};


TreeNode* buildTree(){
    int data;
    cout<<"Enter the data : ";
    cin >> data;

    // if data is -1 it means that you don't want to extend the tree 
    if (data == -1)
    {
        return NULL;
    }

    // ab kro aage ka kaam 
    // Step 1: create a node 
    TreeNode* root = new TreeNode(data);
    cout<<"Enter data for left node of "<<data<<endl;
    // Step 2: create a node at left
    root->left = buildTree();
    // Step 3: create a node at right
    cout<<"Enter data for right node of "<<data<<endl;
    root->right = buildTree();

    return root;
}




int main(int argc, char const *argv[])
{
   
    TreeNode* root = buildTree();
    
    return 0;
}