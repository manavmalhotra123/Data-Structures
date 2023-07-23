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

Node* InsertIntoBST(Node* root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }
    else if (root->data > data){
        root->L = InsertIntoBST(root->L, data);
    }
    else
    {
        root->R = InsertIntoBST(root->R, data);
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

int main(int argc, char const *argv[])
{
    cout<<"Enter the values of the tree nodes (Enter -1 to stop..)"<<endl;
    Node* root = nullptr;
    TakeInput(root);
    return 0;
}
