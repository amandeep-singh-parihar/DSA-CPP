// 987. Vertical Order Traversal of a Binary Tree
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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, pair<int, int>>> q; // {TreeNode,{col,row}}
    map<int, map<int, multiset<int>>> mp;      // col -> {row :  [x,y,z.....]}
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *&node = p.first;
        int col = p.second.first, row = p.second.second;
        mp[col][row].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {col - 1, row + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {col + 1, row + 1}});
        }
    }
    // visuale representation of the map
    // {
    //     -2: { 2: {4} },
    //     -1: { 1: {2} },
    //      0: { 0: {1}, 2: {5, 6} },
    //      1: { 1: {3} },
    //      2: { 2: {7} }
    // }
    vector<vector<int>> ans;
    for (auto &p : mp)
    {
        vector<int> level;
        for (auto &q : p.second)
        {
            level.insert(level.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(level);
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

    // Calling verticalTraversal function
    vector<vector<int>> result = verticalTraversal(root);

    // Printing the result
    cout << "[";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}