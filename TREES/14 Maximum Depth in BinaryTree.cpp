// 104. Maximum Depth of Binary Tree
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

int maxDepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = maxDepth(root->left);  // first go all the way to left
    int rh = maxDepth(root->right); // second go all the way to right

    return 1 + max(lh, rh); // the height must be 1 + the max from either side (right, left)
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
    cout << maxDepth(root);
    return 0;
}