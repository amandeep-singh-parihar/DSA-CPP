// Floor in BST
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int findFloor(TreeNode *root, int key)
{
    if (!root)
        return -1;
    int flr = -1;
    while (root)
    {
        if (root->data <= key)
        {
            flr = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return flr;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    cout << findFloor(root, 19);
    return 0;
}