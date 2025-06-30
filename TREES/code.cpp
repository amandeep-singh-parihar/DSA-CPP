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

vector<vector<int>> Paths(TreeNode *root)
{
    
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