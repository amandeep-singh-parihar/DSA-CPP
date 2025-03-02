// 297. Serialize and Deserialize Binary Tree
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
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
string serialize(TreeNode *root)
{
    string s = "";
    if (!root)
        return s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
            s.append("#,");
        else
            s.append(to_string(node->val) + ',');

        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            TreeNode *leftnode = new TreeNode(stoi(str));
            node->left = leftnode;
            q.push(leftnode);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            TreeNode *rightnode = new TreeNode(stoi(str));
            node->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}

string _serialize(TreeNode *root)
{
    string s = "";
    if (!root)
        return "";
    queue<TreeNode *> q;
    q.push(root);
    s.append(to_string(root->val) + ",");
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
            s.append(to_string(node->left->val) + ',');
        }
        else
        {
            s.append("#,");
        }
        if (node->right)
        {
            q.push(node->right);
            s.append(to_string(node->right->val) + ',');
        }
        else
        {
            s.append("#,");
        }
    }
    return s;
}

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Serializing the tree
    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserializing the tree
    TreeNode *deserializedRoot = deserialize(serializedTree);

    // Serializing again to check if it remains the same
    string checkSerialization = serialize(deserializedRoot);
    cout << "Re-Serialized Tree After Deserialization: " << checkSerialization << endl;
    return 0;
}
