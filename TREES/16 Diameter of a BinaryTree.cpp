// 543. Diameter of Binary Tree
#include <bits/stdc++.h>
using namespace std;
// revision 2
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

// T.C O(N)
int solve(node *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = solve(root->left, diameter);
    int rh = solve(root->right, diameter);

    diameter = max(diameter, lh + rh); // At this point it is calculated that is this the max Diameter

    return 1 + max(lh, rh); // return the height to the upper node
}

int diameterOfBinaryTree(node *root)
{

    int diameter = INT_MIN;

    solve(root, diameter);

    return diameter;
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
    cout << diameterOfBinaryTree(root);

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
    // cout << diameterOfBinaryTree(root);
    return 0;
}