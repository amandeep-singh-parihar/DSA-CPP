// 100. Same Tree
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

// Using recursion
bool isSameTree(node *p, node *q)
{
    // If both nodes are NULL, they are identical (base case)
    if (p == NULL || q == NULL)
    {
        return p == q; // Returns true if both are NULL, otherwise false
    }

    // Check if the current nodes have the same value
    // Then recursively check if the left and right subtrees are identical
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Using BFS
bool _isSameTree(node *p, node *q)
{
    // If both nodes are NULL, they are identical (base case)
    if (p == NULL || q == NULL)
        return p == q; // Returns true if both are NULL, otherwise false

    queue<node *> que1;
    queue<node *> que2;

    que1.push(p); // push p in the que1
    que2.push(q); // pusht q in the que2

    while (!que1.empty() && !que2.empty()) // till the anyone of them will empty
    {
        node *node1 = que1.front(); // take the first element of the que1
        que1.pop();                 // pop it from the que1
        node *node2 = que2.front(); // take the first element of the que2
        que2.pop();                 // pop if from the que2

        if (node1->data != node2->data) // if the data of the node1 and node2 are not same return false
            return false;

        if (node1->left != NULL && node2->left != NULL) // if both the nodes do not have left as NULL
        {
            que1.push(node1->left); // push the node1 left in the queue
            que2.push(node2->left); // push the node2 left in the queue
        }
        else if (node1->left != NULL || node2->left != NULL) // if any of them will NULL
        {
            return false;
        }

        if (node1->right != NULL && node2->right != NULL) // same for the right
        {
            que1.push(node1->right);
            que2.push(node2->right);
        }
        else if (node1->right != NULL || node2->right != NULL)
        {
            return false;
        }
    }
    return true; // run only if tree are identical
}

int main()
{
    // Creating first tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);

    // Creating second tree (same as first tree)
    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    if (isSameTree(root1, root2))
    {
        cout << "The trees are identical." << endl;
    }
    else
    {
        cout << "The trees are different." << endl;
    }
    return 0;
}