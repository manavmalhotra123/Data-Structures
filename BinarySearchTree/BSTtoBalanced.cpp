#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int value) {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
};

// Function to construct a balanced binary search tree from sorted array
TreeNode* BalancedBinaryTree(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = BalancedBinaryTree(nums, start, mid - 1);
    root->right = BalancedBinaryTree(nums, mid + 1, end);

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

TreeNode* sortedListToBST(vector<int>& nums) {
    return BalancedBinaryTree(nums, 0, nums.size() - 1);
}

int main(int argc, char const* argv[]) {

    // Create the hardcoded binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Perform inorder traversal and store the nodes in a list
    vector<int> nodesList;
    inorderTraversal(root);

    // Construct a balanced binary search tree using the nodes list
    TreeNode* balancedBST = sortedListToBST(nodesList);

    // Print the nodes of the new balanced binary search tree in inorder
    inorderTraversal(balancedBST);

    return 0;
}
