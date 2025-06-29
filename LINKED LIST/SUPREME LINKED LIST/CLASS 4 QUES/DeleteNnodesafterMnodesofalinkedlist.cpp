// Delete N nodes after M nodes of a linked list
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void solve(Node *head, int n, int m)
{
    if (!head)
        return;
    Node *it = head;
    for (int i = 0; i < m - 1; ++i)
    {
        if (!it)
            return;
        it = it->next;
    }
    if (!it)
        return;
    Node *mthNode = it;
    it = mthNode->next;
    for (int i = 0; i < n; ++i)
    {
        if (!it)
            break;
        Node *temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;
    linkdelete(it, n, m);
}
Node *linkdelete(Node *head, int n, int m)
{
    solve(head, n, m);
    return head;
}

int main()
{

    return 0;
}