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

// Morris
vector<int> __inorder(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    node *curr = root;   // take the root as current
    while (curr != NULL) // till the current root not null
    {
        if (curr->left == NULL) // if the current root is null it means this is the left most root print it
        {
            ans.push_back(curr->data); // push it in the vector
            curr = curr->right;        // now go the right of the current node
        }
        else // if the current->left is not null
        {
            node *leftChild = curr->left;    // the leftChild of the current
            while (leftChild->right != NULL) // go to the most right of the left child
            {
                leftChild = leftChild->right;
            }

            leftChild->right = curr; // connect the most right node of leftChild to the current
            node *temp = curr;       // get a temp as curr
            curr = curr->left;       // go move the curr to the left
            temp->left = NULL;       // now mark the left root as null as we don't go on it again
        }
    }
    return ans; // return the ans;
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
