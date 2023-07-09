// Diameter of the binary tree 

#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node *R;
    Node *L;
    Node(int data) {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

Node *build() {
    int data;
    cin >> data;
    if (data == -1) {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "At left of node " << root->data << endl;
    root->L = build();

    cout << "At right of node " << root->data << endl;
    root->R = build();

    return root;
}

// Finding the diameter of the tree
// approach used - the diameter can be in only the left subtree, only the right subtree, or it can pass through the root
int Diameter(Node *root) {
    // Base Case: if the node is null, return 0 as the tree is empty
    if (root == nullptr) {
        return 0;
    }

    // finding the height of the left subtree
    int Lheight = Diameter(root->L);
    // finding the height of the right subtree
    int Rheight = Diameter(root->R);
    // calculate the length of the longest path that passes through the root
    int throughRoot = Lheight + Rheight + 1;

    // calculate the maximum of the three cases: left subtree, right subtree, or through the root
    int diameter = max({Lheight, Rheight, throughRoot});

    return diameter;
}

int main(int argc, char const *argv[]) {
    Node *root = build();
    int treeDiameter = Diameter(root);
    cout << "Diameter of the tree: " << treeDiameter << endl;

    return 0;
}
