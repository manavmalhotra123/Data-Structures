// Building tree from postorder and inorder of the tree 


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *L;
    Node *R;
    Node(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

int find(int arr[], int size, int element)
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

Node *BuildFromPostOrder(int InOrder[], int PostOrder[], int Size, int &PostOrderIndex, int InorderStartIndex, int InorderEndIndex)
{
    // Base Case:
    // when whole array is traversed
    if (PostOrderIndex < 0 || InorderStartIndex > InorderEndIndex)
    {
        return nullptr;
    }

    // select the root element
    int element = PostOrder[PostOrderIndex];
    PostOrderIndex--;


    // create  new node to start the tree
    Node *root = new Node(element);

    // find the position of the root element so that the division
    // of subtrees can be done 
    int position = find(InOrder,Size,element);

    // turn for doing the same thing for left as well as right now 
    root->R = BuildFromPostOrder(InOrder,PostOrder,Size,PostOrderIndex,position + 1, InorderEndIndex);
    root->L = BuildFromPostOrder(InOrder,PostOrder,Size,PostOrderIndex,InorderStartIndex,position - 1);

    return root;
}



void LevelOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node* temp = Q.front();
        cout << temp->data << " ";
        Q.pop();

        if (temp->L)
            Q.push(temp->L);
        if (temp->R)
            Q.push(temp->R);
    }
}


int main(int argc, char const *argv[])
{
    int inorder[] = {3, 1, 4, 5, 2};
    int postorder[] = {3, 4, 1, 2, 5};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    int postorderIndex = size - 1;
    Node *root = BuildFromPostOrder(inorder, postorder, size, postorderIndex, 0, size - 1);

    LevelOrderTraversal(root);
    return 0;
}