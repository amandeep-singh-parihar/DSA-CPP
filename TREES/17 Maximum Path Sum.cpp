// 124. Binary Tree Maximum Path Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// TC O(N)
// SC O(N)
int solve(node *root, int &pathSum)
{
    if (root == NULL)
        return 0;

    int ls = max(0, solve(root->left, pathSum));
    int rs = max(0, solve(root->right, pathSum));

    pathSum = max(pathSum, root->data + ls + rs);

    return root->data + max(ls, rs);
}

int maxPathSum(node *root)
{
    int pathSum = INT_MIN;
    solve(root, pathSum);
    return pathSum;
}

int main()
{
    // Creating the tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    cout << maxPathSum(root);
    //    Constructing the following tree:
    //               1
    //            /    \
    //           2      3
    //          / \    / \
    //         4   5  19  6
    //        / \     /    \
    //       6   7   11     10
    //          / \
    //         21  8
    //        /     \
    //       23     40
    // */
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(19);
    // root->right->right = new node(6);
    // root->left->left->left = new node(6);
    // root->left->left->right = new node(7);
    // root->right->right->left = new node(11);
    // root->right->right->right = new node(10);
    // root->left->left->right->left = new node(21);
    // root->left->left->right->right = new node(8);
    // root->left->left->right->left->left = new node(23);
    // root->left->left->right->right->right = new node(40);
    return 0;
}