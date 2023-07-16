#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node class for tree nodes
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Struct to store both the node and its corresponding column
struct NodeColumn {
    Node* node;
    int column;
    NodeColumn(Node* node, int column) {
        this->node = node;
        this->column = column;
    }
};

// Function to perform vertical order traversal
void verticalOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    int minColumn = 0, maxColumn = 0;

    // Queue to store nodes and their columns
    queue<NodeColumn> nodeQueue;
    nodeQueue.push(NodeColumn(root, 0));

    // Vector of vectors to store nodes at each column
    vector<vector<int>> columns;

    // Perform BFS traversal
    while (!nodeQueue.empty()) {
        // Get the front node and column from the queue
        NodeColumn curr = nodeQueue.front();
        nodeQueue.pop();

        Node* node = curr.node;
        int column = curr.column;

        // Update the minColumn and maxColumn values
        if (column < minColumn) {
            minColumn = column;
            // Insert an empty vector at the beginning of columns to accommodate the new column
            columns.insert(columns.begin(), vector<int>());
        } else if (column > maxColumn) {
            maxColumn = column;
            // Append an empty vector at the end of columns to accommodate the new column
            columns.push_back(vector<int>());
        }

        // Add the current node to the corresponding column in columns
        columns[column - minColumn].push_back(node->data);

        // Enqueue the left child with column - 1 and right child with column + 1
        if (node->left)
            nodeQueue.push(NodeColumn(node->left, column - 1));

        if (node->right)
            nodeQueue.push(NodeColumn(node->right, column + 1));
    }

    // Print the nodes at each column
    for (const auto& column : columns) {
        for (int i = 0; i < column.size(); ++i) {
            cout << column[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a sample tree
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    // Perform vertical order traversal
    verticalOrderTraversal(root);

    return 0;
}
