// 236. Lowest Common Ancestor of a Binary Tree
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

// Brute force
// TC O(N+N)
// SC O(N+N)
bool solve(TreeNode *root, vector<TreeNode *> &res, TreeNode *target)
{
    if (root == NULL)
        return false;

    res.push_back(root);

    if (root == target)
        return true;

    if (solve(root->left, res, target) || solve(root->right, res, target))
    {
        return true;
    }

    res.pop_back();
    return false;
}
TreeNode *_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> resP;
    vector<TreeNode *> resQ;
    solve(root, resP, p);
    solve(root, resQ, q);

    TreeNode *lca = nullptr;

    int size = min(resP.size(), resQ.size());
    for (int i = 0; i < size; ++i)
    {
        if (resP[i] == resQ[i])
        {
            lca = resP[i];
        }
        else
        {
            break;
        }
    }
    return lca;
}

// SAME AS BT
// TC O(N)
// SC ->
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

int main()
{
    // Creating the tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *p = root->left->left;  // Node 4
    TreeNode *q = root->left->right; // Node 5

    TreeNode *lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}