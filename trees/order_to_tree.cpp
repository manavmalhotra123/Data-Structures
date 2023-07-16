// create a tree from indorder and pre-order

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

/*
            TREE
             5
            / \
           1   2
          / \
         3  4

         INORDER: LNR : 3 1 4 5 2
         PREORDER: NLR : 5 1 3 4 2


         Preorder ki sbse pehli value tumhaari major root hogi tree ki
                it means that 5 is the major root.

                     5

        now considering the preorder we can say that 3 1 4 lie in left subtree
        and 2 lie in right subtree

                     5
                    / \
              (3 1 4)  2

        ab dekh kitne element bilkul done ho gye hai - 5,2
        ab ek cheez dekh preorder mai tere pass next element konsa hai
        and it is 1 so it is the root of left subtree
        aur jab inorder mai dekhega toh uske right left wale subtree mai daalde

             5
            / \
           1   2
          / \
         3  4

*/

class TreeNode
{
public:
    int data;
    TreeNode *L;
    TreeNode *R;
    TreeNode(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

// searching ko alg se hangle krle baad mai BT hogi ni to 
int find(int element, int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; 
        }
        
    }
    return -1;
}

// build tree from inorder and traversal 
TreeNode* BuildFromTraversal(int inorder[], int preorder[],int size, int &preorderindex,int inorderstartindex,int inorderendindex)
{
    // base case 
    // basically jb humaara array traversal khtm ho jayega 
    if(preorderindex >= size || inorderstartindex > inorderendindex)
    {
        return nullptr;
    }

    // Step 1: root node create krna and uske liye need to find the data 
    int element = preorder[preorderindex];
    preorderindex++;

    // ab is element se ek root node bnaado 
    TreeNode* root = new TreeNode(element);  // root node bna di ab yha pr 

    // step 2: left part solve krna ab iska or right part solve krna 
    // for that we need to define left and right sub tree fr unko alg alg recursion ko pkda denge krne ke liye 

    // search krna hai but uska alg function bnane ka nhi to BT hogi 
    int position = find(element,inorder,size);

    // left ke liye solve krle bhai 
    root->L = BuildFromTraversal(inorder,preorder,size,preorderindex,inorderstartindex,position-1);
    //  right ke liye solve krle bhai
    root->R = BuildFromTraversal(inorder,preorder,size,preorderindex,position+1,inorderendindex);

    return root;
}


void LevelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        TreeNode* temp = Q.front();
        cout<<temp->data<<" ";
        Q.pop();
        if (temp->L)
        {
            Q.push(temp->L);
        }
        if (temp->R)
        {
            Q.push(temp->R);
        }   
    }
}


int main(int argc, char const *argv[])
{
        int inorder[] = {3, 1, 4, 5, 2};
    int preorder[] = {5, 1, 3, 4, 2};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    int preorderIndex = 0;
    TreeNode *root = BuildFromTraversal(inorder, preorder, size, preorderIndex, 0, size - 1);


    LevelOrderTraversal(root);
}