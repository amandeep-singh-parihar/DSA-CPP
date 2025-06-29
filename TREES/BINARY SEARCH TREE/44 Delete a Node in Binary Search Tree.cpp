// 450. Delete Node in a BST
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

int findMin(TreeNode *root)
{
    if (!root)
        return -1;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == key)
    {
        // 0 child -> if the root have no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // delete that root
            return NULL; // and return NULL
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            TreeNode *temp = root->left; // store the root's left in the temp
            delete root;                 // delete the root
            return temp;                 // return the temp as it contain the root's left
        }
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            TreeNode *temp = root->right; // store the root's right in the temp
            delete root;                  // delete the root
            return temp;                  // return the temp as it contain the root's right
        }

        // 2 child
        if (root->right && root->left)
        {
            int mini = findMin(root->right);             // now find the minimum in the right
            root->data = mini;                           // put the mini value in the root
            root->right = deleteNode(root->right, mini); // now delete the root on the right from which i take the value
            return root;                                 // return the root
        }
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key); // if the key is smaller find it in the left subtree
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, key); // if the key is greater find it in the right subtree
        return root;
    }
    return root;
}

// Utility function to insert nodes into BST
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

// Utility function to print inorder traversal of BST
void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of BST before deletion: ";
    inorder(root);
    cout << endl;

    int key = 50;
    root = deleteNode(root, key);

    cout << "Inorder traversal of BST after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}