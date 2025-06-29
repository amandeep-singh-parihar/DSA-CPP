// 653. Two Sum IV - Input is a BST
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

// METHOD 1
// TC O(N)
// SC O(N)
void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> in;
    inorder(root, in);
    unordered_map<int, int> mp;
    for (int i = 0; i < in.size(); ++i)
    {
        int moreNeeded = k - in[i];
        if (mp.find(moreNeeded) != mp.end())
        {
            return true;
        }
        mp[in[i]] = i;
    }
    return false;
}

// METHOD 2
class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse = true;

    void pushAll(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (!reverse)
        {
            pushAll(temp->right);
        }
        else
        {
            pushAll(temp->left);
        }
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};

int main()
{

    return 0;
}