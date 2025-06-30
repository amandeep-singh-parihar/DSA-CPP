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

// Print Root to Node Path in Binary Tree
// T.C O(N)
// S.C O(H)
bool getPath(TreeNode *root, vector<int> &ans, int target)
{
    if (root == NULL) // if the root is NULL just return false
        return false;

    ans.push_back(root->data); // add the curret node to the ans vector

    if (root->data == target) // if the root is the target return true
    {
        return true;
    }

    if (getPath(root->left, ans, target) || getPath(root->right, ans, target)) // if any of the left or right get the true. It means that we found the target either on the left or on the right . hence return true here also.
    {
        return true;
    }

    ans.pop_back(); // now if we don't find the target remove the element
    return false;   // return false on not finding the target
}
vector<int> solve(TreeNode *root, int target)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }-
    getPath(root, ans, target);
    return ans;
}

// Root to Leaf Paths in Binary Tree
// T.C O(N)
// S.C O(NlogN)
void helper(TreeNode *root, vector<vector<int>> &ans, vector<int> &v)
{
    if (root == NULL)
        return;

    v.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(v);
    }

    helper(root->left, ans, v);
    helper(root->right, ans, v);
    v.pop_back();
}
vector<vector<int>> Paths(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> v;
    helper(root, ans, v);
    return ans;
}

int main()
{
    // Creating the tree:
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

    int target = 5; // Change target to test different cases
    vector<int> path = solve(root, target);

    if (path.empty())
    {
        cout << "Target not found in the tree.\n";
    }
    else
    {
        cout << "Root to Node Path for " << target << ": ";
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> allPaths = Paths(root);

    cout << "All Root-to-Leaf Paths:\n";
    for (auto &path : allPaths)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}