#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

Node *BuildTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    // ab root node bnayo
    Node *root = new Node(data);

    // ab root ke left mai jaayo
    cout << "At left of node " << root->data << endl;
    root->L = BuildTree();

    cout << "At right of node " << root->data << endl;
    root->R = BuildTree();

    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node*temp = Q.front();
        Q.pop();
        cout <<temp->data << " ";
        if (temp->L)
        {
            Q.push(temp->L);
        }
        if (temp->R)
        {
            Q.push(temp->R);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    Node *root = BuildTree();
    LevelOrderTraversal(root);
    return 0;
}