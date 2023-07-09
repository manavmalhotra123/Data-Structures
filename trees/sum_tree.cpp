// convert the tree into sum tree
/*
condition for sum tree: node->data = node->data + sum of left subtree + sum of right subtree
*/
#include <iostream>

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

Node *build()
{
    int data;
    cout << "Enter data for the node (-1 for no node): ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "At the left of node " << root->data << endl;
    root->L = build();

    cout << "At the right of node " << root->data << endl;
    root->R = build();

    return root;
}

int SumTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int LSum = SumTree(root->L);
    int RSum = SumTree(root->R);
    int old_data = root->data;

    root->data = LSum + RSum + root->data;

    return root->data + LSum + RSum;
}

int main()
{
    Node *root = build();
    SumTree(root);
    return 0;
}
