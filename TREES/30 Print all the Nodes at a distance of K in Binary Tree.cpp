// 863. All Nodes Distance K in Binary Tree
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

// parentTraverl + traversal + hashmaps
// T.C O(N) + O(N) + O(logN)
// S.C O(N) + O(N) + O(N)
void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track) // this will mark the parent of each node in the tree
{
    queue<TreeNode *> q; // take a queue for the BFS
    q.push(root);        // push the root in the tree
    while (!q.empty())   // traverse till the q will become empty
    {
        TreeNode *node = q.front(); // take the first element from the queue
        q.pop();                    // pop that element from the queue
        if (node->left)             // if there exists a left
        {
            parent_track[node->left] = node; // map it with his parent 5->3...
            q.push(node->left);              // now push the element in the map for traversal
        }
        if (node->right) // if there exists a right
        {
            parent_track[node->right] = node; // map it with his raprent 1->3...
            q.push(node->right);              // now push the element in the map for traversal
        }
    }
    // Parent Map:
    // 5 → 3
    // 1 → 3
    // 6 → 5
    // 2 → 5
    // 0 → 1
    // 8 → 1
    // 7 → 2
    // 4 → 2
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    //             child,      parent
    unordered_map<TreeNode *, TreeNode *> parent_track; // this map will track of the parent of each node
    markParent(root, parent_track);                     // call the function and the parent_track must be passes as reference

    unordered_map<TreeNode *, bool> visited; // map to check if the node is visited for not
    queue<TreeNode *> q;                     // a queue for the traversal
    q.push(target);                          // push the target node in the queue
    visited[target] = true;                  // mark the target as visited
    int curr_level = 0;                      // take the curr_level as 0
    while (!q.empty())                       // till the queue not become empty
    {
        int size = q.size(); // take the size of the queue
        if (curr_level == k) // if the curr_level is equal to k break the loop
        {
            break;
        }
        else
        {
            ++curr_level; // else increase the curr_level
        }
        for (int i = 0; i < size; ++i) // traverse in the for loop till the size
        {
            TreeNode *currentNode = q.front();                    // take the currentNode
            q.pop();                                              // pop it from the queue
            if (currentNode->left && !visited[currentNode->left]) // if the currentNode->left not null and it is not visited
            {
                q.push(currentNode->left);         // push that node in the queue
                visited[currentNode->left] = true; // and mark it as visited
            }

            if (currentNode->right && !visited[currentNode->right])
            {
                q.push(currentNode->right);
                visited[currentNode->right] = true;
            }

            if (parent_track[currentNode] && !visited[parent_track[currentNode]]) // if the currentNode parent exists and it is not visited
            {
                q.push(parent_track[currentNode]);         // push the currentNode parent in the q
                visited[parent_track[currentNode]] = true; // and mark it as visited
            }
        }
    }
    vector<int> ans;   // a vector for storing ans
    while (!q.empty()) // till the queue is not empty
    {
        TreeNode *node = q.front(); // take the first element
        q.pop();                    // pop it from the q
        ans.push_back(node->data);  // push its data in the ans
    }
    return ans; // return the answer
}

int main()
{
    // Constructing the example tree
    //      3
    //     /  \
    //    5    1
    //   / \  / \
    //  6  2 0   8
    //    / \
    //   7   4

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *target = root->left; // Target node = 5
    int k = 2;                     // Distance

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->data << " are: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}