// Boundary Traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// T.C O(H)+O(H)+O(N) = O(N)
// S.C O(N)

bool isLeaf(node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundry(node *root, vector<int> &res)
{
    node *curr = root->left;
    while (curr != NULL)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }

        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addRightBoundry(node *root, vector<int> &res)
{
    node *curr = root->right;
    vector<int> temp;
    while (curr != NULL)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }

        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        res.push_back(temp[i]);
    }
}

void addLeaves(node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}

vector<int> traverseBoundary(node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundry(root, res);
    addLeaves(root, res);
    addRightBoundry(root, res);
    return res;
}

int main()
{
    // Creating the tree structure from the image
    //     100
    //     /   \
    //   50     150
    //  /  \    /   \
    // 25   75  140   200
    //  \   / \
    //  30 70  80
    //    \
    //    35

    node *root = new node(100);
    root->left = new node(50);
    root->right = new node(150);
    root->left->left = new node(25);
    root->left->right = new node(75);
    root->right->left = new node(140);
    root->right->right = new node(200);
    root->left->left->right = new node(30);
    root->left->right->left = new node(70);
    root->left->right->right = new node(80);
    root->left->left->right->right = new node(35);

    // Calling the boundary traversal function
    vector<int> boundary = traverseBoundary(root);

    // Printing the result
    cout << "Boundary Traversal: ";
    for (int val : boundary)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}