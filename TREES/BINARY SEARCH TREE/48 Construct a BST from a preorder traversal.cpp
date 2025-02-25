// 1008. Construct Binary Search Tree from Preorder Traversal
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
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// METHOD 1
// By manually create the Tree
// Worst-case: O(N²) (if the tree is skewed).
// Best-case: O(N log N) (if the tree is balanced).
// O(N) (for storing N nodes in the tree).
// O(H) recursive stack (O(N) worst-case, O(log N) best-case).

TreeNode *_insert(TreeNode *root, int key)
{
    TreeNode *ans = new TreeNode(key);
    if (!root)
        return ans;
    TreeNode *dummy = root;
    while (dummy)
    {
        if (dummy->data > key)
        {
            if (dummy->left == NULL)
            {
                dummy->left = ans;
                return root;
            }
            dummy = dummy->left;
        }
        else
        {
            if (dummy->right == NULL)
            {
                dummy->right = ans;
                return root;
            }
            dummy = dummy->right;
        }
    }
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i)
    {
        root = _insert(root, preorder[i]);
    }
    return root;
}

// METHOD 2
// AS this is a BST and preorder is already given
// store preorder in a vector and sort the vector you got inorder of that BST
// now just create the Tree as you have both preorder and inorder (using map)
// O(N log N) + O(N) + O(N) = O(N log N)
// O(N) for extra arrays + O(H) for recursion stack → O(N) in the worst case.

TreeNode *helper(vector<int> &preorder, int preStart, int preEnd,
                 vector<int> &inorder, int inStart, int inEnd,
                 map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = helper(preorder, preStart + 1, preStart + numsLeft,
                        inorder, inStart, inRoot - 1, inMap);
    root->right = helper(preorder, preStart + numsLeft + 1, preEnd, inorder,
                         inRoot + 1, inEnd, inMap);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i)
    {
        inMap[inorder[i]] = i;
    }
    TreeNode *root = helper(preorder, 0, preorder.size() - 1, inorder, 0,
                            inorder.size() - 1, inMap);

    return root;
}

// TC O(3N) visiting a node 3 times worst
// SC O(1)
TreeNode *build(vector<int> &preorder, int &i, int upperBound)
{
    if (i == preorder.size() || preorder[i] > upperBound)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, upperBound);
    return root;
}

TreeNode *__bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

int main()
{

    return 0;
}