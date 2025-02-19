// 662. Maximum Width of Binary Tree
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
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
#define ll long long
int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, ll>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        ll mmin = q.front().second;
        int last, first;
        for (int i = 0; i < size; ++i)
        {
            ll curr_id = q.front().second - mmin;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;
            if (node->left)
            {
                q.push({node->left, curr_id * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, curr_id * 2 + 2});
            }
        }
        ans = max(ans, (int)(last - first + 1));
    }
    return ans;
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