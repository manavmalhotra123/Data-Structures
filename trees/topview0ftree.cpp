// Top View of the tree

// horizontal distance se hoga yeh question
/*
root ko origin maan lo aur aage ko +1 aur piche ko -1
isme jo pehle pehle are hai upr upr unko print krdo

horizontal distance aur node ko store krne 
ke liye maps use krenge
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*
Tree example:

      10
     /  \
    20  50
   / \   \
  30 40  90
    / \  / \
   60 70 80 100

Top View : jo element upr se dekhne pr dikhe bs baaki saare chod do
Top View: 30 20 10 50 90 100
*/

class Node
{
public:
    int data;
    Node *R;
    Node *L;
    Node(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

void LevelOrder(Node *root)
{
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *temp = Q.front();
        cout << temp->data << " ";
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


// TopView nikaalte hai ab 
void PrintTopView(Node* root)
{
    //Base Case 
    if (root == nullptr)
    {
        return;
    }
    
    // map to keep the record of 
    // node data and it's horzontal distance
    map<int,int> topNode;

    // level order traversal krte ab 
    // storing the pair of the node data and 
    // the horzontal distance
    queue< pair<Node*,int>> Q;

    Q.push(make_pair(root,0));

    while (!Q.empty())
    {
        // Pair of node and distance
        pair<Node*,int> temp = Q.front();
        // front pair ko bhar nikaal do 
        Q.pop();

        // Node aur distance ko alag krdo 
        Node* tempNode = temp.first;
        int distance = temp.second;

        // store krni hai ya nhi ab yeh dekhna hai 
        // mtlb ek distance ki ek hi value uthaani hai
        if (topNode.find(distance) == topNode.end())
        {
            topNode[distance] = tempNode->data;    
        }

        // left mai check kro 
        if (tempNode->L)
        {
            Q.push(make_pair(tempNode->L,distance-1));
        }
        if (tempNode->R)
        {
            Q.push(make_pair(tempNode->R,distance+1));
        }
    }

    cout<<"Top View :";
    for(auto i:topNode){
        cout<<i.second<<" ";
    }
    
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);

    // left subtree
    root->L = new Node(20);
    root->L->L = new Node(30);
    root->L->R = new Node(40);
    root->L->R->L = new Node(60);
    root->L->R->R = new Node(70);

    // right subtree
    root->R = new Node(50);
    root->R->R = new Node(90);
    root->R->R->R = new Node(100);
    root->R->R->L = new Node(80);


    cout<<"Tree: ";
    LevelOrder(root);
    cout<<endl;

    PrintTopView(root);
    

    return 0;
}