
class Solution{
  public:
    
    // Function to get the inorder traversal of the binary tree and store it in arr[]
    void getArr(int arr[], int *index, Node *root)
    {
        if(root == NULL)
            return ;
        
        // recursively traverse the left subtree
        getArr(arr, index, root->left);
        
        // store the data of current node in arr[] and increment the index
        arr[*index] = root->data;
        *index += 1;
        
        // recursively traverse the right subtree
        getArr(arr, index, root->right);
    }
    
    
    // Function to convert the binary tree to BST
    void convert(Node *root, int arr[], int *index)
    {
        if(root == NULL)
            return ;
    
        // recursively convert the left subtree
        convert(root->left, arr, index);
        
        // replace the data of current node with the corresponding arr[] element and increment the index
        root->data = arr[*index];
        *index += 1;
        
        // recursively convert the right subtree
        convert(root->right, arr, index);
    }
    
    // Function to get the total number of nodes in the binary tree
    int totalNodes(Node* root)
    {
        // if the root is NULL, return 0
        if(root == NULL)
            return 0;
        
        // recursively calculate the total number of nodes in the left subtree and right subtree, and add 1 for the current root node
        return (1 + totalNodes(root->left) + totalNodes(root->right));
    }
    
    // Function to convert the binary tree to a binary search tree (BST)
    Node* binaryTreeToBST (Node *root)
    {
        if(root == NULL)
            return NULL ;
        
        // get the total number of nodes in the binary tree
        int n = totalNodes(root);
        
        // create an array of size n+1 to store the inorder traversal of the binary tree
        int *arr = new int[n + 1];
        
        int index = 0;
        
        // get the inorder traversal of the binary tree and store it in arr[]
        getArr(arr, &index, root);
        
        // sort the arr[] in ascending order
        sort(arr, arr + index);
        
        index = 0;
        
        // convert the binary tree to a BST by replacing the data of each node with the corresponding arr[] element
        convert(root, arr, &index);
        
        // return the modified BST
        return root;
    }
};
