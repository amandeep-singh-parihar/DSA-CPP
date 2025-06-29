// 102. Binary Tree Level Order Traversal
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
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

vector<vector<int>> levelorder(TreeNode *root)
{
    vector<vector<int>> ans; // create the ans vec of vec for the final ans
    if (root == NULL)        // if the root is null directly return the ans
    {
        return ans;
    }
    queue<TreeNode *> q; // we take a queue
    q.push(root);        // the q initially have the root element
    while (!q.empty())   // untill the q is not empty
    {
        int size = q.size();           // take the currect size of the q
        vector<int> level;             // create a vec name level
        for (int i = 0; i < size; ++i) // loop till the size
        {
            TreeNode *element = q.front(); // take the first element of the q
            q.pop();                       // pop that element from the q
            if (element->left != NULL)     // if the element has left child
            {
                q.push(element->left); // push the left child into the q
            }
            if (element->right != NULL) // if the element has right child
            {
                q.push(element->right); // push the right child into the q
            }
            level.push_back(element->val); // push the val of the current element into the level vector
        }
        ans.push_back(level); // after all the elements at a specific level has traversed (the result of the was in the level vector, Now push the level vector into the ans(vec of vec));
    }
    return ans; // return the ans
}

// If we want the level order traversal in one line (or one vector)
vector<int> _levelorder(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        ans.push_back(node->val);
    }
    return ans;
}

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Calling level order traversal
    vector<vector<int>> result = levelorder(root);

    // Printing the result
    cout << "Level Order Traversal:\n";
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    // calling the _level order traversal
    vector<int> ans = _levelorder(root);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}