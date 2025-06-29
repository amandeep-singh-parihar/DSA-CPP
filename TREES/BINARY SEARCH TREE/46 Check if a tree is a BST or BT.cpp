// 98. Validate Binary Search Tree
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
    struct TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
// METHOD 1

// TC O(N)
// SC O(1)
bool validateBST(TreeNode *node, long long lowerBound,
                 long long upperBound)
{
    if (node == NULL)
        return true;

    if (node->val <= lowerBound || node->val >= upperBound)
        return false;

    return validateBST(node->left, lowerBound, node->val) &&
           validateBST(node->right, node->val, upperBound);
}
bool isValidBST(TreeNode *root)
{
    return validateBST(root, LONG_MIN, LONG_MAX);
}

// METHOD 2

// The inorder of BST is always strictly incresing (having no duplicates)

// TC O(N)
// SC O(1)
void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
bool isValidBST(TreeNode *root)
{
    vector<int> arr;
    inorder(root, arr);
    return adjacent_find(arr.begin(), arr.end(), greater_equal<int>()) == arr.end();
    // return true if the array is strictly increasing
    // adjacent_find(arr.begin(), arr.end(), greater_equal<int>()) if this not find any pair where a>=b
    // then it points to the arr.end() , it means elements were stictly incresing

    // or i can do this
    // for(size_t i = 0;i<arr.size();++i)
    // {
    //     if(arr[i]>=arr[i+1]) return false;
    // }
    // return true;
}

int main()
{

    return 0;
}