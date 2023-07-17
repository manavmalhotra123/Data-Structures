#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node* R;
    Node* L;

    Node(int data) {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

Node* InsertIntoBST(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    }
    else if (data < root->data) {
        root->L = InsertIntoBST(root->L, data);
    }
    else {
        root->R = InsertIntoBST(root->R, data);
    }
    return root;
}

void TakeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node* root) {
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        if (temp == nullptr) {
            cout << endl;
        }
        else {
            cout << temp->data << " ";
            if (temp->L) {
                Q.push(temp->L);
            }
            if (temp->R) {
                Q.push(temp->R);
            }
        }
    }
}

int main() {
    Node* root = nullptr;
    cout << "Enter the values of the nodes you want (Enter -1 to stop): ";
    TakeInput(root);
    LevelOrderTraversal(root);
    return 0;
}
