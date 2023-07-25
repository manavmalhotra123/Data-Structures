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

vector<int> SpiralTraversal(Node*root)
{
    // to store the final results 
    vector<int> spiral;

    // Queue to maintain the levels 
    queue<Node*> Q;

    // bool to keep the check from right or from left 
    bool LeftToRight = true; // as first level is from left always

    // first element ko push krdiya queue mai 
    Q.push(root);
    
    while (!Q.empty())
    {
        int number_of_nodes = Q.size();

        for (int i = 0; i < number_of_nodes; i++)
        {
            Node* temp = Q.front();
            Q.pop();

            if (LeftToRight) // jab left to right jaana ho 
            {
                spiral.push_back(temp->data);
            }
            else  // right to left jaana ho 
            {
                spiral.insert(spiral.begin(), temp->data); // value adding at the start of the queue
            }
            if (temp->L)
            {
                Q.push(temp->L);
            }
            if (temp->R)
            {
                Q.push(temp->R);
            }
            // side change krdi 
            LeftToRight = !LeftToRight;
        }
    }
    return spiral;
}

int main(int argc, char const *argv[])
{
    Node *root = BuildTree();
    LevelOrderTraversal(root);
    return 0;
}