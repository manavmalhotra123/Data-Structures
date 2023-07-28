#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *L;
    Node *R;
    Node(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

Node *LCA(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == p->data)
    {
        return root;
    }
    if (root->data == q->data)
    {
        return root;
    }

    Node *Left = LCA(root->L, p, q);
    Node *Right = LCA(root->R, p, q);

    if (Left == nullptr && Right == nullptr)
    {
        return nullptr;
    }
    if (Left != nullptr && Right != nullptr)
    {
        return root;
    }
    if (Left != nullptr && Right == nullptr)
    {
        return Left;
    }
    if (Left == nullptr && Right != nullptr)
    {
        return Right;
    }

    return nullptr;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(3);
    root->L = new Node(5);
    root->R = new Node(1);
    root->L->L = new Node(6);
    root->L->R = new Node(2);
    root->R->L = new Node(0);
    root->R->R = new Node(8);
    root->L->R->L = new Node(7);
    root->L->R->R = new Node(4);

    Node *p = root->L;
    Node *q = root->R;
    Node *lca = LCA(root, p, q);

    if (lca != nullptr)
    {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    }
    else
    {
        cout << "One or both nodes not found in the tree." << endl;
    }

    return 0;
}