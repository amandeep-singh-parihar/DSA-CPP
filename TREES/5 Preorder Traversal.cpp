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
// Morris
vector<int> __preorder(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            node *leftChild = curr->left;
            while (leftChild->right != NULL && leftChild->right != curr)
            {
                leftChild = leftChild->right;
            }
            if (leftChild->right == NULL)
            {
                leftChild->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                leftChild->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
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
    vector<int>_ans=__preorder(root);
    for(int _i=0;_i<_ans.size();++_i)
    {
        cout<<_ans[_i]<<" ";
    }
    cout << endl;
    return 0;
}
