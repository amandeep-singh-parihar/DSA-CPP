// 700. Search in a Binary Search Tree
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

int findMin(TreeNode *root)
{
    if (!root)
        return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findMax(TreeNode *root)
{
    if (!root)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
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
    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
    return 0;
}