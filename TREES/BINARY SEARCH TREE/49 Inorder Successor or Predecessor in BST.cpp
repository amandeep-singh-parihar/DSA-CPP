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
// TC O(N) + O(N) = O(N)
// SC O(N) (for in vector) + O(H) (for recursion) = O(N) in worst case
void inorder(TreeNode *root, vector<TreeNode *> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}
TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    vector<TreeNode *> in;
    inorder(root, in);
    for (int i = 0; i < in.size(); ++i)
    {
        if (in[i] == p)
        {
            if (i + 1 < in.size())
                return in[i + 1];
            return NULL;
        }
    }
    return NULL;
}

// METHOD 2
// TC O(N)
// SC O(1)
TreeNode *_inorder(TreeNode *root, TreeNode *p, TreeNode *&successor)
{
    if (!root)
        return NULL;

    _inorder(root->left, p, successor);

    if (root->data > p->data && !successor) // this is used to stop the recursion as if found then !found gives you NULL so it automatically stops the recursion
    {
        successor = root;
        return successor; // Stop once the successor is found
    }

    _inorder(root->right, p, successor);
    return successor;
}
TreeNode *_inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;
    return _inorder(root, p, successor);
}

// METHOD 3
TreeNode *__inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;
    while (root)
    {
        if (p->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

// TC O(H)
// SC O(1)
TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p)
{
    TreeNode *predecessor = NULL;
    while (root)
    {
        if (p->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}

// Function to insert into a BST
TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Main function
int main()
{

    //      20
    //     /  \
    //   10    30
    //  /  \   /  \
    // 5   15 25  35

    TreeNode *root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    TreeNode *p = root->left; // Node with value 10
    // TreeNode *p = root->right->right; // Node with value 35

    TreeNode *successor = _inorderSuccessor(root, p);

    if (successor)
        cout << "Inorder Successor of " << p->data << " is: " << successor->data << endl;
    else
        cout << "No Inorder Successor found for " << p->data << endl;

    return 0;
}