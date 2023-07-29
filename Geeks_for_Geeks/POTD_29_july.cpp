#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* findInorderPredecessor(Node* current) {
    Node* predecessor = current->left;
    while (predecessor->right != nullptr && predecessor->right != current) {
        predecessor = predecessor->right;
    }
    return predecessor;
}

float findMedian(Node* root) {
    if (root == nullptr)
        return -1;

    Node* current = root;
    Node* prev = nullptr;

    int count = 0;
    int size = 0;
    float median = 0;

    // Traverse the BST in inorder to find the median
    while (current != nullptr) {
        if (current->left == nullptr) {
            // Process the current node (inorder)
            size++;
            if (size % 2 == 0) {
                // If the size is even, we need to find two middle elements
                if (count == size / 2 - 1 || count == size / 2) {
                    if (count == size / 2 - 1)
                        median += current->data;
                    else
                        median += current->data;
                    break;
                }
            } else {
                // If the size is odd, we need to find the middle element
                if (count == size / 2) {
                    median = current->data;
                    break;
                }
            }

            count++;
            prev = current;
            current = current->right;
        } else {
            // Find the inorder predecessor (leftmost node in the right subtree)
            Node* predecessor = findInorderPredecessor(current);

            if (predecessor->right == nullptr) {
                // Set the threaded link
                predecessor->right = current;
                current = current->left;
            } else {
                // Restore the threaded link
                predecessor->right = nullptr;

                // Process the current node (inorder)
                size++;
                if (size % 2 == 0) {
                    // If the size is even, we need to find two middle elements
                    if (count == size / 2 - 1 || count == size / 2) {
                        if (count == size / 2 - 1)
                            median += current->data;
                        else
                            median += current->data;
                        break;
                    }
                } else {
                    // If the size is odd, we need to find the middle element
                    if (count == size / 2) {
                        median = current->data;
                        break;
                    }
                }

                count++;
                prev = current;
                current = current->right;
            }
        }
    }

    // Calculate the final median value
    if (size % 2 == 0)
        return median / 2.0;
    else
        return median;
}

int main() {
    // Example usage:
    // Constructing a sample Binary Search Tree:
    //        5
    //       / \
    //      3   7
    //     / \ / \
    //    2  4 6  8

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    float medianValue = findMedian(root);

    // Displaying the median value
    std::cout << "Median value of the BST: " << medianValue << std::endl;

    // Clean up the dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left; 
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
