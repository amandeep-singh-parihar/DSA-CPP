// 230. Kth Smallest Element in a BST
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

// METHOD 1 -> get the level order traversal of BST and sort the level order traversal

// TC O(N)+N(NlogN)
// SC O(N) for storing the nodes
int kthSmallest(TreeNode *root, int k)
{
    vector<int> levelOrder;
    if (!root)
        -1;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        levelOrder.push_back(node->data);
    }

    sort(levelOrder.begin(), levelOrder.end());
    return levelOrder[k - 1];
}

// METHOD 2

// Instead of doing BFS traversal do inorder traversal it -> BFS of inorder traversal will contain the nodes in sorted order
// TC O(N)
// SC O(N)
void inorder(TreeNode *root, vector<int> &ans)
{
    vector<int> ans;
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

pair<int, int> findKth(TreeNode *root, int k)
{
    vector<int> arr;
    inorder(root, arr);
    int kLargest = arr[arr.size() - k]; // K largest means (N - k)th smallest
    int kSmallest = arr[k - 1];
    return make_pair(kSmallest, kLargest);
}

// METHOD 3 -> don't maintain a extra vector just count node while visiting it

// TC O(N)
// SC O(1)
void inorder(TreeNode *root, int &counter, int k, int &kSmallest)
{
    if (!root || counter >= k)
        return;

    inorder(root->left, counter, k, kSmallest);
    counter++;
    if (counter == k)
    {
        kSmallest = root->data;
        return;
    }
    inorder(root->right, counter, k, kSmallest);
}
int kthSmallest(TreeNode *root, int k)
{
    int counter = 0;
    int kSmallest = INT_MAX;
    inorder(root, counter, k, kSmallest);
    return kSmallest;
}

// METHOD 4 -> find the kLargest and kSmallest

// TC O(N)
// SC O(1)
void reverseInorder(TreeNode *node, int &counter, int k, int &kLargest)
{
    if (!node || counter >= k)
        return;

    // Traverse right subtree
    reverseInorder(node->right, counter, k, kLargest);

    // Increment counter after
    // visiting right subtree
    counter++;

    // Check if current node
    // is the Kth largest
    if (counter == k)
    {
        kLargest = node->data;
        return;
    }

    // Traverse left subtree if
    // Kth largest is not found yet
    reverseInorder(node->left, counter, k, kLargest);
}
void inorder(TreeNode *node, int &counter, int k, int &kSmallest)
{
    if (!node || counter >= k)
        return;

    // Traverse left subtree
    inorder(node->left, counter, k, kSmallest);

    // Increment counter after visiting left subtree
    counter++;

    // Check if current node is the Kth smallest
    if (counter == k)
    {
        kSmallest = node->data;
        return;
    }

    // Traverse right subtree if
    // Kth smallest is not found yet
    inorder(node->right, counter, k, kSmallest);
}

int main()
{
}