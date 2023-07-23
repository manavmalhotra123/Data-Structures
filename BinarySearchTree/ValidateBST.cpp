#include <iostream>
#include <queue>
#include <climits> // For INT_MIN and INT_MAX

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

Node *InsertIntoBST(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->L = InsertIntoBST(root->L, data);
    }
    else if (data > root->data)
    {
        root->R = InsertIntoBST(root->R, data);
    }

    return root;
}

void TakeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *temp = Q.front();
        cout << temp->data << " ";
        Q.pop();
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

bool solve(Node *root, int lowerBound, int upperBound)
{
    // If the tree is empty, it is still considered a valid BST
    if (root == nullptr)
    {
        return true;
    }

    // Check if the current node's data violates the BST property
    if (root->data <= lowerBound || root->data >= upperBound)
    {
        return false;
    }

    // Recursively check the left and right subtrees
    bool LeftAnswer = solve(root->L, lowerBound, root->data);
    bool RightAnswer = solve(root->R, root->data, upperBound);

    return LeftAnswer && RightAnswer;
}

bool isValidate(Node* root)
{
    // Use the minimum and maximum possible values for 'int'
    int lowerBound = INT_MIN;
    int upperBound = INT_MAX;
    bool ans = solve(root, lowerBound, upperBound);

    return ans;
}

int main()
{
    cout << "Enter the values of nodes of BST (Enter -1 to stop)..." << endl;
    Node *root = nullptr;
    TakeInput(root);
    
    cout << "Level Order Traversal: ";
    LevelOrderTraversal(root);
    cout << endl;
    
    if (isValidate(root))
    {
        cout << "The given tree is a valid Binary Search Tree (BST)." << endl;
    }
    else
    {
        cout << "The given tree is NOT a valid Binary Search Tree (BST)." << endl;
    }

    return 0;
}
