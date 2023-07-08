// TREE - non linear data structure
/*
It contains the nodes
Binary Tree: number of children of one node can be 0,1 or 2
N-ery Tree: n number of children of single node
Skew Tree: one sides tree
            10                         
        20 
    30
40
        OR
10  
    20 
        30 
            40

Tree Terms;
1.Node
2.Root -- topmost node
3.Child -- niche waala
4.Parent -- upr waala ek ke 
5.Ancestor -- do level upr
6.Sibling -- sath ke level waala
7.Leaf -- aakhri waaris family ka 
8.Descendant
*/

/*
Travesal techinque of the trees 
1.Level order 
2.Pre-order
3.Post-order
*/

/*
                      10 
                20         30
            40     50   60      70

Level order traverse - 10  20  30  40   50   60   70 
*/


/*
Build tree method:
1. Level order traversal 
2. Recursive traversal  - create a root node 
                        - root ka left part recursion solve krega 
                        - root ka right part recursion solve kreg 
3. 
*/

// Binary Tree
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class NryTree
{
private:
    int data;
    // for n nodes 
    vector<NryTree*> child;
};


class BinaryNode
{
private:
    int data;
    BinaryNode *left;
    BinaryNode *right;
};


int main(int argc, char const *argv[])
{

    return 0;
}
