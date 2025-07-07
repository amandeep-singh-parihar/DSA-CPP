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
    struct TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int findCeil(TreeNode *root, int key)
{
    if(!root) return NULL;
    int res = 0;

    while(root!=NULL){
        root = root->data < key ?  root->right : root->left; 
    }

    return res;
}

int main()
{

    return 0;
}