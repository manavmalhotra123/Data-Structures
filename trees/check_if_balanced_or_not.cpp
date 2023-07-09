// Creating a mirror of two binary trees
/*
    The given tree is balanced if the absolute difference of left and right subtree is less than or equal to 1
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>

class Node
{
public:
    int data;
    Node* R;
    Node* L;
    Node(int data)
    {
        this->data = data;
        this->L = nullptr;
        this->R = nullptr;
    }
};

Node* build()
{
    int data;
    std::cout << "Enter Value: ";
    std::cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node* root = new Node(data);

    std::cout << "At left of node " << root->data << std::endl;
    root->L = build();

    std::cout << "At right of node " << root->data << std::endl;
    root->R = build();

    return root;
}

int height(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int Lheight = height(root->L);
    int Rheight = height(root->R);

    int ans = std::max(Lheight, Rheight) + 1;
    return ans;
}

bool isbalanced(Node* root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool LSub = isbalanced(root->L);
    int Lhigh = height(root->L);
    bool RSub = isbalanced(root->R);
    int Rhigh = height(root->R);

    bool check = LSub && RSub && (std::abs(Lhigh - Rhigh) <= 1);

    return check;
}

int main()
{
    Node* root = build();
    if (isbalanced(root))
    {
        std::cout << "Tree is balanced!!!" << std::endl;
    }
    else
    {
        std::cout << "Tree is not balanced!!!" << std::endl;
    }

    return 0;
}
