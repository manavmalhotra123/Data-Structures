#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* L;
    Node* R;
};

using namespace std;

// Function to perform inorder traversal and find the kth smallest element
int KthSmallestElement(Node* root, int& k) {
    if (root == nullptr) {
        return -1; // If the tree is empty, return a value that represents an invalid node.
    }

    // Step 1: Traverse the left subtree recursively
    int left_val = KthSmallestElement(root->L, k);

    // Step 2: Visit the current node
    if (k == 0) {
        // If k is zero, it means we have already found the kth smallest element.
        return left_val; // Return the left_val which contains the kth smallest element.
    }

    // If k is not zero, decrement k and check if it's zero now.
    k--;

    // Step 3: Traverse the right subtree recursively
    int right_val = KthSmallestElement(root->R, k);

    // If k is zero, it means the kth smallest element is in the right subtree.
    if (k == 0) {
        return root->data; // Return the current node's value as it is the kth smallest element.
    }

    // If k is still not zero, it means the kth smallest element is in the right subtree.
    return right_val;
}

int main() {
    // Create a sample binary search tree
    Node* root = new Node{4, new Node{2, new Node{1, nullptr, nullptr}, new Node{3, nullptr, nullptr}},
                                 new Node{5, nullptr, nullptr}};

    int k = 3; // Find the 3rd smallest element in the BST
    int check = k;
    // Get the kth smallest element
    int result = KthSmallestElement(root, k);

    if (result != -1) {
        cout << "The " << check << "th smallest element is: " << result << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    // Clean up the memory (optional)
    // Remember to implement a proper tree deletion function to avoid memory leaks.

    return 0;
}
