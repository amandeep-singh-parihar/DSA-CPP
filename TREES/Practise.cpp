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
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// using recursion
// preorder1
void preorder1(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder1(root->left);
    preorder1(root->right);
}

void postorder1(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder1(root->left);
    postorder1(root->right);
    cout << root->data << " ";
}

void inorderR(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderR(root->left);
    cout << root->data << " ";
    inorderR(root->right);
}

vector<int> preorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *ele = st.top();
        st.pop();

        if (ele->right != NULL)
        {
            st.push(ele->right);
        }
        if (ele->left != NULL)
        {
            st.push(ele->left);
        }
        ans.push_back(ele->data);
    }
}

vector<int> inorder(node *root)
{
    stack<node *> st;
    node *ele = root;
    vector<int> ans;
    if (root == NULL)
        return ans;

    while (true)
    {
        if (ele != NULL)
        {
            st.push(ele);
            ele = ele->left;
        }
        else
        {
            if (st.empty())
                break;

            ele = st.top();
            st.pop();
            ans.push_back(ele->data);
            ele = ele->right;
        }
    }
    return ans;
}

vector<int> postorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st1;
    st1.push(root);
    while (!st1.empty())
    {
        node *ele = st1.top();
        st1.pop();
        ans.push_back(ele->data);
        if (ele->left != NULL)
        {
            st1.push(ele->left);
        }
        if (ele->right != NULL)
        {
            st1.push(ele->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> PreInPostTraversal(node *root)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
    {
        return {};
    }
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}

bool isLeaf(node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundry(node *root, vector<int> &res)
{
    node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
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
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
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
        return ;
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
    // Creating the tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // vector<int> ans = preorder1(root);
    // vector<int> ans = inorder(root);
    // vector<int> ans = postorder(root);
    // for (int i = 0; i < ans.size(); ++i)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return 0;
}