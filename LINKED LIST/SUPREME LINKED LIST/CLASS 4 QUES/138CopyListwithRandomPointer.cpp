// 138. Copy List with Random Pointer
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *helper(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *newHead = new Node(head->val);
    mp[head]=newHead;
    newHead->next = helper(head->next, mp);
    if (head->random)
    {
        newHead->random = mp[head->random];
    }
    return newHead;
}


Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    return helper(head, mp);
}

int main()
{
    // Create a linked list with random pointers
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;

    // Set up random pointers
    head->random = third;   // 1 -> 3
    second->random = head;  // 2 -> 1
    third->random = second; // 3 -> 2

    // Call the function to copy the list
    Node *copiedList = copyRandomList(head);

    // Print the original and copied lists to verify
    cout << "Original list:" << endl;
    Node *temp = head;
    while (temp)
    {
        cout << "Node value: " << temp->val;
        if (temp->random)
        {
            cout << ", Random points to: " << temp->random->val << endl;
        }
        else
        {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    cout << "\nCopied list:" << endl;
    temp = copiedList;
    while (temp)
    {
        cout << "Node value: " << temp->val;
        if (temp->random)
        {
            cout << ", Random points to: " << temp->random->val << endl;
        }
        else
        {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    return 0;
}
