// 889. Construct Binary Tree from Preorder and Postorder Traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *constructFromPrePostHelper(vector<int> &preorder, int preStart,
                                     int preEnd, vector<int> &postorder,
                                     int postStart, int postEnd,
                                     map<int, int> &postMap)
{
    if (preStart > preEnd || postStart > postEnd)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    if (preStart == preEnd)
        return root;

    int leftChildVal = preorder[preStart + 1];

    int leftChildPostIdx = postMap[leftChildVal];

    int leftSubtreeSize = leftChildPostIdx - postStart + 1;

    root->left = constructFromPrePostHelper(
        preorder, preStart + 1, preStart + leftSubtreeSize, postorder,
        postStart, leftChildPostIdx, postMap);

    root->right = constructFromPrePostHelper(
        preorder, preStart + leftSubtreeSize + 1, preEnd, postorder,
        leftChildPostIdx + 1, postEnd - 1, postMap);

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder,
                               vector<int> &postorder)
{
    map<int, int> postMap;
    for (int i = 0; i < postorder.size(); ++i)
    {
        postMap[postorder[i]] = i;
    }

    TreeNode *root = constructFromPrePostHelper(
        preorder, 0, preorder.size() - 1, postorder, 0,
        postorder.size() - 1, postMap);

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode *root = constructFromPrePost(preorder, postorder);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
