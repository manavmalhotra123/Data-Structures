// Check if two trees are identical or not.

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

Node* build()
{
    int data;
    cout << "Enter Value: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node* root = new Node(data);

    cout<<"At left of node "<<root->data << endl;
    root->L = build();

    cout<<"At right of node "<<root->data << endl;
    root->R = build();

    return root;
}

// check function - logic used recursion 
bool check(Node* root_1, Node* root_2){
    // if both of them are null at same time then the nodes are equal
    if (root_1 == nullptr && root_2 == nullptr)
    {
        return true;
    }
    // if any of them is not null or opposite to other then the nodes are not equal
    else if((root_1 == nullptr && root_2 != nullptr) || (root_1 != nullptr && root_2 == nullptr)||(root_1->data != root_2->data)){
        return false;
    }
    
    // check for left subtree nodes of the trees
    bool Lcheck = check(root_1->L, root_2->L);
    // check for right subtree nodes of the trees
    bool Rcheck = check(root_1->R,root_2->R);

    // combine them if both of the sides are equal then they are identical
    return (Lcheck && Rcheck);
}

int main(int argc, char const *argv[])
{
    Node* root_1 = build(); // tree 1
    Node* root_2 = build(); // tree 2

    // check and tell 
    if (check(root_1,root_2))
    {
        cout<<"The trees are identical"<<endl;
    }
    else
    {
        cout<<"The trees are not identical"<<endl;
    }
    
    
    return 0;
}