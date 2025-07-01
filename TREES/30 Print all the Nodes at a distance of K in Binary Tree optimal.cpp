#include <bits/stdc++.h>
using namespace std;

static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Approach
// (1) Find the root to targetnode path
// (2) Now traverse the path and just print the k-ith below nodes of that paticular node
// (3) But to prevent that no two path print twice we send a bloacker node with the function

// Dry Run
// [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// root = 3 , target = 5
// (1)-> root to targetnode path -> [3,5] reverse it -> [5,3]
// (2)-> now traverse the [5,3] and print the k-ith belowe nodes
//  for i = 0 , knodesDown(root,k-0,blocker=NULL) this is the first node so no bloacker
//  knodesDown for 5 is [7,4]
//  for i = 1 , knodesDown(root,k-1,blocker=path[i-1]) blocker = 5 (as I don't need the path we overlap 5)
// knodesDwon for 3 is [1]. Not 5 because we send 5 as blocker so any path which contain 5 not store in the res.
// ultimatily the full as is [7,4,1]

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

vector<int> v;

void knodesDown(TreeNode *root, int k, TreeNode *blocker)
{
    if (root == NULL || k < 0 || root == blocker)
        return;

    if (k == 0)
    {
        v.push_back(root->data);
        return;
    }

    knodesDown(root->left, k - 1, blocker);
    knodesDown(root->right, k - 1, blocker);
}

bool rootToNodeHelper(TreeNode *root, int target, vector<TreeNode *> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root);

    if (root->data == target)
        return true;

    if (rootToNodeHelper(root->left, target, path) || rootToNodeHelper(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}

vector<TreeNode *> rootToNode(TreeNode *root, int target)
{
    vector<TreeNode *> path;
    rootToNodeHelper(root, target, path);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<TreeNode *> path = rootToNode(root, target->data);
    for (int i = 0; i < path.size(); ++i)
    {
        TreeNode *blocker = (i == 0) ? nullptr : path[i - 1];
        knodesDown(path[i], k - i, blocker);
    }
    return v;
}
int main()
{
    // Constructing tree: [3,5,1,6,2,0,8,null,null,7,4]

    //        3
    //      /   \
    //     5     1
    //    / \   / \
    //   6   2 0   8
    //      / \
    //     7   4

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int targetVal = 5;
    int k = 2;

    TreeNode *target = new TreeNode(targetVal);

    v.clear();
    vector<int> ans = distanceK(root, target, k);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
