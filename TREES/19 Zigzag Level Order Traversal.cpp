// 103. Binary Tree Zigzag Level Order Traversal
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

    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

//  T.C O(N)
//  S.C O(N)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans; // create the ans vec of vec for the final ans
    if (root == NULL)        // if the root is null directly return the ans
        return ans;

    queue<TreeNode *> q; // we take a queue
    q.push(root);        // the q initially have the root element
    bool flag = true;    // true -> left to right, false -> right to left
    while (!q.empty())   // untill the q is not empty
    {
        int size = q.size();           // take the currect size of the q
        vector<int> level;             // create a vec name level
        for (int i = 0; i < size; ++i) // loop till the size
        {
            TreeNode *ele = q.front(); // take the first element of the q
            q.pop();                   // pop that element from the q

            if (ele->left != NULL) // if the element has left child
                q.push(ele->left); // push the left child into the q

            if (ele->right != NULL) // if the element has right child
                q.push(ele->right); // push the right child into the q

            level.push_back(ele->val); // push the val of the current element into the level vector
        }
        if (!flag) // if the flag is false left->right . if true right->left
        {
            reverse(level.begin(), level.end());
        }
        ans.push_back(level); // after all the elements at a specific level has traversed (the result of the was in the level vector, Now push the level vector into the ans(vec of vec));
        flag = !flag;         // invert the flag
    }
    return ans;
}

int main()
{
    // Creating the tree structure from the image
    //        3
    //       / \
    //      9   20
    //         /  \
    //       15    7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calling level order traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Printing the result
    cout << "Level Order Traversal:\n";
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}