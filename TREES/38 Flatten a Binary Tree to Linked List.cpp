// 114. Flatten Binary Tree to Linked List
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

// TC O(N)
// SC O(N)
void flatten(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    TreeNode *dummy = NULL; // create a dummy node
    stack<TreeNode *> st;   // a stack of TreeNode
    st.push(root);          // push the root
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (dummy != NULL) // if the dummy is not null
        {
            dummy->right = node; // connect the dummy's right to the node
            dummy->left = NULL;  // connect the dummy's left to the NULL
        }
        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
        dummy = node; // move the dummy forward
    }
}

// Morris Traversal
// TC O(N)
// SC O(1)
void _flatten(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode *leftChild = curr->left;
            while (leftChild->right != NULL)
            {
                leftChild = leftChild->right;
            }
            leftChild->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printFlattenedTree(TreeNode *root)
{
    while (root)
    {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

// Main function to test flatten()
int main()
{
    // Creating the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << "Flattening the binary tree..." << endl;
    flatten(root);

    cout << "Flattened tree in linked list format:" << endl;
    printFlattenedTree(root);

    return 0;
}