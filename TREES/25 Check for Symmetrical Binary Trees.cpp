// 101. Symmetric Tree
#include <bits/stdc++.h>
using namespace std;
// revision 1
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isSymmetricHelper(TreeNode *l, TreeNode *r)
{
    if (l == NULL || r == NULL)
    {
        return l == r;
    }
    if (l->data != r->data)
        return false;

    return isSymmetricHelper(l->left, r->right) && isSymmetricHelper(l->right, r->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || isSymmetricHelper(root->left, root->right);
}

int main()
{
    // Creating the tree structure from the image:
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    4   5 5   4

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout << isSymmetric(root);

    return 0;
}