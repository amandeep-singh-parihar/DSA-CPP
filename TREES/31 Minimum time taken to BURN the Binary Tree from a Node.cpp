// L31. Minimum time taken to BURN the Binary Tree from a Node
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

void mark_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_tracker, int target, TreeNode *&tgt)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->data == target)
        {
            tgt = curr;
        }
        if (curr->left)
        {
            parent_tracker[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_tracker[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

int minTime(TreeNode *root, int target)
{
    if (!root)
    {
        return 0;
    }
    int time = 0;
    unordered_map<TreeNode *, TreeNode *> parent_tracker;
    TreeNode *tgt = NULL;
    mark_parent(root, parent_tracker, target, tgt);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(tgt);
    visited[tgt] = true;
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent_tracker[node] && !visited[parent_tracker[node]])
            {
                flag = 1;
                q.push(parent_tracker[node]);
                visited[parent_tracker[node]] = true;
            }
        }
        if (flag)
        {
            ++time;
        }
    }
    return time;
}

int main()
{
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    //     / \    \
    //    7   8    9
    //              \
    //              10

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);

    int target = 8;
    cout << "Minimum time to burn the tree from target node " << target << " is: " << minTime(root, target) << endl;

    return 0;
}