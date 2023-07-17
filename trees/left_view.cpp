// left view of the tree 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Node
{
    public:
        int data;
        Node* L;
        Node* R;
        Node(int data)
        {
            this->data = data;
            this->L = nullptr;
            this->R = nullptr;
        }
};

// left view of the tree 
// hr level ka left most node nikaalne ka 
void PrintLeftView(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = Q.front();
            Q.pop();

            if (i == 0)
                cout << curr->data << " ";

            if (curr->L)
                Q.push(curr->L);
            if (curr->R)
                Q.push(curr->R);
        }
    }
}


// Right View
void PrintRightView(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = Q.front();
            Q.pop();

            // Print the rightmost node of each level
            if (i == size - 1)
                cout << curr->data << " ";

            if (curr->L)
                Q.push(curr->L);
            if (curr->R)
                Q.push(curr->R);
        }
    }
}


int main(int argc, char const *argv[])
{

    Node* root = new Node(10);
    // Right subtree
    root->R = new Node(50);
    root->R->R = new Node(70);

    // Left subtree
    root->L = new Node(20);
    root->L->L = new Node(30);
    root->L->R = new Node(40);
    root->L->R->L = new Node(60);
    root->L->R->R = new Node(80);
    root->L->R->R->R = new Node(90);

    // Left View
    PrintLeftView(root);
    cout<<endl;
    // Right View
    PrintRightView(root);
    return 0;
}

