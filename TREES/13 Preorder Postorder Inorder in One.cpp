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

vector<vector<int>> PreInPostTraversal(node *root)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return {};
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is the part of pre
        // increament 1 to 2
        // push the left side of the tree
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

        // this is the part of in
        // increment 2 to 3
        // push right
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
        // don't push it back again
        else
        {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
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
    // Calling the function
    vector<vector<int>> result = PreInPostTraversal(root);

    // Displaying the results
    cout << "Preorder: ";
    for (int num : result[0])
        cout << num << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int num : result[1])
        cout << num << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int num : result[2])
        cout << num << " ";
    cout << endl;
    return 0;
}