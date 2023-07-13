#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

TreeNode *build()
{
    int data;
    cout << "Enter the value: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(data);

    cout << "At the left of node " << root->data << endl;
    root->L = build();

    cout << "At the right of node " << root->data << endl;
    root->R = build();

    return root;
}

void LevelOrderTraversal(TreeNode *root)
{
    cout << "Tree: ";
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> helper;
    helper.push(root);
    TreeNode *temp;

    while (!helper.empty())
    {
        temp = helper.front();
        helper.pop();
        cout << temp->data << " ";

        if (temp->L)
        {
            helper.push(temp->L);
        }
        if (temp->R)
        {
            helper.push(temp->R);
        }
    }
    cout << endl;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> answer;
    vector<int> temp;
    solve(root, 0, targetSum, answer, temp);
    return answer;
}

void solve(TreeNode *root, int currentSum, int targetSum, vector<vector<int>> &answer, vector<int> temp)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->L == nullptr && root->R == nullptr)
    {
        if (currentSum + root->data == targetSum)
        {
            temp.push_back(root->data);
            answer.push_back(temp);
        }
        return;
    }

    temp.push_back(root->data);
    currentSum += root->data;

    solve(root->L, currentSum, targetSum, answer, temp);
    solve(root->R, currentSum, targetSum, answer, temp);
}

int main()
{
    TreeNode *root = build();
    LevelOrderTraversal(root);

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<vector<int>> paths = pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const auto &path : paths)
    {
        for (const auto &node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
