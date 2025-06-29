// 144. Binary Tree Preorder Traversal
#include <bits/stdc++.h>
using namespace std;

// Revision 2

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

// Recursive Solution
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Iterative Solution
vector<int> _preorder(node *root)
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
        node *element = st.top();
        st.pop();
        ans.push_back(element->data);
        if (element->right != NULL) // as this is stack so we put the right first as it retrive last
        {
            st.push(element->right);
        }
        if (element->left != NULL) // as this is stack so we put the left last as it retrive first
        {
            st.push(element->left);
        }
    }
    return ans;
}
// Morris Traversal
// TC O(N)
// SC O(1)
vector<int> __preorder(node *root)
{
    vector<int> preorder;
    if (!root)
        return preorder;
    node *curr = root;
    while (curr != NULL)
    {
        // If no left child, print the current node and move right
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            // If the right child of predecessor is NULL, create a temporary link
            if (prev->right == NULL)
            {
                prev->right = curr;             // Threading
                preorder.push_back(curr->data); // Process current node
                curr = curr->left;              // Move to the left subtree
            }
            // If the link already exists, remove it and move right
            else
            {
                prev->right = NULL; // Remove the thread
                curr = curr->right; // Move to the right subtree
            }
        }
    }
    return preorder;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    cout << "Recursive" << endl;
    preorder(root);
    cout << endl;

    cout << "Iterative" << endl;
    vector<int> ans = _preorder(root);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "Morris" << endl;
    vector<int> _ans = __preorder(root);
    for (int _i = 0; _i < _ans.size(); ++_i)
    {
        cout << _ans[_i] << " ";
    }
    cout << endl;
    return 0;
}
