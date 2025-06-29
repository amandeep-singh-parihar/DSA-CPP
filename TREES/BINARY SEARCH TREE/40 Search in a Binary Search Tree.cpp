// 700. Search in a Binary Search Tree
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
    struct TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->data != val)
    {
        root = root->data > val ? root->left : root->right;
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    int searchVal;
    cout << "Enter value to search: ";
    cin >> searchVal;

    TreeNode *result = searchBST(root, searchVal);

    if (result)
        cout << "Found: " << result->data << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}