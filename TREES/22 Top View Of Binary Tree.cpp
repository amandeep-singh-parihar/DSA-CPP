// Top View Of Binary Tree
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

vector<int> getTopView(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q; // {node,column}
    map<int, int> mp;               // col -> data
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int col = it.second;
        if (mp.find(col) == mp.end()) // if the col is not already in the map
        {
            mp[col] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, col - 1});
        }
        if (node->right)
        {
            q.push({node->right, col + 1});
        }
    }
    vector<int> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    // Creating the tree structure from the image:
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

    // Calling getTopView function
    vector<int> topView = getTopView(root);

    // Printing the top view
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}