#include <iostream>
#include <vector>
#include <algorithm>

// Node class definition
class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Solution class definition
class Solution {
private:
    // Utility function to traverse the tree and get leaf costs
    void dfs(Node* node, int level, std::vector<int> &leaf_levels) {
        if (!node) return;

        // If leaf node
        if (!node->left && !node->right) {
            leaf_levels.push_back(level);
            return;
        }

        // Recursive DFS calls
        if (node->left) dfs(node->left, level + 1, leaf_levels);
        if (node->right) dfs(node->right, level + 1, leaf_levels);
    }

public:
    int getCount(Node *root, int k) {
        std::vector<int> leaf_levels;

        // Get all leaf levels
        dfs(root, 1, leaf_levels);

        // Sort the leaf levels to prioritize cheaper ones
        std::sort(leaf_levels.begin(), leaf_levels.end());

        int count = 0;
        for (int i = 0; i < leaf_levels.size() && k >= leaf_levels[i]; ++i) {
            k -= leaf_levels[i];
            count++;
        }

        return count;
    }
};

int main() {
    // Creating the tree from the first example
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->left = new Node(3);
    root->right->right = new Node(6);
    root->right->left->right = new Node(4);

    Solution sol;
    std::cout << sol.getCount(root, 8) << std::endl;  // Output should be 2

    return 0;
}
