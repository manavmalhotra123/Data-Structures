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

// Function to insert a new node into the BST
Node* InsertIntoBST(Node* root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }
    else if (root->data > data)
    {
        root->L = InsertIntoBST(root->L, data);
    }
    else
    {
        root->R = InsertIntoBST(root->R, data);
    }

    return root;
}

// Function to delete a node from the BST
Node* DeleteNodeFromBST(Node* root, int data)
{
    if (root == nullptr)
    {
        // The node to delete is not found, do nothing
        return root;
    }
    else if (data < root->data)
    {
        // The node to delete is in the left subtree
        root->L = DeleteNodeFromBST(root->L, data);
    }
    else if (data > root->data)
    {
        // The node to delete is in the right subtree
        root->R = DeleteNodeFromBST(root->R, data);
    }
    else
    {
        // Node to delete is found

        // Case 1: Node with one child or no child
        if (root->L == nullptr)
        {
            Node* temp = root->R;
            delete root;
            return temp;
        }
        else if (root->R == nullptr)
        {
            Node* temp = root->L;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Find the inorder successor (smallest node in the right subtree)
        Node* temp = root->R;
        while (temp->L != nullptr)
        {
            temp = temp->L;
        }

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor node
        root->R = DeleteNodeFromBST(root->R, temp->data);
    }

    return root;
}

void TakeInput(Node*& root){ // Pass by reference using '&' to modify the original pointer
    int data;
    cin >> data;
    while (data != -1) // Keep taking input until -1 is encountered
    {
        root = InsertIntoBST(root,data);
        cin >> data;
    }
}

int height(Node* root){
    if (root == NULL) 
    {
        return -1;
    }
    int hieght = 0;

    int LHeight = height(root->L);
    int RHeight = height(root->R);

    return max(RHeight, LHeight) + 1;
}

// validating the BST

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
    int lowerBound = INT16_MAX;
    int upperBound = INT16_MIN;
    bool ans = solve(root, lowerBound, upperBound);

    return ans;
}
// ---------------- validating done --------------


int main(int argc, char const *argv[])
{
    cout<<"Enter the values of the tree nodes (Enter -1 to stop..)"<<endl;
    Node* root = nullptr;
    TakeInput(root);

    // Example of how to delete a node
    int value_to_delete;
    cout << "Enter the value of the node to delete: ";
    cin >> value_to_delete;

    root = DeleteNodeFromBST(root, value_to_delete);

    // Display the BST after deletion (You can implement a display function for this purpose)
    // ...

    return 0;
}
