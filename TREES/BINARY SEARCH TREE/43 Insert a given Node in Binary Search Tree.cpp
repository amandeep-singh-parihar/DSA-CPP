// 701. Insert into a Binary Search Tree
#include <bits/stdc++.h>
using namespace std;
// r1
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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *ans = new TreeNode(val); // make the TreeNode with the val
    if (!root)                         // if the root is null return the val node
        return ans;
    TreeNode *dummy = root; // take a dummy node points to root
    while (dummy)           // while the dummy is not null
    {
        if (dummy->data > val) // if the the dummy->data > val it means the val small value go to left
        {
            if (dummy->left == NULL) // if the left is null
            {
                dummy->left = ans; // points the dummy->left to ans
                return root;       // return the root
            }
            dummy = dummy->left; // move the dummy to dummy -> left
        }
        else
        {                             // if the value is greater than dummy
            if (dummy->right == NULL) // if the dummy->right is NULL
            {
                dummy->right = ans; // points the dummy->right to ans
                return root;        // return the ans
            }
            dummy = dummy->right; // move the dummy to dummy -> right
        }
    }
    return root; // return root
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
    TreeNode *root = NULL;

    // Insert values into BST
    vector<int> values = {10, 5, 15, 3, 7, 12, 18};
    for (int val : values)
    {
        root = insertIntoBST(root, val);
    }

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}