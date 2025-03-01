// 145. Binary Tree Postorder Traversal
#include <bits/stdc++.h>
using namespace std;

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

// Recursive solution
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Iterative solution using 2 stacks
vector<int> _postorder(node *root)
{
    vector<int> ans; // create a vector for ans
    if (root == NULL)
    {
        return ans;
    }
    stack<node *> st1, st2; // create two stack st1 and st2
    st1.push(root);         // push the root element in the stack 1
    while (!st1.empty())    // do it till the stack 1 got exhuasted
    {
        node *ele = st1.top(); // take the top element of the stack 1
        st1.pop();             // pop the element
        st2.push(ele);         // push the element in the stack 2
        if (ele->left != NULL) // if the element have left push it in stack 1
        {
            st1.push(ele->left);
        }
        if (ele->right != NULL) // if the element have right push it in stack 1
        {
            st1.push(ele->right);
        }
    }
    while (!st2.empty()) // travers -> now stack 2 have all the traversal result
    {
        ans.push_back(st2.top()->data); // push the ans in the ans vector
        st2.pop();                      // pop the ele
    }
    return ans;
}

// Iterative solution using 1 stack (Approach 1)
vector<int> __postorder(node *root)
{
    // In this approach doing the same just inplace of taking two stacks I am taking one stack and one vec
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
        ans.push_back(ele->data);
        if (ele->left != NULL)
        {
            st.push(ele->left);
        }
        if (ele->right != NULL)
        {
            st.push(ele->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    postorder(root);
    // vector<int> ans = postorder(root);
    // for (int i = 0; i < ans.size(); ++i)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << endl;
    return 0;
}
