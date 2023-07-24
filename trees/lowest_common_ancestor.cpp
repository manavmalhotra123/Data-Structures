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
TreeNode* lowest_ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base Case:
    if (root == nullptr)
    {
        return nullptr;
    }

    // Check for p and q
    if (root->data == p->data)
    {
        return root;
    }
    if (root->data == q->data)
    {
        return root;
    }

    // if dono upar waale case s ma i se kuch nhi mila to left ka answer nikaal le
    TreeNode *Left = lowest_ancestor(root->L, p, q);
    // right ka answer nikaal le
    TreeNode *Right = lowest_ancestor(root->R, p, q);

    if (Left == nullptr && Right == nullptr)
    {
        return nullptr;
    }
    if (Left != nullptr &&  Right == nullptr)
    {
        return Left;
    }
    if (Left == nullptr && Right != nullptr)
    {
        return Right;
    }
    if (Left != nullptr && Right != nullptr)
    {
        return root;
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
    TreeNode* ans = lowest_ancestor(root,p,q);
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