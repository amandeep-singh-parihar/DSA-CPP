// 173. Binary Search Tree Iterator
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> st;

    void pushAll(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root) { pushAll(root); }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
};

class BSTIterator_before
{
private:
    stack<TreeNode *> st;

    void pushAll(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->right; // push all the right
        }
    }

public:
    BSTIterator_before(TreeNode *root) { pushAll(root); }

    int prev()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->left);
        return temp->val;
    }

    bool hasprev() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */