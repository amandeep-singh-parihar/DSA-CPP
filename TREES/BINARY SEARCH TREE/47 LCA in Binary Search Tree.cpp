// 235. Lowest Common Ancestor of a Binary Search Tree
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
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// SAME AS BT
// TC O(N)
// SC
// O(H), where H is the height of the tree.
// O(log N) for a balanced tree (recursion depth = tree height).
// O(N) for a skewed tree (recursion depth = number of nodes).
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

// TC O(H)
// SC
// O(H), where H is the height of the tree.
// O(log N) for a balanced tree (recursion depth = tree height).
// O(N) for a skewed tree (recursion depth = number of nodes).
TreeNode *_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;
    if (root->data < p->data && root->data < q->data)
    {
        return _lowestCommonAncestor(root->right, p, q);
    }
    else if (root->data > p->data && root->data > q->data)
    {
        return _lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return root;
    }
}

int main()
{

    return 0;
}