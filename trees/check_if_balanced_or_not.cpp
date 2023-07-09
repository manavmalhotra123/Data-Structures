// Creating a mirror of two binary trees
/*

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *R;
    Node *L;
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
    cout << "Enter Value: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "At left of node " << root->data << endl;
    root->L = build();

    cout << "At right of node " << root->data << endl;
    root->R = build();

    return root;
}

// check if the binary tree is balanced or not
bool isbalanced(Node *root)
{

}

int main(int argc, char const *argv[])
{
    Node *root = build();
    if (isbalanced(root))
    {
        cout << "Trees is balanced!!!" << endl;
    }
    else
    {
        cout << "Tree is not balanced!!!" << endl;
    }

    return 0;
}