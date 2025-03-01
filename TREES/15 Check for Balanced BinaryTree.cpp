// 110. Balanced Binary Tree
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


// Naive Approach 
// T.C O(N*N)
int _maxDepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = _maxDepth(root->left);  // gets the max height in the left subtree
    int rh = _maxDepth(root->right); // gets the max height in the right subtree

    return 1 + max(lh, rh); // calculate the max height of the tree
}

bool _isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = _maxDepth(root->left);  // it gets the left height of the tree
    int rh = _maxDepth(root->right); // it gets the right height of the tree

    if (abs(lh - rh) > 1) // if the left height and right height differ more than 1 it means it is an unbalanced tree
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right); // if reach here it means the root is balanced but doesn't mean every node is balanced as the example is given below in the main so now go for the root's left and root' right recursively
}


// Optimal Approach T.C O(N)
int dfsHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = dfsHeight(root->left);
    if (lh == -1)
    {
        // here when the dfsHeight return from a calling as this is recursion, if the difference is > 1
        // then is return -1 , now the the lh has -1 and anytime it has -1 it means it is unbalanced tree
        // now this finaly return -1 to the isBalanced function
        return -1;
    }

    int rh = dfsHeight(root->right);
    if (rh == -1)
    {
        // here when the dfsHeight return from a calling as this is recursion, if the difference is > 1
        // then is return -1 , now the the rh has -1 and anytime it has -1 it means it is unbalanced tree
        // now this finaly return -1 to the isBalanced function
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(rh, lh);
}
bool isBalanced(node *root)
{
    if (dfsHeight(root) == -1)
    {
        return false;
    }
    return true;
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
    cout << isBalanced(root);

    // /*
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
    // // cout<<isBalanced(root);
    // // cout << dfsHeight(root);

    return 0;
}
