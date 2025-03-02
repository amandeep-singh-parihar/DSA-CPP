// This is not the GFG one question which check if the tree follows the children sum property or not
// in this question We have to make it to follow children sum property
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
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// TC O(N)
// SC O(H) if skew O(N)
void isSumProperty(TreeNode *root)
{
    if (root == NULL)
        return;
    int child = 0;  // create a child variable which store the sum of child nodes
    if (root->left) // if the root->left exists add the value of it in child
    {
        child += root->left->data;
    }
    if (root->right) // if the root->right exists add the value of it in right
    {
        child += root->right->data;
    }

    if (child >= root->data) // now if the sum of child is greater than root->data it means root it smaller so make the parent to child value
    {
        root->data = child;
    }
    else // if the child are smaller than root->data make the child to root->data
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    isSumProperty(root->left);  // call for the left
    isSumProperty(root->right); // call for the right

    int total = 0;  // take a variable as total = 0;
    if (root->left) // now if the root->left add it in total
        total += root->left->data;
    if (root->right) // now if the root->right add it in total
        total += root->right->data;

    if (root->left || root->right) // if any of left or right node exists make the root->data as total
    {
        root->data = total;
    }
}

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

int main()
{
    //      50
    //     /  \
    //    7    2
    //   / \  / \
    //  3   5 1  30
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    cout << "Before transformation: ";
    printTree(root);

    isSumProperty(root);

    cout << "After transformation: ";
    printTree(root);

    return 0;
}