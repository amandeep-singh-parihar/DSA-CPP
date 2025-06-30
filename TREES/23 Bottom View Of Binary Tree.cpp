// Bottom View Of Binary Tree
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

vector<int> getBottomView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<pair<TreeNode *, int>> q; // {node,col}
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int col = it.second;
        mp[col] = node->data; /* as in this we have to take the most right node if overlap so by using
        this we can over write it as this is level order traversal from left to right*/
        if (node->left)
        {
            q.push({node->left, col - 1});
        }
        if (node->right)
        {
            q.push({node->right, col + 1});
        }
    }
    for (auto &it : mp)
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
    vector<int> topView = getBottomView(root);

    // Printing the top view
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}