// 662. Maximum Width of Binary Tree
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

// TC O(N) -> level order traversal
// SC O(N) -> using a queue
#define ll long long
int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int maxWidth = 0;
    queue<pair<TreeNode *, ll>> q; // {root,index}
    q.push({root, 0});
    while (!q.empty()) // till the q is not empty
    {
        int size = q.size();           // get the size as I want to traverse the whole level
        ll minimum = q.front().second; // take the minimum as the second of the front (to make the current index 0)
        int last, first;               // create first and last to get the maxWidth
        for (int i = 0; i < size; ++i)
        {
            ll index = q.front().second - minimum;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0) // it means I am at the first node
                first = index;
            if (i == size - 1) // it means I am at the last node
                last = index;
            if (node->left) // if there exists node's left
            {
                q.push({node->left, index * 2 + 1});
            }
            if (node->right) // if there exists node's right
            {
                q.push({node->right, index * 2 + 2});
            }
        }
        maxWidth = max(maxWidth, (int)(last - first + 1)); // calculate the maxWidth
    }
    return maxWidth;
}

int main()
{
    // Creating the binary tree:
    //         1
    //       /   \
    //      3     2
    //     / \     \
    //    5   3     9

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "Maximum width of binary tree: " << widthOfBinaryTree(root) << endl;
    return 0;
}