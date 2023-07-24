// Left View of the Binary Search Tree 

class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        queue<Node *> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            int levelSize = nodesQueue.size();

            for (int i = 0; i < levelSize; ++i)
            {
                Node *node = nodesQueue.front();
                nodesQueue.pop();

                // Keep track of the rightmost node at each level
                if (i == levelSize - 1)
                    result.push_back(node->data);

                if (node->left)
                    nodesQueue.push(node->left);

                if (node->right)
                    nodesQueue.push(node->right);
            }
        }

        return result;
    }
};
