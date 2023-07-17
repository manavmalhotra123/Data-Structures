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
    Node *R;
    Node *L;
    Node(int data)
    {
        this->data = data;
        this->R = nullptr;
        this->L = nullptr;
    }
};

// left nodes print
void PrintLeftNode(Node *node)
{
    // base case
    if (node == nullptr)
    {
        return;
    }
    if (node->L == nullptr && node->R == nullptr)
    {
        return;
    }

    cout << node->data << " ";

    // try to go to left
    if (node->L)
    {
        PrintLeftNode(node->L);
    }
    else
    {
        PrintLeftNode(node->R);
    }
}

// right nodes print
void PrintRightNode(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->L == nullptr && node->R == nullptr)
    {
        // leaf node waala portion
        return;
    }
    // try to go to right
    if (node->R)
    {
        PrintRightNode(node->R);
    }
    else
    {
        PrintRightNode(node->L);
    }
    cout << node->data << " ";
}

// leaf node print
void PrintLeafNodes(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->L == nullptr && node->R == nullptr)
    {
        cout << node->data << " ";
    }
    PrintLeafNodes(node->L);
    PrintLeafNodes(node->R);
}

// Boundary Traversal
void BoundaryTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    // print root
    cout << root->data << " ";

    // Step A : print left
    if (root->L)
        PrintLeftNode(root->L);

    // Step B : print leaf node
    PrintLeafNodes(root);

    // Step C : print right
    if (root->R && root->R != root->L)
        PrintRightNode(root->R);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    // left subtree
    root->L = new Node(20);
    root->L->L = new Node(30);
    root->L->R = new Node(50);
    root->L->R->L = new Node(70);
    root->L->R->L->L = new Node(90);
    root->L->R->L->R = new Node(80);
    root->L->R->R = new Node(60);
    // right subtree
    root->R = new Node(40);
    root->R->R = new Node(100);
    root->R->R->R = new Node(120);
    root->R->R->R->L = new Node(110);
    root->R->R->R->R = new Node(130);

    BoundaryTraversal(root);

    return 0;
}
