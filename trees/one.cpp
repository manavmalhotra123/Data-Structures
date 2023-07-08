// TREE - non linear data structure
/*
It contains the nodes
Binary Tree: number of children of one node can be 0,1 or 2
N-ery Tree: n number of children of single node

Tree Terms;
1.Node
2.Root
3.Child
4.Parent
5.Ancestor
6.Sibling
7.Leaf
8.Descendant
*/

// Binary Tree
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;





class BinaryNode
{
private:
    int data;
    BinaryNode *left;
    BinaryNode *right;
public:
    BinaryNode(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    BinaryNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}