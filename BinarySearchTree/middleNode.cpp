#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* L;
    Node* R;
    Node(int data) {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

void InorderTraversal(Node* root, std::vector<int>& Inorder) {
    if (root == nullptr) {
        return;
    }

    InorderTraversal(root->L, Inorder);
    Inorder.push_back(root->data);
    InorderTraversal(root->R, Inorder);
}

int MiddleElement(Node* root, std::vector<int>& Inorder) {
    int size = Inorder.size();
    int mid = size / 2;

    return Inorder[mid];
}

int main() {

    Node* root = new Node(4);
    root->L = new Node(2);
    root->R = new Node(5);
    root->L->L = new Node(1);
    root->L->R = new Node(3);

    std::vector<int> Inorder;
    InorderTraversal(root, Inorder);
    int middleElement = MiddleElement(root, Inorder);
    std::cout << "Middle element: " << middleElement << std::endl; // Output: Middle element: 3

    // Don't forget to free the allocated memory
    delete root->L->R;
    delete root->L->L;
    delete root->R;
    delete root->L;
    delete root;

    return 0;
}
