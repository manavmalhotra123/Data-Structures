// Lowest Common ancestor

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
    TreeNode *L;
    TreeNode *R;

    TreeNode(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

TreeNode *build()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(data);

    cout << "currently at left of node " << root->data << endl;
    root->L = build();

    cout << "currently at right of node " << root->data << endl;
    root->R = build();

    return root;
}

void ShowTree(TreeNode *root)
{
    cout << "Tree with level order traversal..." << endl;
    queue<TreeNode *> helper;
    helper.push(root);

    while (!helper.empty())
    {
        TreeNode *printer = helper.front();
        cout << printer->data << " ";
        helper.pop();
        if (printer->L)
        {
            helper.push(printer->L);
        }
        if (printer->R)
        {
            helper.push(printer->R);
        }
    }
}

// lowest ancestor question
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data)
    {
        return root;
    }
    if (root->data == q->data)
    {
        return root;
    }
    
    TreeNode* Left = LCA(root->L, p, q);
    TreeNode* Right = LCA(root->R, p, q);
    
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL && right == NULL)
    {
        return nullptr;
    }
    if (left == nullptr && right != nullptr)
    {
        return nullptr;
    }
    if (Left == nullptr && Right == nullptr)
    {
        return nullptr;
    }
    
    return nullptr;
    
    
    
}

int main(int argc, char const *argv[])
{
    TreeNode *root = build();
    ShowTree(root);
    TreeNode* q = new TreeNode(3);
    TreeNode* p = new TreeNode(4);
    cout<<endl;
    TreeNode* ans = LCA(root,p,q);
    if (ans != nullptr)
    {
        cout<<"Answer is "<<ans->data<<endl;
    }
    else
    {
        cout<<"No lowest ancestor found!!"<<endl;
    }
    
    
    
    return 0;
}