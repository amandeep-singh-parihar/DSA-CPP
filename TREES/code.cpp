// // #include <bits/stdc++.h>
// // using namespace std;
// // static const bool __boost = []()
// // {
// //     cin.tie(nullptr);
// //     cout.tie(nullptr);
// //     return ios_base::sync_with_stdio(false);
// // }();

// // struct node
// // {
// //     int data;
// //     node *left;
// //     node *right;

// //     node(int val)
// //     {
// //         data = val;
// //         left = right = NULL;
// //     }
// // };

// // bool isLeaf(node *root)
// // {
// //     return !root->left && !root->right;
// // }

// // void addLeftBoundry(node *root, vector<int> &res)
// // {
// //     // res.push_back(root->left);
// //     node *curr = root->left;
// //     while (curr != NULL)
// //     {
// //         if (!isLeaf(curr))
// //         {
// //             res.push_back(curr->data);
// //         }

// //         if (curr->left)
// //         {
// //             curr = curr->left;
// //         }
// //         else
// //         {
// //             curr = curr->right;
// //         }
// //     }
// // }
// // void addLeaves(node *root, vector<int> &res)
// // {
// //     if (isLeaf(root))
// //     {
// //         res.push_back(root->data);
// //         return;
// //     }

// //     if (root->left)
// //     {
// //         addLeaves(root->left, res);
// //     }
// //     if (root->right)
// //     {
// //         addLeaves(root->right, res);
// //     }
// // }
// // void addRightBoundry(node *root, vector<int> &res)
// // {
// //     vector<int> level;
// //     node *curr = root->right;
// //     while (curr != NULL)
// //     {
// //         if (!isLeaf(curr))
// //         {
// //             level.push_back(curr->data);
// //         }

// //         if (curr->right)
// //         {
// //             curr = curr->left;
// //         }
// //         else
// //         {
// //             curr = curr->left;
// //         }
// //     }

// //     for (int i = level.size() - 1; i >= 0; --i)
// //     {
// //         res.push_back(level[i]);
// //     }
// // }

// // vector<int> traverseBoundary(node *root)
// // {
// //     vector<int> res;
// //     if (root == NULL)
// //         return res;
// //     if (!isLeaf(root))
// //     {
// //         res.push_back(root->data);
// //     }
// //     addLeftBoundry(root, res);
// //     addLeaves(root, res);
// //     addRightBoundry(root, res);
// // }

// // int main()
// // {
// //     // Creating the tree structure from the image
// //     //     100
// //     //     /   \
// //     //   50     150
// //     //  /  \    /   \
// //     // 25   75  140   200
// //     //  \   / \
// //     //  30 70  80
// //     //    \
// //     //    35

// //     node *root = new node(100);
// //     root->left = new node(50);
// //     root->right = new node(150);
// //     root->left->left = new node(25);
// //     root->left->right = new node(75);
// //     root->right->left = new node(140);
// //     root->right->right = new node(200);
// //     root->left->left->right = new node(30);
// //     root->left->right->left = new node(70);
// //     root->left->right->right = new node(80);
// //     root->left->left->right->right = new node(35);

// //     // Calling the boundary traversal function
// //     vector<int> boundary = traverseBoundary(root);

// //     // Printing the result
// //     cout << "Boundary Traversal: ";
// //     for (int val : boundary)
// //     {
// //         cout << val << " ";
// //     }
// //     cout << endl;

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// struct node
// {
//     /* data */
//     int data;
//     node *left;
//     node *right;

//     node(int data)
//     {
//         // data = val;
//         this->data = data;
//         left = right = NULL;
//     }
// };

// vector<int> getTopView(node *root)
// {
//     vector<int> res;

//     queue<pair<node *, int>> q; // {node,col};
//     map<int, int> mpp;          // col->node.values

//     q.push({root, 0});
//     while (!q.empty())
//     {
//         auto p = q.front();
//         q.pop();
//         node *n = p.first;
//         int col = p.second;
//         if (mpp.find(col) == mpp.end())
//         {
//             mpp[col] = n->data;
//         }

//         if (n->left)
//         {
//             q.push({n->left, col - 1});
//         }

//         if (n->right)
//         {
//             q.push({n->right, col + 1});
//         }
//     }

//     for (auto it : mpp)
//     {
//         res.push_back(it.second);
//     }

//     return res;
// }

// int main()
// {
//     // Creating the tree structure from the image:
//     //         1
//     //       /   \
//     //      2     3
//     //     / \   / \
//     //    4   5 6   7

//     node *root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->left = new node(6);
//     root->right->right = new node(7);

//     // Calling getTopView function
//     vector<int> topView = getTopView(root);

//     // Printing the top view
//     for (int val : topView)
//     {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

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
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// custom on overlapping give the left most
vector<int> getBottomView(TreeNode *root)
{
    if (!root)
        return {};

    map<int, pair<int, int>> mpp;         // col -> {depth, value}
    queue<tuple<TreeNode *, int, int>> q; // node, col, depth

    q.push(make_tuple(root, 0, 0));

    while (!q.empty())
    {
        TreeNode *node = get<0>(q.front());
        int col = get<1>(q.front());
        int depth = get<2>(q.front());
        q.pop();

        // if col not seen or deeper level, update
        if (mpp.find(col) == mpp.end() || depth > mpp[col].first)
        {
            mpp[col] = make_pair(depth, node->data);
        }

        if (node->left)
        {
            q.push(make_tuple(node->left, col - 1, depth + 1));
        }
        if (node->right)
        {
            q.push(make_tuple(node->right, col + 1, depth + 1));
        }
    }

    vector<int> res;
    for (map<int, pair<int, int>>::iterator it = mpp.begin(); it != mpp.end(); ++it)
    {
        res.push_back(it->second.second); // get value
    }

    return res;
}

int main()
{
    // Creating the tree structure from the image:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Calling getTopView function
    vector<int> topView = getBottomView(root);

    // Printing the top view
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
