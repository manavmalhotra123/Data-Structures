struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = 1 + max(leftHeight, rightHeight);
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted is found

        // Case 1: Node has no child or only one child
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Case 2: Node has two children
            Node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // Update the height of the current node
    updateHeight(root);

    // Check if the tree is balanced
    int balance = getHeight(root->left) - getHeight(root->right);

    // Left Left Case
    if (balance > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getHeight(root->left->left) < getHeight(root->left->right)) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getHeight(root->right->right) < getHeight(root->right->left)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

