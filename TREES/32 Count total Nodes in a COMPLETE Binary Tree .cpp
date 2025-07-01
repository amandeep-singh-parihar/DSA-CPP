// 222. Count Complete Tree Nodes
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

// TC O(N)
// SC O(N)
int dfsCount(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int l = dfsCount(root->left);
    int r = dfsCount(root->right);

    return l + r + 1;
}
int countNodes(TreeNode *root)
{
    return dfsCount(root);
}

// TC O(log^2 N)
// SC O(logN)
// Logic -> if at any node the height of left subtree is equal to right subtree we calculate the nodes
// using this formula of 2^h - 1
// if at any node if the lh and rh is not equal we go down and calculate there
int leftHeight(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        ++height;
        node = node->left;
    }
    return height;
}

int rightHeight(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        ++height;
        node = node->right;
    }
    return height;
}

int _countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + _countNodes(root->left) + _countNodes(root->right);
}

int main()
{
    // Creating a simple binary tree for testing
    //      1
    //     / \
    //    2   3
    //   / \  /
    //  4  5 6

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Count the number of nodes in the binary tree
    int nodeCount = countNodes(root);

    cout << "Number of nodes in the tree: " << nodeCount << endl;
    return 0;
}