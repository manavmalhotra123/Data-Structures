#include <iostream>

class Node {
public:
    int val;
    Node* right;
    Node* left;

    Node(int val) {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        root = new Node(val);
    }
    else if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* findLeftmostNode(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* inOrderSuccessor(Node* root, Node* x) {
    if (root == nullptr)
        return nullptr;

    // If x is found, the Inorder Successor is in its right subtree (if exists)
    if (x->val == root->val) {
        if (root->right)
            return findLeftmostNode(root->right);
        return nullptr;
    }

    // If x is smaller than the current root, the Inorder Successor is in the left subtree
    if (x->val < root->val) {
        Node* leftSuccessor = inOrderSuccessor(root->left, x);
        return leftSuccessor ? leftSuccessor : root;
    }

    // If x is greater than the current root, the Inorder Successor is in the right subtree
    return inOrderSuccessor(root->right, x);
}

Node* createBST() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 8);
    insert(root, 12);
    insert(root, 18);
    return root;
}

int main(int argc, char const* argv[]) {
    Node* root = createBST();

    // node whose successor needs to be found
    Node* x = root->left->right;

    Node* successor = inOrderSuccessor(root, x);

    if (successor) {
        std::cout << "Inorder Successor of " << x->val << " is " << successor->val << std::endl;
    } else {
        std::cout << "No Inorder Successor found for " << x->val << std::endl;
    }

    return 0;
}
