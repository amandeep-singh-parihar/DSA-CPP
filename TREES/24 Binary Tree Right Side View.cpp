// 199. Binary Tree Right Side View
// Binary Tree Left Side View
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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode *, int>> q; // {node,row}
    map<int, int> mp;               // row -> val
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int row = it.second;
        mp[row] = node->data; // no need of checking as we are pushing left first and then right
        // if there is any node at the same row level(rightmost) then it get pushed it later (overwrite)
        if (node->left)
        {
            q.push({node->left, row + 1});
        }
        if (node->right)
        {
            q.push({node->right, row + 1});
        }
    }
    for (auto &it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> leftSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode *, int>> q; // {node,row}
    map<int, int> mp;               // row -> val
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int row = it.second;
        mp[row] = node->data;
        if (node->right)
        {
            q.push({node->right, row + 1});
        }
        if (node->left)
        {
            q.push({node->left, row + 1});
        }
    }
    for (auto &it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

// vector<int> leftSideView(TreeNode *root)
// {
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     queue<pair<TreeNode *, int>> q; // {node, row}
//     map<int, int> mp;               // row -> val
//     q.push({root, 0});
//     while (!q.empty())
//     {
//         auto it = q.front();
//         q.pop();
//         TreeNode *node = it.first;
//         int row = it.second;
//         // Insert only if the level is not already in the map
//         if (mp.find(row) == mp.end())
//         {
//             mp[row] = node->data;
//         }
//         // Push left child first
//         if (node->left)
//         {
//             q.push({node->left, row + 1});
//         }
//         if (node->right)
//         {
//             q.push({node->right, row + 1});
//         }
//     }
//     for (auto &it : mp)
//     {
//         ans.push_back(it.second);
//     }
//     return ans;
// }

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

    //     1
    //     / \
    //    2   3
    //     \    \
    //      5    4

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(5);
    // root->right->right = new TreeNode(4);
    // Calling getTopView function
    vector<int> topView = rightSideView(root);

    // vector<int> topView = leftSideView(root);

    // Printing the top view
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}