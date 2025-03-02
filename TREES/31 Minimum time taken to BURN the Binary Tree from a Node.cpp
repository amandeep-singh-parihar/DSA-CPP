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

// TC O(N) + O(N)
// TC O(N) + O(N) 
void mark_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_tracker, int target, TreeNode *&tgt)
{
    queue<TreeNode *> q; // creat the q of TreeNode*
    q.push(root);        // push it in the q
    while (!q.empty())   // till the q is not empty
    {
        TreeNode *node = q.front(); // take the first node from the q
        q.pop();
        if (node->data == target) // if the target node and currect node is same now put the value of the target node in the tgt
        {
            tgt = node;
        }
        if (node->left) // if the node -> left is not null
        {
            parent_tracker[node->left] = node; // mark the parent of node->left as node
            q.push(node->left);                // push it in the queue
        }
        if (node->right) // if the node -> right is not null
        {
            parent_tracker[node->right] = node; // mark the parent of node->right as node
            q.push(node->right);                // push it in the queue
        }
    }
}

int minTime(TreeNode *root, int target)
{
    if (!root)
    {
        return 0;
    }
    int time = 0;                                         // intially the time is 0
    unordered_map<TreeNode *, TreeNode *> parent_tracker; // to move upward
    TreeNode *tgt = NULL;                                 // take the tgt as NULL
    mark_parent(root, parent_tracker, target, tgt);       // pass the tgt and paret_tracker map by reference
    if (!tgt)
        return 0;                           // if we don't get the tgt in the tree return 0;
    unordered_map<TreeNode *, bool> burned; // create a map of TreeNode* and bool which track how many nodes get burned
    queue<TreeNode *> q;                    // create a queue of TreeNode*
    q.push(tgt);                            // push the tgt node
    burned[tgt] = true;                     // mark the tgt node as burned
    while (!q.empty())                      // till the queue is not empty
    {
        int size = q.size(); // take the size of the queue
        int flag = 0;        // mark a flag as 0 as any of node burn then it become 1
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front(); // take the front node
            q.pop();
            if (node->left && !burned[node->left]) // if there exists left and not burned(not burned already)
            {
                flag = 1;                  // mark the flag as 1 (it means lets burn it)
                q.push(node->left);        // push the node->left in the queue
                burned[node->left] = true; // mark it as burned
            }
            if (node->right && !burned[node->right]) // if there exists right and not burned
            {
                flag = 1;                   // mark the flag as 1
                q.push(node->right);        // push it in the q
                burned[node->right] = true; // mark it as burned
            }
            if (parent_tracker[node] && !burned[parent_tracker[node]]) // move upward if there exists parent of node and it is not burned
            {
                flag = 1;                            // mark the flag as 1
                q.push(parent_tracker[node]);        // push the parent of node in the map
                burned[parent_tracker[node]] = true; // mark the node's parent as burned
            }
        }
        if (flag) // if any one of the node burned then is 1
        {
            ++time; // increase the time by 1
        }
    }
    return time; // return the time
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