class Solution {
public:
    Node* insert(Node* root, int key) {
        // If the tree is empty, create a new node and return it as the root.
        if (root == nullptr) {
            return new Node(key);
        }
        
        // Insert into the left subtree if key is less than the current node's value.
        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        // Insert into the right subtree if key is greater than or equal to the current node's value.
        else {
            root->right = insert(root->right, key);
        }
        
        return root;
    }

    // Function to perform an inorder traversal of the BST.
    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
};