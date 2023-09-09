
class Solution
{
    public:
    // Utility function to find the kth largest element in a binary search tree
    void kthLargestUtil(Node *root, int k, int &c, int &res)
    {
        // Base case: if root is NULL or we have already found k elements
        if (root == NULL || c >= k)
            return;
        
        // Recursively traverse the right subtree
        kthLargestUtil(root->right, k, c, res);
        
        // Increment the count
        c++;
        
        // If we have found the kth largest element, update the result
        if (c == k)
        {
            res = root->data;
            return;
        }
        
        // Recursively traverse the left subtree
        kthLargestUtil(root->left, k, c, res);
    }
    
    // Function to find the kth largest element in a binary search tree
    int kthLargest(Node *root, int k)
    {
        // Initialize count and result variables
        int c = 0;
        int res = -1;
        
        // Call the utility function to find the kth largest element
        kthLargestUtil(root, k, c, res);
        
        // Return the result
        return res;
    }
};