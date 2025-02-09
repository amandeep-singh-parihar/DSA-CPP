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

// Recursive
// void inorder(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// Iterative
vector<int> inorder(node *root)
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
            // if the element if null
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

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // inorder(root); // Inorder
    vector<int> ans = inorder(root);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
