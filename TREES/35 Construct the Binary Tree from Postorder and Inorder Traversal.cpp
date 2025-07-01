// 106. Construct Binary Tree from Inorder and Postorder Traversal
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
// TC O(N)
// SC O(N)
TreeNode *buildTreeHelper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{
    if (postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);

    root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i)
    {
        inMap[inorder[i]] = i;
    }

    TreeNode *root = buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> postorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build Tree
    TreeNode *root = buildTree(postorder, inorder);

    // Output Inorder Traversal (Should match the input inorder sequence)
    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}