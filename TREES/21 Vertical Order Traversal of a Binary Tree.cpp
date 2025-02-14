// 987. Vertical Order Traversal of a Binary Tree
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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, pair<int, int>>> q; // {TreeNode,{row,col}}
    map<int, map<int, multiset<int>>> mp;      // col -> {row :  [x,y,z.....]}
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *&node = p.first;
        // x -> row , y -> col
        int &x = p.second.first, &y = p.second.second;
        mp[y][x].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {x + 1, y - 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto &p : mp)
    {
        vector<int> col;
        for (auto &q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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
    for (auto col : result)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}