// 94. Binary Tree Inorder Traversal
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

// Recursive
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Iterative
vector<int> _inorder(node *root)
{
    stack<node *> st; // we take a stack of node* type
    node *ele = root; // let the root node be ele
    vector<int> ans;  // a vector named ans
    while (true)
    {
        if (ele != NULL) // if the element is not null
        {
            st.push(ele);    // push that element in the stack
            ele = ele->left; // and move to the left
        }
        else
        {
            // if the element is null
            if (st.empty())           // check if the stack is empty it means traversal done
                break;                // break the loop
            ele = st.top();           // if the stack is not empty take the top element of the stack
            st.pop();                 // pop it from the stack
            ans.push_back(ele->data); // push the element->data in the ans which was at the top
            ele = ele->right;         // move to the right
        }
    }
    return ans;
}

// Morris Traversal
// TC O(N)
// SC O(1)
vector<int> __inorder(node *root)
{
    vector<int> inorder;
    if (!root)
        return inorder;
    node *curr = root;
    while (curr != NULL)
    {
        // If there is no left subtree, print the current node and move right
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            // If the right child of predecessor is NULL, create a temporary link
            if (prev->right == NULL)
            {
                prev->right = curr; // Threading
                curr = curr->left;  // Move to the left subtree
            }
            // If the link already exists, remove it and process the current node
            else
            {
                prev->right = NULL;            // Remove the thread
                inorder.push_back(curr->data); // Process current node
                curr = curr->right;            // Move to the right subtree
            }
        }
    }
    return inorder;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Recursive" << endl;
    inorder(root);
    cout << endl;

    cout << "Iterative" << endl;
    vector<int> ans = _inorder(root);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "Morris" << endl;
    vector<int> res = __inorder(root);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
